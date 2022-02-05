#include "datacontroller.h"

dataController::dataController()
{
    transactions = tableData.getAllData();
    readMembers();
    readCategories();
}

void dataController::readCategories() {
    QList<QString> catValues;
    catValues = tableData.getColumn(QString("category"));
    for (auto cats = catValues.begin();
         cats < catValues.end() ; cats++) {
        Category tempCat;
        tempCat.setTitle(*cats);
        categories.addCategory(tempCat);
    }
}

void dataController::readMembers() {
    QList<QString> memValues;
    memValues = tableData.getColumn(QString("member"));
    for (auto mems = memValues.begin();
         mems < memValues.end() ; mems++) {
        Member tempMem;
        tempMem.setFirstName(*mems);
        members.addMember(tempMem);
    }
}

