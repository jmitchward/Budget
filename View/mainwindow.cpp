#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initDB();
//    initDefaultDB();

    model = new sqlTableModel(budgetDB);
    ui->budgetView->setModel(model);
    ui->budgetView->setColumnHidden(0, true);
    ui->budgetView->resizeColumnsToContents();
    model->select();    

    statsTab = new viewStats();
    ui->mainPanelWidget->addWidget(statsTab);
    statsTab->setDatabase(budgetDB);

    incomeBox = new addIncomeBox(this);

    initMenu();
    ui->mainPanelWidget->setCurrentWidget(ui->budgetViewWidget);
}

void MainWindow::initMenu() {
    connect(ui->viewStats, &QAbstractButton::clicked, this, [=] { ui->mainPanelWidget->setCurrentWidget(statsTab);});
    connect(ui->viewExpenses, &QAbstractButton::clicked, this, [=] { ui->mainPanelWidget->setCurrentWidget(ui->budgetViewWidget);});
    connect(ui->addIncome, &QAbstractButton::clicked, this, [=] { incomeBox->show();});
}

void MainWindow::initDB() {

    budgetDB = QSqlDatabase::addDatabase("QSQLITE");
    budgetDB.setDatabaseName("budget.db");
    budgetDB.setHostName("mitchell");
    budgetDB.setPassword("password");
    bool ok = budgetDB.open();
    if (ok) {std::cout << "initDB succeeded." << std::endl;}
    else {std::cout << "initDB failed." << std::endl;}

    QSqlQuery query;
    if(query.exec("create table if not exists transactions("
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

    if (query.exec("PRAGMA journal_mode=WAL")) { std::cout << "WAL mode successful." << std::endl; }
}

void MainWindow::initDefaultDB() {
        inputFile = new QFile(":/Resources/july_transactions.csv");
        if (inputFile->open(QIODevice::ReadOnly))
        {
            readFile database(inputFile);
            writeTable table(database.readCSV());
        }
        else { std::cout << "File not open." << std::endl; }
        inputFile->close();
        inputFile = new QFile(":/Resources/august_transactions.csv");
        if (inputFile->open(QIODevice::ReadOnly))
        {
            readFile database(inputFile);
            writeTable table(database.readCSV());
        }
        else { std::cout << "File not open." << std::endl; }
        inputFile->close();
        inputFile = new QFile(":/Resources/september_transactions.csv");
        if (inputFile->open(QIODevice::ReadOnly))
        {
            readFile database(inputFile);
            writeTable table(database.readCSV());
        }
        else { std::cout << "File not open." << std::endl; }
        inputFile->close();
        inputFile = new QFile(":/Resources/october_transactions.csv");
        if (inputFile->open(QIODevice::ReadOnly))
        {
            readFile database(inputFile);
            writeTable table(database.readCSV());
        }
        else { std::cout << "File not open." << std::endl; }
        inputFile->close();
        inputFile = new QFile(":/Resources/november_transactions.csv");
        if (inputFile->open(QIODevice::ReadOnly))
        {
            readFile database(inputFile);
            writeTable table(database.readCSV());
        }
        else { std::cout << "File not open." << std::endl; }
        inputFile->close();
}

MainWindow::~MainWindow()
{
    delete ui;
}




