#include "DataController.h"

DataController::DataController(QWidget *parent) {
    Q_UNUSED(parent);
    initDatabase();
    model = new SqlTableModel(database);
    initDefaultDatabase();
    collectData();

}

void DataController::collectData() {
    transactions = tableReader.getAllData();
    foreach( auto transaction, transactions) {
        if (!categories.checkCategory(transaction.getCtg())) {
            categories.addCategory(transaction.getCtg());
        }
        if (!members.checkMember(transaction.getMbr())) {
            members.addMember(transaction.getMbr());
        }
        if (!stores.checkStore(transaction.getStore())) {
            stores.addStore(transaction.getStore());
        }
    }
}

void DataController::initDatabase() {

    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("budget.db");
    database.setHostName("mitchell");
    database.setPassword("password");
    bool ok = database.open();
    if (ok) {std::cout << "initDB succeeded." << std::endl;}
    else {std::cout << "initDB failed." << std::endl;}

    QSqlQuery query;
    if (query.exec("create table if not exists transactions("
            "primary_key INTEGER PRIMARY KEY,"
            "date TEXT, "
            "amount INTEGER NOT NULL, "
            "store TEXT, "
            "description TEXT, "
            "category TEXT NOT NULL, "
            "shared INTEGER NOT NULL, "
            "member TEXT NOT NULL)"))
        { std::cout << "Query successful." << std::endl; }
    else
        { std::cout << query.lastError().text().toStdString() << std::endl; }

    if (query.exec("create table if not exists earnings("
            "primary_key INTEGER PRIMARY KEY,"
            "date TEXT, "
            "amount INTEGER NOT NULL, "
            "type TEXT, "
            "description TEXT, "
            "category TEXT NOT NULL, "
            "member TEXT NOT NULL)"))
        { std::cout << "Query successful." << std::endl; }
    else
        { std::cout << query.lastError().text().toStdString() << std::endl; }

    if (query.exec("PRAGMA journal_mode=WAL")) { std::cout << "WAL mode successful." << std::endl; }
}

void DataController::initDefaultDatabase() {

   auto readInFile = [ = ] (QFile* file) {
       if (file->open(QIODevice::ReadOnly))
       {
           fileReader.setFile(file);
           tableWriter.writeExpense(fileReader.readCSV());
           expenseRow = tableWriter.writeExpenseModel(*model, expenseRow);
       }
       else { std::cout << "File not open." << std::endl; }
       file->close();
   };

    inputFile = new QFile(":/Resources/july_transactions.csv");
    readInFile(inputFile);
    delete inputFile;

    inputFile = new QFile(":/Resources/august_transactions.csv");
    readInFile(inputFile);
    delete inputFile;

    inputFile = new QFile(":/Resources/september_transactions.csv");
    readInFile(inputFile);
    delete inputFile;

    inputFile = new QFile(":/Resources/october_transactions.csv");
    readInFile(inputFile);
    delete inputFile;

    inputFile = new QFile(":/Resources/november_transactions.csv");
    readInFile(inputFile);
    delete inputFile;
}

void DataController::addNewExpense(QList<QString> expense) {
    tableWriter.writeExpense(expense);
}

void DataController::addNewIncome(QList<QString> income) {
    tableWriter.writeIncome(income);
}

void DataController::newExpenseError() {

}

void DataController::newIncomeError() {

}
