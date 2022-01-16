#include "dataStructs.h"

Category::Category() {
    init();
}

Category::Category(QString category) {
    if (!this->checkValues(category)) {
        this->itemValue = category;
    }
}

void Category::init() {
    itemValues << "Groceries"
                      << "Gifts"
                      << "Health/Medical"
                      << "Home"
                      << "Transportation/Gas"
                      << "Personal"
                      << "Other"
                      << "Utilities"
                      << "Travel"
                      << "Debt"
                      << "Crafts"
                      << "Rent"
                      << "Dining Out"
                      << "Subscriptions"
                      << "Clothes";
}

Members::Members() {
    init();
}

Members::Members(QString firstName) {
    Member tempMember(firstName);
    addMember(tempMember);
}

QList<Member> Members::getMembers() {
    return this->getValues();
}

Member Members::getMember(QString firstName) {
    for (QList<Member>::iterator memberFinder = this->itemValues.begin();
         memberFinder < this->itemValues.end(); memberFinder++) {
        if (memberFinder->getFirstName() == firstName) {
            return *memberFinder;
        }
    }
    return Member();
}

void Members::addMember(Member newMember) {
    // If the member being added does not have the default null name, it is valid
    if (getMember(newMember.getFirstName()).getFirstName() != "NULL") {
        this->itemValue = newMember;
        this->itemValues.append(newMember);
    }
}

void Members::init() {

}









