#ifndef DATACONTROLLER_H
#define DATACONTROLLER_H

#include "DTO/dataStructs.h"
#include "DTO/member.h"
#include "DTO/transaction.h"
#include "SQL/readtable.h"

class dataController
{
public:
    dataController();

    inline QList<Transaction> getData() { return transactions; }

    inline QList<Category>   getCategories()
                        { return categories.getCategories(); }
    inline QList<Member>    getMembers()
                        { return members.getMembers(); }
    inline bool checkCategory(Category category)
                        { return categories.checkCategory(category); }
    inline bool checkMember(Member member)
                        { return members.checkMember(member); }
    inline void addCategory(Category category)
                        { categories.addCategory(category); }
    inline void addMember(Member member)
                        { members.addMember(member); }

    inline Member fetchMember(QString firstName) {
        QList<Member>::const_iterator memIt;
        for (memIt = members.getMembers().cbegin();
             memIt < members.getMembers().cend();
             memIt++) {
            if (*memIt == firstName) {
                std::cout << "Member found." << std::endl;
                return *memIt;
            }
        }
        return Member();
    }

    inline Category fetchCategory(QString title) {
        QList<Category>::const_iterator catIt;
        for (catIt = categories.getCategories().cbegin();
             catIt < categories.getCategories().cend();
             catIt++) {
            if (*catIt == title) {
                std::cout << "Category found." << std::endl;
                return *catIt;
            }
        }
        return Category();
    }

    void readCategories();
    void readMembers();

private:
    readTable           tableData;
    Categories          categories;
    Members             members;
    QList<Transaction>  transactions;
};

#endif // DATACONTROLLER_H
