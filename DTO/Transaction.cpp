#include "Transaction.h"
#include <iostream>

Transaction::Transaction() {
}


Transaction::Transaction(QString nDate, double nAmount,
                         QString nDescription, Store nStore,
                         Category nCategory, bool nShared,
                         Member nMember) {
    std::cout << "Creating new transaction." << std::endl;
    this->date = nDate;
    std::cout << "Set date." << std::endl;
    this->amount = nAmount;
    std::cout << "Set amount." << std::endl;
    this->description = nDescription;
    std::cout << "Set desc." << std::endl;
    this->store = nStore;
    std::cout << "Set store." << std::endl;
    this->category = nCategory;
    std::cout << "Set category." << std::endl;
    this->shared = nShared;
    std::cout << "Set shared." << std::endl;
    this->member = nMember;
    std::cout << "Set member." << std::endl;
}

Transaction::Transaction(QString nDate, double nAmount,
                        QString nDescription, QString nStore,
                        QString nCategory, bool nShared,
                        QString nMember) {

    std::cout << "Creating new transaction." << std::endl;
    this->date = nDate;
    std::cout << "Set date." << std::endl;
    this->amount = nAmount;
    std::cout << "Set amount." << std::endl;
    this->description = nDescription;
    std::cout << "Set desc." << std::endl;
    this->store = nStore;
    std::cout << "Set store." << std::endl;
    this->category = nCategory;
    std::cout << "Set category." << std::endl;
    this->shared = nShared;
    std::cout << "Set shared." << std::endl;
    this->member = nMember;
    std::cout << "Set member." << std::endl;
}


Transaction::Transaction(const Transaction& t) {
    this->date = t.date;
    this->amount = t.amount;
    this->description = t.description;
    this->store = t.store;
    this->category = t.category;
    this->shared = t.shared;
    this->member = t.member;
}




