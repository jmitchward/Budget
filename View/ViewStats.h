#ifndef VIEWSTATS_H
#define VIEWSTATS_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QBoxLayout>
#include "DTO/Transaction.h"

class ViewStats : public QWidget {
    Q_OBJECT
public:
    ViewStats(QWidget *parent = nullptr);
    void getByMonthly();
    void getByCategory();
    void getByDate();
    void getByMember();
    void getByStore();
    void parseData();

public slots:
    void displayTab();
    void setData(QList<Transaction>);
    void clearData();
    inline void refreshData(QList<Transaction> data) {
        clearData();
        setData(data);
    }

private:
    QBoxLayout *layout;
    QPushButton *aButton;
    QList<Transaction>  transactions;
    QMap<QString, double> categoryTotals;
    QMap<QString, double> memberTotals;
    QMap<QString, double> storeTotals;
};

#endif // VIEWSTATS_H
