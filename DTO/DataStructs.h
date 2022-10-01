#ifndef DATASTRUCTS_H
#define DATASTRUCTS_H

#include <QObject>
#include <QSet>
#include "DTO/Member.h"
#include "DTO/Category.h"
#include "DTO/Store.h"

class Categories : public QObject{
    Q_OBJECT
public:
    Categories();
    bool addCategory(Category);
    bool removeCategory(Category);
    bool checkCategory(Category);
    bool contains(Category);
    void append(Category);
    inline QList<Category> getCategories() { return categories; }
    inline void setCategories(QList<Category> newCategories) { categories = newCategories; }
private:
    QList<Category> categories;
};

class Members : public QObject {
    Q_OBJECT
public:
    Members();
    bool addMember(Member newMember);
    bool removeMember(Member oldMember);
    bool checkMember(Member mem);
    inline QList<Member> getMembers() { return members; }
    inline void setMembers(QList<Member> newMembers) { members = newMembers; }
private:
    QList<Member> members;
};

class Stores : public QObject {
    Q_OBJECT
public:
    Stores();
    bool addStore(Store newStore);
    bool removeStore(Store oldStore);
    bool checkStore(Store store);
    inline QList<Store> getStores() { return stores; }
    inline void setStores(QList<Store> newStores) { stores = newStores; }
private:
    QList<Store> stores;
};

#endif // DATASTRUCTS_H
