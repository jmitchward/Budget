#include "WriteTable.h"
#include <QDebug>

WriteTable::WriteTable() {
}


void WriteTable::writeExpense(QList<QList<QString>> data) {

    for (QList<QList<QString>>::const_iterator dataIterator = data.cbegin(); dataIterator < data.cend(); dataIterator++) {
        if ( dataIterator->size() == 0 ) {
            continue;
        }
        else {

            if ( dataIterator->at(0).toLower().contains("date")) { continue; }
            if ( ( dataIterator->at(1).toDouble() < 0 ) ) { continue ;}

            QSqlQuery query;
            query.prepare(QString("INSERT INTO transactions(date, amount, store, description, category, shared, member) "
                          " VALUES (:date, :amount, :description, :store, :category, :shared, :member)"));
            query.bindValue(":date", dataIterator->at(0));
            query.bindValue(":amount", QString::number(dataIterator->at(1).toDouble(), 'f', 4 ) );
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
}

void WriteTable::writeExpense(QList<QString> data) {

    QSqlQuery query;
    query.prepare(QString("INSERT INTO transactions(date, amount, store, description, category, shared, member) "
                  " VALUES (:date, :amount, :description, :store, :category, :shared, :member)"));
    query.bindValue(":date",        data.at(0));
    query.bindValue(":amount",      QString::number( data.at(1).toDouble(), 'f', 4 ) );
    query.bindValue(":store" ,      data.at(2));
    query.bindValue(":description", data.at(3));
    query.bindValue(":category",    data.at(4));
    query.bindValue(":shared",      data.at(5));
    query.bindValue(":member",      data.at(6));

    if (!query.exec()) {
        std::cout << "Query not successful." << std::endl;
        std::cout << query.lastError().text().toStdString() << std::endl;
    }
}

void WriteTable::writeIncome(QList<QList<QString>> data) {

    for (QList<QList<QString>>::const_iterator dataIterator = data.cbegin(); dataIterator < data.cend(); dataIterator++) {

            if(dataIterator->at(0).toLower().contains("date")) { std::cout << "Index line skipped." << std::endl;
                                                                continue; }
            QSqlQuery query;
            query.prepare(QString("INSERT INTO transactions(date, amount, store, description, category, shared, member) "
                          " VALUES (:date, :amount, :type, :description, :category, :shared, :member)"));
            query.bindValue(":date",        dataIterator->at(0));
            query.bindValue(":amount",      dataIterator->at(1));
            query.bindValue(":type" ,       dataIterator->at(2));
            query.bindValue(":description", dataIterator->at(2));
            query.bindValue(":category",    dataIterator->at(3));
            query.bindValue(":member",      dataIterator->at(5));

            if (!query.exec()) {
                std::cout << "Query not successful." << std::endl;
                std::cout << query.lastError().text().toStdString() << std::endl;
            }
    }
}

void WriteTable::writeIncome(QList<QString> data) {

    QSqlQuery query;
    query.prepare(QString("INSERT INTO earnings(date, amount, type, description, category, member) "
                  " VALUES (:date, :amount, :type, :description, :category, :member)"));
    query.bindValue(":date",        data.at(0));
    query.bindValue(":amount",      data.at(1));
    query.bindValue(":type" ,       data.at(2));
    query.bindValue(":description", data.at(3));
    query.bindValue(":category",    data.at(4));
    query.bindValue(":member",      data.at(6));

    if (!query.exec()) {
        std::cout << "Query not successful." << std::endl;
        std::cout << query.lastError().text().toStdString() << std::endl;
    }
}

int WriteTable::writeExpenseModel(SqlTableModel &model, int rowCount) {

    for (QList<QList<QString>>::const_iterator dataIterator = data.cbegin(); dataIterator < data.cend(); dataIterator++) {

        QList<QString> rowData;

        if(dataIterator->at(0).toLower().contains("date")) { std::cout << "Index line skipped." << std::endl;
                                                            continue; }

        // Date
        rowData.append(dataIterator->at(0));
        // Amount
        rowData.append(QString::number( dataIterator->at(1).toDouble(), 'f', 4) );
        // Store
        rowData.append(QString("NULL"));
        // Description
        rowData.append(dataIterator->at(2));
        // Category
        rowData.append(dataIterator->at(3));
        // Shared
        rowData.append(dataIterator->at(4));
        // Member
        rowData.append(dataIterator->at(5));

        model.populateExpenseModel(rowCount, rowData);
        rowCount++;
    }

    return rowCount;
}
