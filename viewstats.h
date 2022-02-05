#ifndef VIEWSTATS_H
#define VIEWSTATS_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QBoxLayout>
#include "Model/datacontroller.h"
#include "DTO/transaction.h"

class viewStats : public QWidget
{
    Q_OBJECT
public:
    viewStats(QWidget *parent = nullptr);
    void initData(QList<Transaction>);
    void getByMonthly();
    void getByDate();
    QMap<Category, QList<Transaction>> getByCategory();
    QMap<Member, QList<Transaction>>   getByMember();
    QMap<QString, QList<Transaction>>  getByStore();

    void initConnections();

public slots:
    void displayTab();
    inline void fetchCategoriesSlot(Categories cats) { categories = cats; }
    inline void fetchMembersSlot(Members mems) {members = mems;}

signals:
    void requestCategories();
    void requestMembers();

private:
    QList<Transaction> data;
    Categories categories;
    Members members;
    QBoxLayout *layout;
    QPushButton *aButton;
};

#endif // VIEWSTATS_H
