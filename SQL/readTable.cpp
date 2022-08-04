#include "readTable.h"

ReadTable::ReadTable() {
    std::cout << "readTable created." << std::endl;
}

QList<Transaction> ReadTable::getAllData() {
    QSqlQuery query;
    QList<Transaction> readTransactions;

    QString selectQuery("SELECT * FROM transactions ");

    query.prepare(selectQuery);

    if (query.exec()) { std::cout << "getAllData() executed successfully." << std::endl; }
    else { std::cout << "getAllData() failed." << std::endl
                     << query.lastError().text().toStdString() << std::endl;}

    while (query.next()) {

        Transaction *transaction = new Transaction();
        // Date
        transaction->setDate(query.value(1).toString());
//        std::cout << "Date set. "  << query.value(1).toString().toStdString() << std::endl;
        // Amount
        transaction->setAmt(query.value(2).toDouble());
//        std::cout << "Amount set. " << query.value(2).toDouble() << std::endl;
        // Description
        transaction->setDesc(query.value(3).toString());
//        std::cout << "Desc set. "   << query.value(3).toString().toStdString() << std::endl;
        // Store
        transaction->setStore(query.value(4).toString());
//        std::cout << "Store set. "  << query.value(4).toString().toStdString() << std::endl;
        // Category
//        std::cout << "Creating category." << std::endl;
        Category newCategory;
        newCategory.setTitle(query.value(5).toString());
//        std::cout << "New instance created. " << std::endl;
        transaction->setCtg(newCategory);
//        std::cout << "Cat set. "    << query.value(5).toString().toStdString() << std::endl;
        // Shared
        transaction->setShr(query.value(6).toBool());
//        std::cout << "Shared set. " << query.value(6).toBool() << std::endl;
        // Member
        transaction->setMbr(Member(query.value(7).toString()));
//        std::cout << "Member set. "    << query.value(7).toString().toStdString() << std::endl;

//        std::cout << "Attempting to add transaction." << std::endl;
        // Add it ito the returning list of transactions
        readTransactions.append(*transaction);
//        std::cout << "Transaction appended." << std::endl;
    }
    return readTransactions;
}

QList<Transaction> ReadTable::getData(QString column, QString value, strictType strict, QSqlDatabase database) {
    QSqlQuery query;
    QString queryStr;
    QList<Transaction> readTransactions;

    if (!database.open()) {
        std::cout << "getData() database not open." << std::endl;
    }

    queryStr = selectPrep();

    switch (strict) {
        case EQUAL:
            queryStr += strPrep(column, value);
            break;
        case LIKE:
            queryStr += strLkPrep(column, value);
    }

    query.prepare(queryStr);

    if (query.exec()) { std::cout << "Success." << std::endl; }
    else { std::cout << "Error. Query failed." << std::endl
                     << query.lastError().text().toStdString() << std::endl;}

    while (query.next()) {
        Transaction transaction;
        // Create a transaction based on the current line
        // Date
        transaction.setDate(query.value(1).toString());
        // Amount
        transaction.setAmt(query.value(2).toDouble());
        // Description
        transaction.setDesc(query.value(3).toString());
        // Store
        transaction.setStore(query.value(4).toString());
        // Category
        Category cat;
        cat.setTitle(query.value(5).toString());
        transaction.setCtg(cat);
        // Shared
        transaction.setShr(query.value(6).toBool());
        // Member
        Member mem;
        mem.setFirstName(query.value(7).toString());
        transaction.setMbr(mem);
        // Add transaction to the list
        readTransactions.append(transaction);
    }
    return readTransactions;
}

QList<Transaction> ReadTable::getData(QString selectColumn, QString whereColumn, QString value, strictType strict, QSqlDatabase database) {
    QSqlQuery query;
    QString queryStr;
    QList<Transaction> readTransactions;

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

    query.prepare(queryStr);

    if (query.exec()) { std::cout << "Success." << std::endl; }
    else { std::cout << "Error. Query failed." << std::endl
                     << query.lastError().text().toStdString() << std::endl;}

    while (query.next()) {
        // Create a transaction based on the current line
        Transaction transaction(// Date
                                query.value(1).toString(),
                                // Amount
                                query.value(2).toDouble(),
                                // Description
                                query.value(3).toString(),
                                // Store
                                query.value(4).toString(),
                                // Category
                                Category(query.value(5).toString()),
                                // Shared
                                query.value(6).toBool(),
                                // Member
                                Member(query.value(7).toString())
                                );
        // Add it ito the returning list of transactions
        readTransactions.append(transaction);
    }
    return readTransactions;
}

