#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QObject>
#include "dataStructs.h"

template <typename T>
class transactionItem {
public:
    void setValue(T nValue) {
        value = nValue;
    }

    T getValue() {
        return value;
    }

    transactionItem() {
        T defaultValue;
        value = defaultValue;
    }

    transactionItem(const transactionItem& nItem) {
        this = nItem;
    }

    T& operator=(const T nValue) {
        value = nValue.value;
        return this;
    }

private:
    T value;
};

class Transaction
{
public:
    Transaction();
    Transaction(QString, double, QString, QString, Category, bool, Member);
    Transaction(QString, double, QString, QString, QString, bool, QString);
    void operator()(QString, double, QString, QString, Category, bool, Member);
    Transaction(const Transaction&);
private:
    transactionItem<QString>    date,
                                store,
                                description;
    transactionItem<double>     amount;
    transactionItem<Category>   category;
    transactionItem<Member>     member;
    transactionItem<bool>       shared;
};

#endif // TRANSACTION_H
