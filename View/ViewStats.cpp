#include "ViewStats.h"
#include <QTableWidget>

ViewStats::ViewStats(QWidget* parent)  {
    Q_UNUSED(parent);
    layout = new QGridLayout();
    setLayout(layout);
}

void ViewStats::setData(QList<Transaction> tr) {
    transactions = tr;
    parseData();
}

void ViewStats::clearData() {
    categoryTotals.clear();
    memberTotals.clear();
    storeTotals.clear();
}

void ViewStats::parseData() {

    foreach ( auto transaction, transactions ) {
        if ( categoryTotals.contains(transaction.getCtg().getTitle() ) ) {
            categoryTotals[transaction.getCtg().getTitle()] += transaction.getAmt();
        }
        else {
            categoryTotals[transaction.getCtg().getTitle()] = transaction.getAmt();
        }

        if ( memberTotals.contains(transaction.getMbr().getFirstName() ) ) {
            memberTotals[transaction.getMbr().getFirstName()] += transaction.getAmt();
        }
        else {
            memberTotals[transaction.getMbr().getFirstName()] = transaction.getAmt();
        }

        if ( storeTotals.contains(transaction.getStore().getStoreName() ) ) {
            storeTotals[transaction.getStore().getStoreName()] += transaction.getAmt();
        }
        else {
            storeTotals[transaction.getStore().getStoreName()] = transaction.getAmt();
        }
    }

    amountEdit = new AmountEditBox();
    QTableWidget* tableA = new QTableWidget();
    QString firstColumn = "Category";
    QString secondColumn = "Total";
    QStringList columnHeaders;

    columnHeaders.append(firstColumn);
    columnHeaders.append(secondColumn);
    tableA->setColumnCount(2);
    tableA->setRowCount(categoryTotals.size());
    tableA->setHorizontalHeaderLabels(columnHeaders);
    tableA->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    layout->addWidget(tableA, 0, 0);

    QTableWidget* tableB = new QTableWidget();
    firstColumn = "Member";

    columnHeaders.replace(0, firstColumn);
    tableB->setColumnCount(2);
    tableB->setRowCount(memberTotals.size());
    tableB->setHorizontalHeaderLabels(columnHeaders);
    tableB->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    layout->addWidget(tableB, 1, 0);

    QTableWidget* tableC = new QTableWidget();
    firstColumn = "Store";

    columnHeaders.replace(0, firstColumn);
    tableC->setColumnCount(2);
    tableC->setRowCount(storeTotals.size());
    tableC->setHorizontalHeaderLabels(columnHeaders);
    tableC->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    layout->addWidget(tableC, 2, 0);

    auto row = 0;
    for ( const auto &cat : categoryTotals.keys() ) {
        QTableWidgetItem* label = new QTableWidgetItem(cat);
        tableA->setItem(row, 0, label);
        QTableWidgetItem* amount = new QTableWidgetItem(QString::number(categoryTotals.value(cat)));
        tableA->setItem(row, 1, amount);
        row++;
    }

    tableA->setItemDelegateForColumn(1, amountEdit);

    row = 0;
    for ( auto mbr : memberTotals.keys() ) {
        QTableWidgetItem* label = new QTableWidgetItem(mbr);
        tableB->setItem(row, 0, label);
        QTableWidgetItem* amount = new QTableWidgetItem(QString::number(memberTotals.value(mbr)));
        tableB->setItem(row, 1, amount);
        row++;
    }
    tableB->setItemDelegateForColumn(1, amountEdit);

    row = 0;
    for ( auto store : storeTotals.keys() ) {
        QTableWidgetItem* label = new QTableWidgetItem(store);
        tableC->setItem(row, 0, label);
        QTableWidgetItem* amount = new QTableWidgetItem(QString::number(storeTotals.value(store)));
        tableC->setItem(row, 1, amount);
        row++;
    }
    tableC->setItemDelegateForColumn(1, amountEdit);
}

void ViewStats::getByMonthly() {
}

void ViewStats::getByCategory() {

}

void ViewStats::getByDate() {
}

void ViewStats::getByMember() {

}

void ViewStats::getByStore() {

}

void ViewStats::displayTab() {

}
