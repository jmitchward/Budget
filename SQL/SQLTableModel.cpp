#include "SQLTableModel.h"

SqlTableModel::SqlTableModel(QSqlDatabase database) : QSqlTableModel(nullptr, database) {
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

void SqlTableModel::populateModel(int row, int column, QString data) {
    QModelIndex modelIndex = this->index(row, column, QModelIndex());
    this->setData(modelIndex, static_cast<QVariant>(data));
}

void SqlTableModel::populateExpenseModel(int row, QList<QString> data) {
    for (auto i = 0; i < 7; i++) {
        qDebug() << "POPULATE MODEL | ROW |" << row <<"| COLUMN |" << i;
        QModelIndex modelIndex = this->index(row, i, QModelIndex());
        this->setData(modelIndex, data[i]);
    }
}

void SqlTableModel::selectTransactions() {
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

void SqlTableModel::selectEarnings() {
    this->setTable("earnings");
    this->setHeaderData(1, Qt::Horizontal, tr("Date"));
    this->setHeaderData(2, Qt::Horizontal, tr("Amount"));
    this->setHeaderData(3, Qt::Horizontal, tr("Type"));
    this->setHeaderData(4, Qt::Horizontal, tr("Description"));
    this->setHeaderData(5, Qt::Horizontal, tr("Category"));
    this->setHeaderData(6, Qt::Horizontal, tr("Member"));
    this->select();
}

