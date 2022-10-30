#include "AddExpenseBox.h"
#include "ui_AddExpenseBox.h"

AddExpenseBox::AddExpenseBox(QWidget *parent) : QDialog(parent),  ui(new Ui::AddExpenseBox) {
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
}

AddExpenseBox::AddExpenseBox(QWidget *parent, QList<QString> cat, QList<QString> mem, QList<QString> strs ) : QDialog(parent), ui(new Ui::AddExpenseBox) {
    ui->setupUi(this);

    ui->categoryBox->clear();
    ui->categoryBox->addItems(cat);
    ui->categoryBox->setMaxVisibleItems(5);

    ui->memberBox->clear();
    ui->memberBox->addItems(mem);
    ui->memberBox->setMaxVisibleItems(5);

    ui->storeBox->clear();
    ui->storeBox->addItems(strs);
    ui->storeBox->setMaxVisibleItems(5);
}

void AddExpenseBox::setCategoryData(QList<QString> categories) {
    ui->categoryBox->clear();
    ui->categoryBox->addItems(categories);
}

void AddExpenseBox::setMemberData(QList<QString> members) {
    ui->memberBox->clear();
    ui->memberBox->addItems(members);
}


AddExpenseBox::~AddExpenseBox() {
    delete ui;
}

void AddExpenseBox::accept() {

    QList<QString> returnValues;
    bool validValues = true;

    // Date
    returnValues.append(ui->dateEdit->date().toString());

    // Amount
    if ( ui->amountBox->value() == 0 ) {
        Q_EMIT newExpenseNotCreated();
        validValues = false;
        qDebug() << "Rejected.";
        reset();
        done(QDialog::Rejected);
    }
    else {
        returnValues.append(QString::number(ui->amountBox->value()));
    }

    // Store
    returnValues.append(ui->storeBox->currentText());

    // Description
    returnValues.append(ui->descEdit->text());

    // Category
    if ( ui->categoryBox->currentText() == ui->categoryBox->placeholderText() ) {
        Q_EMIT newExpenseNotCreated();
        validValues = false;
        qDebug() << "Rejected.";
        reset();
        done(QDialog::Rejected);
    }
    else {
        returnValues.append(ui->categoryBox->currentText());
    }

    // Shared
    returnValues.append(QString::number(ui->shareBox->isChecked()));

    // Member
    if ( ui->memberBox->currentText() == ui->memberBox->placeholderText() ) {
        Q_EMIT newExpenseNotCreated();
        validValues = false;
        qDebug() << "Rejected.";
        reset();
        done(QDialog::Rejected);
    }
    else {
        returnValues.append(ui->memberBox->currentText());
    }

    if ( validValues ) {
        Q_EMIT newExpenseCreated(returnValues);
        qDebug() << "Accepted.";
        reset();
        done(QDialog::Accepted);
    }
}

void AddExpenseBox::reset() {
    ui->dateEdit->setDate(QDate::currentDate());
    ui->amountBox->setValue(0.00);
    ui->descEdit->setText(QString(""));
    ui->categoryBox->setCurrentText(ui->categoryBox->placeholderText());
    ui->shareBox->setCheckState(Qt::Unchecked);
    ui->memberBox->setCurrentText(ui->memberBox->placeholderText());
}
