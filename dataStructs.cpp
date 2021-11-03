#include "dataStructs.h"

Category::Category() {
    expenseCategories << "Groceries"
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


bool Category::checkCategory(QString category) {
    return expenseCategories.contains(category);
}

QList<QString> Category::getCategories() {
    return expenseCategories.values();
}

void Category::addCategory(QString category) {
    if (!expenseCategories.contains(category)) {
        expenseCategories.insert(category);
    }
}





