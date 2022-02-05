#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QObject>
#include "dataStructs.h"

class Transaction
{
public:
    Transaction();
    Transaction(QString, double, QString, QString, Category, bool, Member);
    Transaction(QString, double, QString, QString, QString, bool, QString);
    Transaction(const Transaction&);


    const QString &getDate() const;
    void setDate(const QString &newDate);

    const QString &getStore() const;
    void setStore(const QString &newStore);

    const QString &getDescription() const;
    void setDescription(const QString &newDescription);

    double getAmount() const;
    void setAmount(double newAmount);

    Category &getCategory();
    void setCategory(Category &newCategory);

    Member &getMember();
    void setMember(Member &newMember);

    bool getShared() const;
    void setShared(bool newShared);

private:
    QString     date, store, description;
    double      amount;
    Category  category;
    Member      member;
    bool        shared;
};

#endif // TRANSACTION_H
