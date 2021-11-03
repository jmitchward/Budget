#include "sqltablemodel.h"

sqlTableModel::sqlTableModel()
{
    this->setTable("transactions");
    this->setHeaderData(0, Qt::Horizontal, tr("Date"));
    this->setHeaderData(1, Qt::Horizontal, tr("Amount"));
    this->setHeaderData(2, Qt::Horizontal, tr("Description"));
    this->setHeaderData(3, Qt::Horizontal, tr("Category"));
    this->setHeaderData(4, Qt::Horizontal, tr("Shared"));
    this->setHeaderData(5, Qt::Horizontal, tr("Purchased"));
}
