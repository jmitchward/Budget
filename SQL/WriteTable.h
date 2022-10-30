#ifndef WRITETABLE_H
#define WRITETABLE_H

#include <iostream>
#include <QObject>
#include <QDir>
#include <QSqlQuery>
#include <QSqlError>
#include <SQL/SQLTableModel.h>

class WriteTable
{
public:
    WriteTable();
    void writeExpense(QList<QList<QString>>);
    void writeExpense(QList<QString>);
    void writeIncome(QList<QList<QString>>);
    void writeIncome(QList<QString>);
    int writeExpenseModel(SqlTableModel&, int);
private:
    QList<QList<QString>> data;
    QSqlDatabase budgetDB;
    QDir currentDir;
};

#endif // WRITETABLE_H
