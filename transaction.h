#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QObject>
#include "dataStructs.h"

class Transaction
{
    Q_OBJECT
public:
    Transaction();



private:
    QString date;
    double amount;
    QString description;
    Category category;
    bool shared;


};

#endif // TRANSACTION_H
