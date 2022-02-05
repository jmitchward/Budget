#include "viewstats.h"

viewStats::viewStats(QWidget* parent)
{
    layout = new QBoxLayout(QBoxLayout::TopToBottom, parent);
    this->setLayout(layout);
    aButton = new QPushButton(this);

}

void viewStats::initData(QList<Transaction> newData) {
    data = newData;
}

void viewStats::getByMonthly() {

}

QMap<Category, QList<Transaction>> viewStats::getByCategory() {
    QMap<Category, QList<Transaction>> results;
    for (auto iter = data.begin(); iter < data.end(); iter++) {
        // If QMap result does not contain the key Category
//        results.value(iter->getCategory()).append(*iter);
//        if (!results.keys().contains(iter->getCategory())) {
//                // Add the current Category to the list of keys
//                results.keys().append(iter->getCategory());
//        }
//        // Insert the transaction into the category's list
//        results.value(iter->getCategory()).append(*iter);
    }
    return results;
}

void viewStats::getByDate() {

}

QMap<Member, QList<Transaction>> viewStats::getByMember() {
    QMap<Member, QList<Transaction>> results;
    for (auto iter = data.begin(); iter < data.end(); iter++) {
        // If QMap result does not contain the key Category
//        results.value(iter->getMember()).append(*iter);
//        if (!results.keys().contains(iter->getMember())) {
//                // Add the current Category to the list of keys
//                results.keys().append(iter->getMember());
//        }
//        // Insert the transaction into the category's list
//        results.value(iter->getMember()).append(*iter);
    }
    return results;
}

QMap<QString, QList<Transaction>> viewStats::getByStore() {
    QMap<QString, QList<Transaction>> results;
    for (auto iter = data.begin(); iter < data.end(); iter++) {
        // If QMap result does not contain the key Category
        if (!results.keys().contains(iter->getStore())) {
                // Add the current Category to the list of keys
                results.keys().append(iter->getStore());
        }
        // Insert the transaction into the category's list
        results.value(iter->getStore()).append(*iter);
    }
    return results;
}

void viewStats::displayTab() {
    std::cout << "This was clicked!" << std::endl;

}
