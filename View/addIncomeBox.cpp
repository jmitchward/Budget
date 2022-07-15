#include "addIncomeBox.h"
#include "ui_addIncomeBox.h"

addIncomeBox::addIncomeBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addIncomeBox)
{
    ui->setupUi(this);
}

addIncomeBox::~addIncomeBox()
{
    delete ui;
}
