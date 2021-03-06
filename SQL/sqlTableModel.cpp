#include "sqlTableModel.h"

sqlTableModel::sqlTableModel(QSqlDatabase database) :
    QSqlTableModel(nullptr, database)
{
    this->setTable("transactions");
    this->setHeaderData(1, Qt::Horizontal, tr("Date"));
    this->setHeaderData(2, Qt::Horizontal, tr("Amount"));
    this->setHeaderData(3, Qt::Horizontal, tr("Description"));
    this->setHeaderData(4, Qt::Horizontal, tr("Store"));
    this->setHeaderData(5, Qt::Horizontal, tr("Category"));
    this->setHeaderData(6, Qt::Horizontal, tr("Shared"));
    this->setHeaderData(7, Qt::Horizontal, tr("Member"));
    this->select();
}
