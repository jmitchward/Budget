#include "viewStats.h"

viewStats::viewStats(QWidget* parent) : ui(new Ui::viewStats)
{
    ui->setupUi(this);
    layout = new QBoxLayout(QBoxLayout::TopToBottom, parent);
    this->setLayout(layout);
    initConnections();
}

void viewStats::initConnections() {
    collectData();
}

void viewStats::collectData() {

    controller.collectData();

    foreach ( auto transaction, controller.getTransactions() ) {
        if ( categoryTotals.contains(transaction.getCtg().getTitle() ) ) {
            std::cout << "Category found: " << transaction.getCtg().getTitle().toStdString() << std::endl;
            categoryTotals[transaction.getCtg().getTitle()] += transaction.getAmt();
            std::cout << "Category amount: " << categoryTotals[transaction.getCtg().getTitle()] << std::endl;
        }
        else {
            std::cout << "New Category: " << transaction.getCtg().getTitle().toStdString() << std::endl;
            categoryTotals[transaction.getCtg().getTitle()] = transaction.getAmt();
            std::cout << "Category amount: " << categoryTotals[transaction.getCtg().getTitle()] << std::endl;
        }

        if ( memberTotals.contains(transaction.getMbr().getFirstName() ) ) {
            std::cout << "Member found: " << transaction.getMbr().getFirstName().toStdString() << std::endl;
            memberTotals[transaction.getMbr().getFirstName()] += transaction.getAmt();
            std::cout << "Member amount: " << memberTotals[transaction.getMbr().getFirstName()] << std::endl;
        }
        else {
            std::cout << "New Member: " << transaction.getMbr().getFirstName().toStdString() << std::endl;
            memberTotals[transaction.getMbr().getFirstName()] = transaction.getAmt();
            std::cout << "Member amount: " << memberTotals[transaction.getMbr().getFirstName()] << std::endl;
        }
    }

    ui->topLeftSideLabel->setText(QString("Category Totals"));
    for ( auto cat : categoryTotals.keys() ) {
        QHBoxLayout *catLayout = new QHBoxLayout;
        QLabel *catName = new QLabel;
        QLabel *catTotal = new QLabel;
        catName->setBuddy(catTotal);
        catName->setText(cat);
        catTotal->setNum(categoryTotals.value(cat));
        catLayout->addWidget(catName);
        catLayout->addWidget(catTotal);
        ui->topLeftSideLayout->addLayout(catLayout);
    }

    ui->bottomLeftSideLabel->setText(QString("Member Totals"));
    for ( auto mbr : memberTotals.keys() ) {
        QHBoxLayout *mbrLayout = new QHBoxLayout;
        QLabel *mbrName = new QLabel;
        QLabel *mbrTotal = new QLabel;
        mbrName->setBuddy(mbrTotal);
        mbrName->setText(mbr);
        mbrTotal->setNum(categoryTotals.value(mbr));
        mbrLayout->addWidget(mbrName);
        mbrLayout->addWidget(mbrTotal);
        ui->bottomLeftSideLayout->addLayout(mbrLayout);
    }

}

void viewStats::getByMonthly() {
}

void viewStats::getByCategory() {

}

void viewStats::getByDate() {
}

void viewStats::getByMember() {

}

void viewStats::getByStore() {

}

void viewStats::displayTab() {
    std::cout << "This was clicked!" << std::endl;

}
