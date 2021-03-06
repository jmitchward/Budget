#ifndef DATACONTROLLER_H
#define DATACONTROLLER_H

#include "DTO/dataStructs.h"
#include "DTO/member.h"
#include "DTO/transaction.h"
#include "SQL/readTable.h"

class dataController
{
public:
    dataController();

    void                        collectData();

    inline QList<Transaction>   getTransactions()
                                    { return transactions;}
    inline QList<Category>      getCategories()
                                    { return categories.getCategories(); }
    inline QList<Member>        getMembers()
                                    { return members.getMembers(); }
    inline bool                 checkCategory(Category category)
                                    { return categories.checkCategory(category); }
    inline bool                 checkMember(Member member)
                                    { return members.checkMember(member);}
    inline void                 addCategory(Category category)
                                    { categories.addCategory(category);}
    inline void                 addMember(Member member)
                                    { members.addMember(member); }

private:
    Categories          categories;
    Members             members;
    QList<Transaction>  transactions;
    readTable           tableReader;
};

#endif // DATACONTROLLER_H
