#ifndef WRITETABLE_H
#define WRITETABLE_H

#include <iostream>
#include <QObject>
#include <QDir>
#include <QSqlQuery>
#include <QSqlError>

class writeTable
{
public:
    writeTable(QList<QList<QString>>);
    void writeData();
private:
    QList<QList<QString>> data;
    QSqlDatabase budgetDB;
    QDir currentDir;
};

#endif // WRITETABLE_H
