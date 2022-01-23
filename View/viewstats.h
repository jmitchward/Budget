#ifndef VIEWSTATS_H
#define VIEWSTATS_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QBoxLayout>
#include "SQL/readtable.h"
#include "DTO/transaction.h"

class viewStats : public QWidget
{
    Q_OBJECT
public:
    viewStats(QWidget *parent = nullptr);
    inline void setDatabase(QSqlDatabase nDatabase) {
        database = nDatabase;
    }
    void getByMonthly();
    void getByCategory();
    void getByDate();
    void getByMember();
    void getByStore();

    void initConnections();

public slots:
    void displayTab();
    void collectData();

private:
    QSqlDatabase database;
    QBoxLayout *layout;
    readTable tableReader;
    QPushButton *aButton;

};

#endif // VIEWSTATS_H
