#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);
    dataController = new DataController();
    ui->budgetView->setModel(dataController->getModel());
    dataController->requestTransactions();
    ui->budgetView->setColumnHidden(0, true);
    ui->budgetView->resizeColumnsToContents();

    statsTab = new ViewStats();
    ui->mainPanelWidget->addWidget(statsTab);
    statsTab->setData(dataController->getTransactions());

    initMenu();

    ui->mainPanelWidget->setCurrentWidget(ui->budgetViewWidget);

    amountEdit = new AmountEditBox(this);
    ui->budgetView->setItemDelegateForColumn(2, amountEdit);

    categoryEdit = new CategoryEditBox(this);
    categoryEdit->setData(dataController->getCategoriesStr());
    ui->budgetView->setItemDelegateForColumn(5, categoryEdit);

    memberEdit = new MemberEditBox(this);
    memberEdit->setData(dataController->getMembersStr());
    ui->budgetView->setItemDelegateForColumn(7, memberEdit);

    incomeBox = new AddIncomeBox(this, dataController->getCategoriesStr(), dataController->getMembersStr());
    connect(incomeBox, &AddIncomeBox::newIncomeCreated, dataController, &DataController::addNewIncome);
    connect(incomeBox, &AddIncomeBox::newIncomeNotCreated, dataController, &DataController::newIncomeError);

    expenseBox = new AddExpenseBox(this, dataController->getCategoriesStr(), dataController->getMembersStr(), dataController->getStoresStr());
    connect(expenseBox, &AddExpenseBox::newExpenseCreated, dataController, &DataController::addNewExpense);
    connect(expenseBox, &AddExpenseBox::newExpenseNotCreated, dataController, &DataController::newExpenseError);
}

void MainWindow::initMenu() {

    connect(ui->viewStats, &QAbstractButton::clicked,       this,   [=] {
                                                                        ui->mainPanelWidget->setWindowTitle(QString("Stats - Total"));
                                                                        statsTab->refreshData(dataController->getTransactions());
                                                                        ui->mainPanelWidget->setCurrentWidget(statsTab);});

    connect(ui->viewExpenses, &QAbstractButton::clicked,    this,   [=] {
                                                                        ui->mainPanelWidget->setWindowTitle(QString("Expenses"));
                                                                        ui->mainPanelWidget->setCurrentWidget(ui->budgetViewWidget);
                                                                        dataController->requestTransactions();
                                                                        ui->budgetView->setColumnHidden(0, true);
                                                                        ui->budgetView->resizeColumnsToContents();});

    connect(ui->viewIncome, &QAbstractButton::clicked,      this,   [=] {
                                                                        ui->mainPanelWidget->setCurrentWidget(ui->budgetViewWidget);
                                                                        dataController->requestEarnings();
                                                                        ui->budgetView->setColumnHidden(0, true);
                                                                        ui->budgetView->resizeColumnsToContents();});

    connect(ui->addIncome, &QAbstractButton::clicked,       this,   [=] {
                                                                        incomeBox->open();});

    connect(ui->addExpense, &QAbstractButton::clicked,      this,   [=] {
                                                                        expenseBox->open();});
}

MainWindow::~MainWindow() {
    delete ui;
}




