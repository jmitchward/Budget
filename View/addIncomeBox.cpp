#include "addIncomeBox.h"
#include "ui_addIncomeBox.h"

AddIncomeBox::AddIncomeBox(QWidget *parent) : QDialog(parent), ui(new Ui::addIncomeBox) {
    ui->setupUi(this);
}

AddIncomeBox::~AddIncomeBox() {
    delete ui;
}
