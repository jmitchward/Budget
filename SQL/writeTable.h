#ifndef WRITETABLE_H
#define WRITETABLE_H

#include <iostream>
#include <QObject>
#include <QDir>
#include <QSqlQuery>
#include <QSqlError>
#include <SQL/sqlTableModel.h>

class writeTable
{
public:
    writeTable(QList<QList<QString>>);
    void writeData();
    int writeModel(SqlTableModel&, int);
private:
    QList<QList<QString>> data;
    QSqlDatabase budgetDB;
    QDir currentDir;
};

#endif // WRITETABLE_H
