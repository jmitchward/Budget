#include "viewstats.h"

viewStats::viewStats(QWidget* parent)
{
    layout = new QBoxLayout(QBoxLayout::TopToBottom, parent);
    this->setLayout(layout);
    aButton = new QPushButton(this);
    initConnections();

}

void viewStats::initConnections() {
    connect(aButton, &QPushButton::clicked, [this] { collectData(); });
}

void viewStats::collectData() {
    std::cout << "Collecting data." << std::endl;
    QList<Transaction> allData = tableReader.getAllData();
    std::cout << "Returned." << std::endl;
    // retrieve the data from the table reader
}

void viewStats::getByMonthly() {
    QString builtQuery = tableReader.sumPrep();
    builtQuery += tableReader.groupPrep(QString("month"));
    std::cout << "Monthly query: " << builtQuery.toStdString() << std::endl;

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
