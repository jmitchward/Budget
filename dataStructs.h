#ifndef DATASTRUCTS_H
#define DATASTRUCTS_H

#include <QObject>
#include <QSet>
#include "DTO/member.h"
#include "DTO/category.h"

class Categories {
public:
    Categories();
    bool addCategory(Category newCategory);
    bool removeCategory(Category oldCategory);
    bool checkCategory(Category cat);
    inline QList<Category> getCategories() { return categories; }
    inline void setCategories(QList<Category> newCategories) { categories = newCategories; }
private:
    QList<Category> categories;
};

class Members {
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

#endif // DATASTRUCTS_H
