#ifndef SQLTABLEMODEL_H
#define SQLTABLEMODEL_H

#include <QObject>
#include <QSqlTableModel>

class SqlTableModel : public QSqlTableModel
{
    Q_OBJECT
public:
    SqlTableModel(QSqlDatabase);
    void populateModel(int, int, QString);
    void populateModel(int, QList<QString>);
};

#endif // SQLTABLEMODEL_H
