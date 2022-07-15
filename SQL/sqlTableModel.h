#ifndef SQLTABLEMODEL_H
#define SQLTABLEMODEL_H

#include <QObject>
#include <QSqlTableModel>

class sqlTableModel : public QSqlTableModel
{
    Q_OBJECT
public:
    sqlTableModel(QSqlDatabase);
};

#endif // SQLTABLEMODEL_H
