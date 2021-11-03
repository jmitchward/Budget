#include "mainwindow.h"
#include "sqltablemodel.h"
#include "ui_mainwindow.h"
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
    budgetDB.setDatabaseName("budget");
    budgetDB.setHostName("mitchell");
    budgetDB.setPassword("password");
    bool ok = budgetDB.open();

    if (ok) {std::cout << "Databse open." << std::endl;}
    else {std::cout << "Databse not open." << std::endl;}

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
    sqlTableModel *model = new sqlTableModel();

    inputFile = new QFile("october_transactions.csv");
    currentDir.setCurrent("/Users/mitchellward/Development");
    if (inputFile->open(QIODevice::ReadOnly))
    {
        std::cout << "------------------------------------" << std::endl;
        std::cout << "File open." << std::endl;
        compiledCSV = readCSV();
    }
    std::cout << "Compiled CSV retrieved. Size: " << compiledCSV.size() << std::endl;
    std::cout << "------------------------------------" << std::endl;
     for (QList<QList<QString>>::iterator listEntries = compiledCSV.begin(); listEntries < compiledCSV.end(); listEntries++)
     {
        for (int i = 0; i < listEntries->size(); i++)
        {
            std::cout << "Value " << i << ": " << listEntries->at(i).toStdString() << std::endl;
        }
     }
     std::cout << "------------------------------------" << std::endl;


    budgetView->setModel(model);
    budgetView->show();
    }

QStringList MainWindow::readLine()
{
    std::cout << "Beginning to read line." << std::endl;
    QStringList values;
    if (!inputFile->atEnd())
    {
        QByteArray line = inputFile->readLine();
        // Get the line, retrieved in ByteArray form
        QList<QByteArray> valuesInBytes = line.split(',');
        // Split the line by commas, since its a CSV
        QList<QByteArray>::const_iterator fileIterator;
        for (fileIterator = valuesInBytes.begin(); fileIterator < valuesInBytes.end(); fileIterator++)
        {
            if (*fileIterator == " " || fileIterator->toStdString().empty() || fileIterator->isEmpty())
            {
                continue;
            }
            else
            {
                std::cout << "Value: " << fileIterator->toStdString() << std::endl;
                 values.append(*fileIterator);
                 std::cout << "Values size: " << values.size() << std::endl;
                 // For each value in the line, append them to a QList
            }

        }
    }
    return values;
}

QList<QList<QString>> MainWindow::readCSV()
{
    std::cout << "Beginning to read CSV." << std::endl;
    std::cout << "Read attempt." << std::endl;
    QStringList line = readLine();
    int lineSize = line.size();
    std::cout << "Read success." << std::endl;
    std::cout << "This line contains: " << line.size() << " items." << std::endl;

    QVector<QList<QString>> transactions;
    QStringList::iterator lineIterator;

    if (lineSize < 3) {line=readLine();}

    while(!inputFile->atEnd())
    {
        QList<QString> lineItem;
        for (lineIterator = line.begin(); lineIterator < line.end(); lineIterator++)
        {
            int columnNumber = lineIterator - line.begin();
            std::cout << "Column number: " << columnNumber << std::endl;
            std::cout << "Column value: " << lineIterator->toStdString() << std::endl;
            lineItem.append(*lineIterator);
            std::cout << "Line Item size: " << lineItem.size() << std::endl;
        }
        transactions.append(lineItem);
        std::cout << "------------------------" << std::endl;
        std::cout << "Reading next item." << std::endl;
        line = readLine();
    }

    return transactions;
}



MainWindow::~MainWindow()
{
    delete ui;
}



