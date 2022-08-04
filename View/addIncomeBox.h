#ifndef ADDINCOMEBOX_H
#define ADDINCOMEBOX_H

#include <QDialog>

namespace Ui {
class addIncomeBox;
}

class AddIncomeBox : public QDialog
{
    Q_OBJECT

public:
    explicit AddIncomeBox(QWidget *parent = nullptr);
    ~AddIncomeBox();

private:
    Ui::addIncomeBox *ui;
};

#endif // ADDINCOMEBOX_H
