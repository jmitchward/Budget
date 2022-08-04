#ifndef VIEWSTATS_H
#define VIEWSTATS_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QBoxLayout>
#include "Model/dataController.h"
#include "DTO/transaction.h"
#include "ui_viewStats.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ViewStats; }
QT_END_NAMESPACE

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
    DataController  controller;
    QPushButton *aButton;
    Ui::ViewStats   *ui;
    QMap<QString, double> categoryTotals;
    QMap<QString, double> memberTotals;
};

#endif // VIEWSTATS_H
