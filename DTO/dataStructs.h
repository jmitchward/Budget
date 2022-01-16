#ifndef DATASTRUCTS_H
#define DATASTRUCTS_H

#include <QObject>
#include <QSet>
#include "DTO/member.h"

template <class T>
class budgetItem : public QObject {
public:
    QList<T> getValues() {
        return itemValues;
    }
    void addValues(T& value) {
//        if (!itemValues.contains(value)) {
            itemValues.append(value);
//        }
    }

    bool checkValues(T& value) {
        return itemValues.contains(value);
    }

    budgetItem operator=(const budgetItem& b) {
        this->itemValue = b.itemValue;
        this->itemValues = b.itemValues;
    }

    budgetItem() {
        T defaultValue;
        itemValue = defaultValue;
    }

    budgetItem(T nValue) {
        this->itemValue = nValue;
    }

    budgetItem(const budgetItem &nItem) {
        this->itemValue = nItem.itemValue;
        this->itemValues = nItem.itemValues;
    }

    T           itemValue;
    QList<T>    itemValues;
};

class Category : public budgetItem<QString> {
    Q_OBJECT
public:
    Category();
    Category(QString category);
private:
    void init();

};

class Members : public budgetItem<Member> {
    Q_OBJECT
public:
    Members();
    Members(QString member);
    QList<Member>   getMembers();
    Member          getMember(QString firstName);
    void            addMember(Member);
private:
    void init();
};

#endif // DATASTRUCTS_H
