#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSqlTableModel>
#include <QTableView>
#include <QSqlDatabase>
#include <iostream>
#include <QStandardItemModel>
#include <QFile>
#include <QDir>


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
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QWidget *mainWidget;
    QHBoxLayout *mainLayout;
    QVBoxLayout *sideLayout;
    QTableView *budgetView;
    QSqlDatabase budgetDB;
    QList<QList<QString>> compiledCSV;
    QFile *inputFile;
    QDir currentDir;


};
#endif // MAINWINDOW_H
