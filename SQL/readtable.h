#ifndef READTABLE_H
#define READTABLE_H

#include <iostream>
#include <QObject>
#include <QFile>
#include <QDir>
#include <QSqlQuery>
#include <QSqlError>
#include "DTO/transaction.h"

enum Month {
    Default,
    January,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

enum selectType {
    COUNT,
    SUM
};

enum countType {
    LESS_THAN,
    GREATER_THAN
};

enum strictType {
    EQUAL,
    LIKE
};

class readTable
{
public:
    readTable();
    QList<Transaction>  getAllData(QSqlDatabase);
    QList<Transaction>  getData(QString, QString, strictType, QSqlDatabase);
    QList<Transaction>  getData(QString, QString, QString, strictType, QSqlDatabase);
    QList<Transaction>  executeQuery(QString);
    QString             getDates(QString, int, selectType, QSqlDatabase);
    QString             getAmounts(QString, QString, selectType, countType, QSqlDatabase);
    QString             getOther(QString, QString, selectType, strictType, QSqlDatabase);
    QString             getOther(QString, QString, QString, selectType, strictType, QSqlDatabase);

    QString datePrep(int);
    QString numLTPrep(int);
    QString numGTPrep(int);
    QString strPrep(QString, QString);
    QString strLkPrep(QString, QString);
    QString sumPrep();
    QString countPrep(QString);
    QString selectPrep();
    QString selectPrep(QString);
    QString groupPrep(QString);

};

#endif // READTABLE_H
