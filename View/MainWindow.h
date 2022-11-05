#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>
#include <QStackedWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QAbstractButton>
#include <QSqlTableModel>
#include <QTableView>
#include <QSqlDatabase>
#include <QStandardItemModel>
#include <QFile>
#include <QDir>
#include <QSqlQuery>
#include <QSqlError>

#include "View/ViewStats.h"
#include "View/Dialogs/AddIncomeBox.h"
#include "View/Dialogs/AddExpenseBox.h"
#include "View/Delegates/AmountEditBox.h"
#include "View/Delegates/CategoryEditBox.h"
#include "View/Delegates/MemberEditBox.h"
#include "Model/DataController.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    void initDB(void);
    void initMenu(void);
    void initDefaultDB(void);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    // WIDGETS
    QStackedWidget *mainWidget;
    QWidget *budgetViewWidget;
    QWidget *gridWidget;
    ViewStats *statsTab;
    AddIncomeBox * incomeBox;
    AddExpenseBox * expenseBox;
    // ITEM DELEGATES
    AmountEditBox*  amountEdit;
    CategoryEditBox* categoryEdit;
    MemberEditBox*  memberEdit;
    // LAYOUTS
    QGridLayout *gridLayout;;
    QHBoxLayout *mainLayout;
    QVBoxLayout *sideLayout;
    // SQL
    QTableView *budgetView;
    // DATA STORAGE
    DataController *dataController;
};
#endif // MAINWINDOW_H
