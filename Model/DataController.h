#ifndef DATACONTROLLER_H
#define DATACONTROLLER_H
#include <QWidget>
#include "DTO/DataStructs.h"
#include "DTO/Member.h"
#include "DTO/Transaction.h"
#include "SQL/ReadTable.h"
#include "SQL/WriteTable.h"
#include "SQL/SQLTableModel.h"
#include "SQL/ReadFile.h"

class DataController : public QWidget {

    Q_OBJECT

public:
    DataController(QWidget *parent = nullptr);

    void                        collectData();

    inline QList<Transaction>   getTransactions()
                                    { return transactions;}
    inline QList<Category>      getCategories()
                                    { return categories.getCategories(); }
    inline QList<QString>       getCategoriesStr()
                                    { return tableReader.getCategories(); }
    inline QList<Member>        getMembers()
                                    { return members.getMembers(); }
    inline QList<QString>       getMembersStr()
                                    { return tableReader.getMembers(); }
    inline QList<Store>         getStores()
                                    { return stores.getStores(); }
    inline QList<QString>       getStoresStr()
                                    { return tableReader.getMembers(); }
    inline bool                 checkCategory(Category category)
                                    { return categories.checkCategory(category); }
    inline bool                 checkMember(Member member)
                                    { return members.checkMember(member);}
    inline void                 addCategory(Category category)
                                    { categories.addCategory(category);}
    inline void                 addMember(Member member)
                                    { members.addMember(member); }
    void initDatabase(void);
    void initDefaultDatabase(void);

    inline SqlTableModel* getModel()
                                    { return model; }

    inline void             requestTransactions()
                                    { model->selectTransactions(); }

    inline void             requestEarnings()
                                    { model->selectEarnings(); }

public slots:
    void addNewExpense(QList<QString>);
    void addNewIncome(QList<QString>);
    void newExpenseError();
    void newIncomeError();

signals:
    void expenseAdded();
    void incomeAdded();

private:
    Categories          categories;
    Members             members;
    Stores              stores;
    QList<Transaction>  transactions;
    ReadFile            fileReader;
    ReadTable           tableReader;
    WriteTable          tableWriter;
    QSqlDatabase        database;
    SqlTableModel       *model;
    QFile               *inputFile;

    int expenseRow;
    int incomeRow;
};

#endif // DATACONTROLLER_H
