#include "viewstats.h"

viewStats::viewStats(QWidget* parent)
{
    layout = new QBoxLayout(QBoxLayout::TopToBottom, parent);
    this->setLayout(layout);
    aButton = new QPushButton(this);
}
void viewStats::collectData() {
    QList<Transaction> allData = tableReader.getAllData(database);
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
