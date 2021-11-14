#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "SQL/sqltablemodel.h"
#include "SQL/readfile.h"
#include "SQL/writetable.h"
#include <QSqlQuery>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Budget"));
    mainWidget = new QWidget();
    mainLayout = new QHBoxLayout();
    sideLayout = new QVBoxLayout();
    budgetView = new QTableView();
    budgetDB = QSqlDatabase::addDatabase("QSQLITE");
    budgetDB.setDatabaseName("budget.db");
    budgetDB.setHostName("mitchell");
    budgetDB.setPassword("password");
    bool ok = budgetDB.open();
    if (ok) {std::cout << "Databse open." << std::endl;}
    else {std::cout << "Databse not open." << std::endl;}

    QSqlQuery query;
    if(query.exec("create table transactions("
            "primary_key INTEGER PRIMARY KEY,"
            "date TEXT, "
            "amount INTEGER NOT NULL, "
            "store TEXT, "
            "description TEXT, "
            "category TEXT NOT NULL, "
            "shared INTEGER NOT NULL, "
                  "member TEXT NOT NULL)")) {
        std::cout << "Query successful." << std::endl;
    }
    else { std::cout << query.lastError().text().toStdString() << std::endl;}

    setCentralWidget(mainWidget);
    mainWidget->setLayout(mainLayout);

    QPushButton *addIncomeButton = new QPushButton();
    QPushButton *addExpenseButton = new QPushButton();
    QPushButton *viewExpensesButton = new QPushButton();
    QPushButton *viewChartButton = new QPushButton();

    mainLayout->addLayout(sideLayout);
    sideLayout->addWidget(addIncomeButton);
    addIncomeButton->setText(tr("Add Income"));
    sideLayout->addWidget(addExpenseButton);
    addExpenseButton->setText(tr("Add Expense"));
    sideLayout->addWidget(viewExpensesButton);
    viewExpensesButton->setText(tr("View Expenses"));
    sideLayout->addWidget(viewChartButton);
    viewChartButton->setText(tr("View Charts"));

    mainLayout->addWidget(budgetView);
    sqlTableModel *model = new sqlTableModel(budgetDB);
    inputFile = new QFile(":/Resources/july_transactions.csv");

    if (inputFile->open(QIODevice::ReadOnly))
    {
        std::cout << "Calling readFile." << std::endl;
        readFile database(inputFile);
        std::cout << "Calling writeTable." << std::endl;
        writeTable table(database.readCSV());
    }
    else { std::cout << "File not open." << std::endl; }
//    std::cout << "Compiled CSV retrieved. Size: " << compiledCSV.size() << std::endl;
//    std::cout << "------------------------------------" << std::endl;
//     for (QList<QList<QString>>::iterator listEntries = compiledCSV.begin(); listEntries < compiledCSV.end(); listEntries++)
//     {
//        for (int i = 0; i < listEntries->size(); i++)
//        {
//            std::cout << "Value " << i << ": " << listEntries->at(i).toStdString() << std::endl;

//        }
//     }
//     std::cout << "------------------------------------" << std::endl;



    budgetView->setModel(model);
    model->select();
    std::cout << "Model set." << std::endl;
    budgetView->show();
    std::cout << "Model shown." << std::endl;

    }

MainWindow::~MainWindow()
{
    delete ui;
}




