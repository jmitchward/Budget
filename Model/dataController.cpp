#include "dataController.h"

DataController::DataController() {
}

void DataController::collectData() {
    transactions = tableReader.getAllData();
    foreach( auto transaction, transactions) {
        if (!categories.checkCategory(transaction.getCtg())) {
            categories.addCategory(transaction.getCtg());
        }
        if (!members.checkMember(transaction.getMbr())) {
            members.addMember(transaction.getMbr());
        }
    }
}
