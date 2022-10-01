#include "AddIncomeBox.h"
#include "ui_addIncomeBox.h"

AddIncomeBox::AddIncomeBox(QWidget *parent) : QDialog(parent), ui(new Ui::addIncomeBox) {
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
}

AddIncomeBox::AddIncomeBox(QWidget *parent, QList<QString> cat, QList<QString> mem ) : QDialog(parent), ui(new Ui::addIncomeBox) {
    ui->setupUi(this);

    ui->categoryBox->clear();
    ui->categoryBox->addItems(cat);
    ui->categoryBox->setMaxVisibleItems(5);

    ui->memberBox->clear();
    ui->memberBox->addItems(mem);
    ui->memberBox->setMaxVisibleItems(5);
}

void AddIncomeBox::setCategoryData(QList<QString> categories) {
    ui->categoryBox->clear();
    ui->categoryBox->addItems(categories);
}

void AddIncomeBox::setMemberData(QList<QString> members) {
    ui->memberBox->clear();
    ui->memberBox->addItems(members);
}

AddIncomeBox::~AddIncomeBox() {
    delete ui;
}

void AddIncomeBox::accept() {

    QList<QString> returnValues;
    bool validValues = true;

    // Date
    returnValues.append(ui->dateEdit->date().toString());

    // Amount
    if ( ui->amountBox->value() == 0 ) {
        Q_EMIT newIncomeNotCreated();
        validValues = false;
        qDebug() << "Rejected.";
        reset();
        done(QDialog::Rejected);
    }
    else {
        returnValues.append(QString::number(ui->amountBox->value()));
    }

    // Type
    returnValues.append(ui->typeBox->currentText());

    // Description
    returnValues.append(ui->descEdit->text());

    // Category
    if ( ui->categoryBox->currentText() == ui->categoryBox->placeholderText() ) {
        Q_EMIT newIncomeNotCreated();
        validValues = false;
        qDebug() << "Rejected.";
        reset();
        done(QDialog::Rejected);
    }
    else {
        returnValues.append(ui->categoryBox->currentText());
    }

    // Member
    if ( ui->memberBox->currentText() == ui->memberBox->placeholderText() ) {
        Q_EMIT newIncomeNotCreated();
        validValues = false;
        qDebug() << "Rejected.";
        reset();
        done(QDialog::Rejected);
    }
    else {
        returnValues.append(ui->memberBox->currentText());
    }

    if ( validValues ) {
        Q_EMIT newIncomeCreated(returnValues);
        qDebug() << "Accepted.";
        reset();
        done(QDialog::Accepted);
    }
}

void AddIncomeBox::reset() {
    ui->dateEdit->setDate(QDate::currentDate());
    ui->amountBox->setValue(0.00);
    ui->typeBox->setCurrentText(ui->typeBox->placeholderText());
    ui->descEdit->setText(QString(""));
    ui->categoryBox->setCurrentText(ui->categoryBox->placeholderText());
    ui->memberBox->setCurrentText(ui->memberBox->placeholderText());
}
