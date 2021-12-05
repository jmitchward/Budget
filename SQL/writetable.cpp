#include "writetable.h"
#include <QDebug>

writeTable::writeTable(QList<QList<QString>> newData) :
    data(newData)
{
    writeData();
}


void writeTable::writeData()
{
    for (QList<QList<QString>>::const_iterator dataIterator = data.cbegin(); dataIterator < data.cend(); dataIterator++)
    {
//            std::cout << "Query captured: " << dataIterator->size() << std::endl;
//            std::cout << "Date: " << dataIterator->at(0).toStdString() << " | "
//                      << "Amount: " << dataIterator->at(1).toStdString() << " | "
//                      << "Description: " << dataIterator->at(2).toStdString() << " | "
//                      << "Category: " << dataIterator->at(3).toStdString() << " | "
//                      << "Shared: " << dataIterator->at(4).toStdString() << " | "
//                      << "Member: " << dataIterator->at(5).toStdString() << " | "
//                      << std::endl;

//            (dataIterator->at(0)=="") ? (std::cout << "0 Blank" << std::endl) : (std::cout << "Not Blank" << std::endl);
//            (dataIterator->at(1)=="") ? (std::cout << "1 Blank" << std::endl) : (std::cout << "Not Blank" << std::endl);
//            (dataIterator->at(2)=="") ? (std::cout << "2 Blank" << std::endl) : (std::cout << "Not Blank" << std::endl);
//            (dataIterator->at(3)=="") ? (std::cout << "3 Blank" << std::endl) : (std::cout << "Not Blank" << std::endl);
//            (dataIterator->at(4)=="") ? (std::cout << "4 Blank" << std::endl) : (std::cout << "Not Blank" << std::endl);
//            (dataIterator->at(5)=="") ? (std::cout << "5 Blank" << std::endl) : (std::cout << "Not Blank" << std::endl);

            if(dataIterator->at(0).toLower().contains("date")) { std::cout << "Index line skipped." << std::endl;
                                                                continue; }
            QSqlQuery query;
            query.prepare(QString("INSERT INTO transactions(date, amount, store, description, category, shared, member) "
                          " VALUES (:date, :amount, :description, :store, :category, :shared, :member)"));
            query.bindValue(":date", dataIterator->at(0));

            query.bindValue(":amount", dataIterator->at(1));
            query.bindValue(":store" , "Null");
            query.bindValue(":description", dataIterator->at(2));
            query.bindValue(":category", dataIterator->at(3));
            query.bindValue(":shared", dataIterator->at(4));
            query.bindValue(":member", dataIterator->at(5));
            // QVariantList boundV = query.boundValues();
//            for (int i = 0; i < boundV.size(); i++) {
//                std::cout << "i : " << i << " " << boundV.at(i).toString().toStdString() << std::endl;
//            }

            if (!query.exec()) {
                std::cout << "Query not successful." << std::endl;
                std::cout << query.lastError().text().toStdString() << std::endl;
            }
    }
}
