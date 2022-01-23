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
    Transaction(const Transaction&);

    inline void setDate (QString nD)    { date          = nD;   }
    inline void setStore(QString nS)    { store         = nS;   }
    inline void setDesc (QString nDsc)  { description   = nDsc; }
    inline void setAmt  (double nAmt)   { amount        = nAmt; }
    inline void setCtg  (Category ctg)  { category      = ctg;  }
    inline void setMbr  (Member mbr)    { member        = mbr;  }
    inline void setShr  (bool shr)      { shared        = shr;  }

private:
    QString     date, store, description;
    double      amount;
    Category    category;
    Member      member;
    bool        shared;
};

#endif // TRANSACTION_H
