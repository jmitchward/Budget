#include "transaction.h"

Transaction::Transaction()
{
}


Transaction::Transaction(QString nDate, double nAmount,
                         QString nDescription, QString nStore,
                         Category nCategory, bool nShared,
                         Member nMember) {
    this->date.setValue(nDate);
    this->amount.setValue(nAmount);
    this->description.setValue(nDescription);
    this->store.setValue(nStore);
    this->category.setValue(nCategory);
    this->shared.setValue(nShared);
    this->member.setValue(nMember);
    this->date.setValue(nDate);
}

Transaction::Transaction(QString nDate, double nAmount,
                        QString nDescription, QString nStore,
                        QString nCategory, bool nShared,
                        QString nMember) {
    this->date.setValue(nDate);
    this->amount.setValue(nAmount);
    this->description.setValue(nDescription);
    this->store.setValue(nStore);
    this->category.setValue(Category(nCategory));
    this->shared.setValue(nShared);
    this->member.setValue(Member(nMember));
    this->date.setValue(nDate);
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




