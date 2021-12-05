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
//    std::cout << "Path: " << qApp->applicationDirPath().toStdString() << std::endl;
    budgetDB = QSqlDatabase::addDatabase("QSQLITE");
    budgetDB.setDatabaseName("budget.db");
    budgetDB.setHostName("mitchell");
    budgetDB.setPassword("password");
    bool ok = budgetDB.open();
    if (ok) {std::cout << "Databse open." << std::endl;}
    else {std::cout << "Databse not open." << std::endl;}

    QSqlQuery query;
    if(query.exec("create table if not exists transactions("
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

    if (query.exec("PRAGMA journal_mode=WAL")) { std::cout << "WAL mode successful." << std::endl; }

    setCentralWidget(mainWidget);
    mainWidget->setLayout(mainLayout);

    QPushButton *addIncomeButton = new QPushButton();
    QPushButton *addExpenseButton = new QPushButton();
    QPushButton *viewExpensesButton = new QPushButton();
    QPushButton *viewChartButton = new QPushButton();
    QPushButton *viewStatsButton = new QPushButton();

    mainLayout->addLayout(sideLayout);
    sideLayout->addWidget(addIncomeButton);
    addIncomeButton->setText(tr("Add Income"));
    sideLayout->addWidget(addExpenseButton);
    addExpenseButton->setText(tr("Add Expense"));
    sideLayout->addWidget(viewExpensesButton);
    viewExpensesButton->setText(tr("View Expenses"));
    sideLayout->addWidget(viewStatsButton);
    viewStatsButton->setText(tr("View Stats"));
    sideLayout->addWidget(viewChartButton);
    viewChartButton->setText(tr("View Charts"));

    mainLayout->addWidget(budgetView);
    sqlTableModel *model = new sqlTableModel(budgetDB);
    inputFile = new QFile(":/Resources/july_transactions.csv");

    if (inputFile->open(QIODevice::ReadOnly))
    {
        readFile database(inputFile);
        writeTable table(database.readCSV());
    }
    else { std::cout << "File not open." << std::endl; }

    inputFile->close();
    inputFile = new QFile(":/Resources/august_transactions.csv");

    if (inputFile->open(QIODevice::ReadOnly))
    {
        readFile database(inputFile);
        writeTable table(database.readCSV());
    }
    else { std::cout << "File not open." << std::endl; }

    inputFile->close();
    inputFile = new QFile(":/Resources/september_transactions.csv");

    if (inputFile->open(QIODevice::ReadOnly))
    {
        readFile database(inputFile);
        writeTable table(database.readCSV());
    }
    else { std::cout << "File not open." << std::endl; }

    inputFile->close();
    inputFile = new QFile(":/Resources/october_transactions.csv");

    if (inputFile->open(QIODevice::ReadOnly))
    {
        readFile database(inputFile);
        writeTable table(database.readCSV());
    }
    else { std::cout << "File not open." << std::endl; }

    inputFile->close();
    inputFile = new QFile(":/Resources/november_transactions.csv");

    if (inputFile->open(QIODevice::ReadOnly))
    {
        readFile database(inputFile);
        writeTable table(database.readCSV());
    }
    else { std::cout << "File not open." << std::endl; }

    inputFile->close();

    budgetView->setModel(model);
    budgetView->setColumnHidden(0, true);
    model->select();
    std::cout << "Model set." << std::endl;
    budgetView->show();
    std::cout << "Model shown." << std::endl;

    }

MainWindow::~MainWindow()
{
    delete ui;
}




