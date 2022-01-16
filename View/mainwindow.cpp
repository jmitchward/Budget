#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "SQL/sqltablemodel.h"
#include "SQL/readfile.h"
#include "SQL/writetable.h"
#include "SQL/readtable.h"
#include <QSqlQuery>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Budget"));
    // Widgets
    mainWidget = new QStackedWidget(this);
    viewStats statsTab(this);
    // Layouts
    mainLayout = new QHBoxLayout();
    sideLayout = new QVBoxLayout();
    // SQL
    budgetView = new QTableView();
    budgetDB = QSqlDatabase::addDatabase("QSQLITE");
    budgetDB.setDatabaseName("budget.db");
    budgetDB.setHostName("mitchell");
    budgetDB.setPassword("password");
    bool ok = budgetDB.open();
    if (ok) {std::cout << "Databse open." << std::endl;}
    else {std::cout << "Databse not open." << std::endl;}
    // Table Reader
    readTable dataRetriever;
    statsTab.setDatabase(budgetDB);
    QSqlQuery query;
    if(query.exec("create table if not exists transactions("
            "primary_key INTEGER PRIMARY KEY,"
            "date TEXT, "
            "amount INTEGER NOT NULL, "
            "store TEXT, "
            "description TEXT, "
            "category TEXT NOT NULL, "
            "shared INTEGER NOT NULL, "
            "member TEXT NOT NULL)"))
        { std::cout << "Query successful." << std::endl; }
    else
        { std::cout << query.lastError().text().toStdString() << std::endl; }

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
    connect(viewStatsButton, SIGNAL(clicked), &statsTab, SLOT(displayTab));
    connect(viewStatsButton, &QPushButton::clicked, [=]{std::cout << "Clicked." << std::endl;});
    sideLayout->addWidget(viewChartButton);
    viewChartButton->setText(tr("View Charts"));

    mainLayout->addWidget(budgetView);
    mainLayout->addWidget(&statsTab);
    sqlTableModel *model = new sqlTableModel(budgetDB);
/*
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
*/

    budgetView->setModel(model);
    budgetView->setColumnHidden(0, true);
    model->select();    
    budgetView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}




