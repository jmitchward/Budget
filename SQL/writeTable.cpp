#include "writeTable.h"
#include <QDebug>

writeTable::writeTable(QList<QList<QString>> newData) : data(newData) {
    writeData();
}


void writeTable::writeData() {

    for (QList<QList<QString>>::const_iterator dataIterator = data.cbegin(); dataIterator < data.cend(); dataIterator++) {

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

            if (!query.exec()) {
                std::cout << "Query not successful." << std::endl;
                std::cout << query.lastError().text().toStdString() << std::endl;
            }
    }
}

int writeTable::writeModel(SqlTableModel &model, int rowCount) {

    for (QList<QList<QString>>::const_iterator dataIterator = data.cbegin(); dataIterator < data.cend(); dataIterator++) {

        QList<QString> rowData;

        if(dataIterator->at(0).toLower().contains("date")) { std::cout << "Index line skipped." << std::endl;
                                                            continue; }

        rowData.append(dataIterator->at(0));
        rowData.append(dataIterator->at(1));
        rowData.append(QString("NULL"));
        rowData.append(dataIterator->at(2));
        rowData.append(dataIterator->at(3));
        rowData.append(dataIterator->at(4));
        rowData.append(dataIterator->at(5));
        model.populateModel(rowCount, rowData);
        rowCount++;
    }

    return rowCount;
}
