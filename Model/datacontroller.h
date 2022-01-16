#ifndef DATACONTROLLER_H
#define DATACONTROLLER_H

#include "DTO/dataStructs.h"
#include "DTO/member.h"
#include "DTO/transaction.h"

class dataController
{
public:
    dataController();

    inline QList<QString>   getCategories()
                        { return categories.getValues(); }
    inline QList<Member>    getMembers()
                        { return members.getValues(); }
    inline bool checkCategory(QString category)
                        { return categories.checkValues(category); }
    inline bool checkMember(Member member)
                        { return members.checkValues(member);}
    inline void addCategory(QString category)
                        { categories.addValues(category);}
    inline void addMember(Member member)
                        { members.addValues(member); }

private:
    Category            categories;
    Members             members;
    QList<Transaction>  transactions;
};

#endif // DATACONTROLLER_H
