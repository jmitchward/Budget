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
    viewStats(QWidget *parent);
    inline void setDatabase(QSqlDatabase nDatabase) {
        database = nDatabase;
    }
    void collectData();
    void getByMonthly();
    void getByCategory();
    void getByDate();
    void getByMember();
    void getByStore();

public slots:
    void displayTab();

private:
    QSqlDatabase database;
    QBoxLayout *layout;
    readTable tableReader;
    QPushButton *aButton;

};

#endif // VIEWSTATS_H
