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

#include "View/viewStats.h"
#include "View/addIncomeBox.h"
#include "View/addExpenseBox.h"
#include "View/categoryEditBox.h"

#include "SQL/sqlTableModel.h"
#include "SQL/readFile.h"
#include "SQL/writeTable.h"
#include "SQL/readTable.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

template <typename T>
struct column
{
public:
    column() {};
    column(QString name, QVector<T> values) : name(name), values(values) {}
    void setName(QString newName) {name = newName;}
    void setValues(QVector<T> newValues) {values = newValues;}
    QString getName(void) {return name;}
    QVector<T> getValues(void) {return values;}
    void addValue(T value) {values.append(value);}
private:
    QString name;
    QVector<T> values;
};

class MainWindow : public QMainWindow
{
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
    viewStats *statsTab;
    AddIncomeBox * incomeBox;
    AddExpenseBox * expenseBox;
    CategoryEditBox* categoryEdit;
    // LAYOUTS
    QGridLayout *gridLayout;;
    QHBoxLayout *mainLayout;
    QVBoxLayout *sideLayout;
    // SQL
    QTableView *budgetView;
    QSqlDatabase budgetDB;
    SqlTableModel *model;
    ReadTable   tableData;
    // DATA STORAGE
    QList<QList<QString>> compiledCSV;
    QFile *inputFile;
    QDir currentDir;   
};
#endif // MAINWINDOW_H