QList<Transaction> ReadTable::executeQuery(QString setQuery) {
    QSqlQuery query;
    QList<Transaction> readTransactions;

    query.prepare(setQuery);

    if (query.exec()) { std::cout << "Success." << std::endl; }
    else { std::cout << "Error. Query failed." << std::endl
                     << query.lastError().text().toStdString() << std::endl;}

    while (query.next()) {
        // Create a transaction based on the current line
        Transaction transaction(// Date
                                query.value(1).toString(),
                                // Amount
                                query.value(2).toDouble(),
                                // Description
                                query.value(3).toString(),
                                // Store
                                query.value(4).toString(),
                                // Category
                                Category(query.value(5).toString()),
                                // Shared
                                query.value(6).toBool(),
                                // Member
                                Member(query.value(7).toString())
                                );
        // Add it ito the returning list of transactions
        readTransactions.append(transaction);
    }
    return readTransactions;
}


QString ReadTable::getDates(QString column, int value, selectType select, QSqlDatabase database) {
    QSqlQuery query;
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
    query.prepare(queryStr);
    if(!query.exec()) { std::cout << "Query failed." << std::endl; }
    return query.value(0).toString();
}

QString ReadTable::getAmounts(QString column, QString value, selectType select, countType count, QSqlDatabase database) {
    QSqlQuery query;
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

    query.prepare(queryStr);
    if(!query.exec()) { std::cout << "Query failed." << std::endl; }
    return query.value(0).toString();
}


QString ReadTable::getOther(QString column, QString value, selectType select, strictType strict, QSqlDatabase database) {
    QSqlQuery query;
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

    query.prepare(queryStr);
    if(!query.exec()) { std::cout << "Query failed." << std::endl; }
    return query.value(0).toString();
}

QString ReadTable::getOther(QString selectColumn, QString whereColumn, QString value, selectType select, strictType strict, QSqlDatabase database) {
    QSqlQuery query;
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

    query.prepare(queryStr);
    if(!query.exec()) { std::cout << "Query failed." << std::endl; }
    return query.value(0).toString();
}

QList<QString> ReadTable::getCategories() {
    QSqlQuery query;
    QString queryStr = QString("SELECT DISTINCT Category FROM transactions");
    query.prepare(queryStr);
    if ( !query.exec()) { std::cout << "Query failed." << std::endl; }
    while ( query.next() ) {
        categories.append(query.value(0).toString());
    }
    return categories;
}

QString ReadTable::datePrep(int month) {
    return QString("WHERE date LIKE \"%1/%\"").arg(month);
}

QString ReadTable::numLTPrep(int number) {
    return QString("WHERE amount < %1").arg(number);
}

QString ReadTable::numGTPrep(int number) {
    return QString("WHERE amount > %1").arg(number);
}

QString ReadTable::strPrep(QString column, QString value) {
    return QString("WHERE %1 = \"%2\"").arg(column, value);
}

QString ReadTable::strLkPrep(QString column, QString value) {
    return QString("Where %1 LIKE \"%2\"").arg(column, value);
}

QString ReadTable::sumPrep() {
    return QString ("SELECT SUM(amount) FROM transactions ");
}

QString ReadTable::countPrep(QString column) {
    return QString("SELECT COUNT(%1) FROM transactions ").arg(column);
}

QString ReadTable::selectPrep() {
    return QString("SELECT * FROM transactions ");
}

QString ReadTable::selectPrep(QString column) {
    return QString("SELECT %1 FROM transactions ").arg(column);
}

QString ReadTable::groupPrep(QString column) {
    return QString("GROUP BY %1").arg(column);
}


