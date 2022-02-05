#include "readtable.h"

readTable::readTable()
{

}

QList<Transaction> readTable::getAllData() {
    QString selectQuery("SELECT * FROM transactions ");
    return executeQuery(selectQuery);
}

QList<Transaction> readTable::getData(QString column, QString value, strictType strict, QSqlDatabase database) {
    QString queryStr;

    if (!database.open()) {
        std::cout << "Error. Database not open." << std::endl;
    }

    queryStr = selectPrep();

    switch (strict) {
        case EQUAL:
            queryStr += strPrep(column, value);
            break;
        case LIKE:
            queryStr += strLkPrep(column, value);
    }
    return executeQuery(queryStr);
}

QList<Transaction> readTable::getData(QString selectColumn, QString whereColumn, QString value, strictType strict, QSqlDatabase database) {
    QString queryStr;

    if (!database.open()) {
        std::cout << "Error. Database not open." << std::endl;
    }

    queryStr = selectPrep(selectColumn);

    switch (strict) {
        case EQUAL:
            queryStr += strPrep(whereColumn, value);
            break;
        case LIKE:
            queryStr += strLkPrep(whereColumn, value);
    }
    return executeQuery(queryStr);
}

QList<QString> readTable::getColumn(QString column) {
    QList<QString> readColumn;
    QSqlQuery query;
    query.prepare(selectDistinctPrep(column));
    if (query.exec()) { std::cout << "Success." << std::endl; }
    else { std::cout << "Error. Query failed." << std::endl
                     << query.lastError().text().toStdString() << std::endl;}
    while(query.next()) {
        std::cout << "Appending " << query.value(0).toString().toStdString() << std::endl;
        readColumn.append(query.value(0).toString());
    }
    return readColumn;
}

QList<Transaction> readTable::executeQuery(QString setQuery) {
    QSqlQuery query;
    QList<Transaction> readTransactions;

    query.prepare(setQuery);

    if (query.exec()) { std::cout << "Success." << std::endl; }
    else { std::cout << "Error. Query failed." << std::endl
                     << query.lastError().text().toStdString() << std::endl;}

    while (query.next()) {
        Transaction transaction;
        // Create a transaction based on the current line
        // Date
        transaction.setDate(query.value(1).toString());
        // Amount
        transaction.setAmount(query.value(2).toDouble());
        // Description
        transaction.setDescription(query.value(3).toString());
        // Store
        transaction.setStore(query.value(4).toString());
        // Category
        Category cat;
        cat.setTitle(query.value(5).toString());
        transaction.setCategory(cat);
        // Shared
        transaction.setShared(query.value(6).toBool());
        // Member
        Member mem;
        mem.setFirstName(query.value(7).toString());
        transaction.setMember(mem);
        // Add transaction to the list
        readTransactions.append(transaction);
    }
    return readTransactions;
}

QString readTable::executeValueQuery(QString setQuery) {
    QSqlQuery query;
    query.prepare(setQuery);
    if (query.exec()) { std::cout << "Success." << std::endl; }
    else { std::cout << "Error. Query failed." << std::endl
                     << query.lastError().text().toStdString() << std::endl;}
    return query.value(0).toString();
}


QString readTable::getDates(QString column, int value, selectType select, QSqlDatabase database) {
    QString queryStr;

    if (!database.open()) {
        std::cout << "Error. Database not open." << std::endl;
    }
    switch (select) {
        case COUNT:
            queryStr = countPrep(column);
            break;
        case SUM:
            queryStr = sumPrep();
            break;
//        default:
//            queryStr = selectPrep();
//            break;
    }
    queryStr += datePrep(value);
    return executeValueQuery(queryStr);
}

QString readTable::getAmounts(QString column, QString value, selectType select, countType count, QSqlDatabase database) {
    QString queryStr;

    if (!database.open()) {
        std::cout << "Error. Database not open." << std::endl;
    }
    switch (select) {
        case COUNT:
            queryStr = countPrep(column);
            break;
        case SUM:
            queryStr = sumPrep();
            break;
//        default:
//            queryStr = selectPrep();
//            break;
    }

    switch (count) {
        case LESS_THAN:
            queryStr += numLTPrep(value.toInt());
            break;
        case GREATER_THAN:
            queryStr += numGTPrep(value.toInt());
            break;
//        default:
//            queryStr = strLkPrep(column, value);
//            break;
    }
    return executeValueQuery(queryStr);
}


QString readTable::getOther(QString column, QString value, selectType select, strictType strict, QSqlDatabase database) {
    QString queryStr;

    if (!database.open()) {
        std::cout << "Error. Database not open." << std::endl;
    }
    switch (select) {
        case COUNT:
            queryStr = countPrep(column);
            break;
        case SUM:
            queryStr = sumPrep();
            break;
    }

    switch (strict) {
        case EQUAL:
            queryStr += strPrep(column, value);
            break;
        case LIKE:
            queryStr += strLkPrep(column, value);
    }

    return executeValueQuery(queryStr);
}

QString readTable::getOther(QString selectColumn, QString whereColumn, QString value, selectType select, strictType strict, QSqlDatabase database) {
    QString queryStr;

    if (!database.open()) {
        std::cout << "Error. Database not open." << std::endl;
    }
    switch (select) {
        case COUNT:
            queryStr = countPrep(selectColumn);
            break;
        case SUM:
            queryStr = sumPrep();
            break;
    }

    switch (strict) {
        case EQUAL:
            queryStr += strPrep(whereColumn, value);
            break;
        case LIKE:
            queryStr += strLkPrep(whereColumn, value);
    }

    return executeValueQuery(queryStr);
}

QString readTable::datePrep(int month) {
    return QString("WHERE date LIKE \"%1/%\"").arg(month);
}

QString readTable::numLTPrep(int number) {
    return QString("WHERE amount < %1").arg(number);
}

QString readTable::numGTPrep(int number) {
    return QString("WHERE amount > %1").arg(number);
}

QString readTable::strPrep(QString column, QString value) {
    return QString("WHERE %1 = \"%2\"").arg(column, value);
}

QString readTable::strLkPrep(QString column, QString value) {
    return QString("Where %1 LIKE \"%2\"").arg(column, value);
}

QString readTable::sumPrep() {
    return QString ("SELECT SUM(amount) FROM transactions ");
}

QString readTable::countPrep(QString column) {
    return QString("SELECT COUNT(%1) FROM transactions ").arg(column);
}

QString readTable::selectPrep() {
    return QString("SELECT * FROM transactions ");
}

QString readTable::selectPrep(QString column) {
    return QString("SELECT %1 FROM transactions ").arg(column);
}

QString readTable::selectDistinctPrep(QString column) {
    return QString("SELECT DISTINCT %1 FROM transactions").arg(column);
}

QString readTable::groupPrep(QString column) {
    return QString("GROUP BY %1").arg(column);
}


