#include "writetable.h"

writeTable::writeTable(QList<QList<QString>> newData) :
    data(newData)
{
    currentDir.setCurrent("C:/Development/Budget/Budget/Resources");
    budgetDB.setDatabaseName("budget.db");
    bool ok = budgetDB.open();

    if (ok) {std::cout << "Databse open." << std::endl;}
    else {std::cout << "Databse not open." << std::endl;}

    writeData();
    budgetDB.close();
}


void writeTable::writeData()
{
    std::cout << "Reached writeData." << std::endl;
    for (QList<QList<QString>>::const_iterator dataIterator = data.cbegin(); dataIterator < data.cend(); dataIterator++)
    {
//            std::cout << "Query captured: " << dataIterator->size() << std::endl;
            QSqlQuery query;
            query.prepare("INSERT INTO transactions(date, amount, description, shared, member) "
                          " VALUES (:date, :amount, :description, :shared, :member)");
            query.bindValue(":date", dataIterator->at(0));
            query.bindValue(":amount", dataIterator->at(1));
            query.bindValue(":description", dataIterator->at(2));
            query.bindValue(":shared", dataIterator->at(3));
            query.bindValue(":member", dataIterator->at(4));
            if (query.exec()) {
                std::cout << "Query successful." << std::endl;
            }
            else {std::cout << query.lastError().text().toStdString() << std::endl;}
    }
}
