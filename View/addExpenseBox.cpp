#include "addExpenseBox.h"
#include "ui_addExpenseBox.h"

AddExpenseBox::AddExpenseBox(QWidget *parent) : QDialog(parent),  ui(new Ui::AddExpenseBox) {
    ui->setupUi(this);
}

void AddExpenseBox::setCategoryData(QList<QString> categories) {
    categoryEdit = new CategoryEditBox(this);
    categoryEdit->setData(categories);
    ui->categoryBox->setItemDelegate(categoryEdit);
}


AddExpenseBox::~AddExpenseBox() {
    delete ui;
}

void AddExpenseBox::accept() {

}
