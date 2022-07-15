#ifndef ADDINCOMEBOX_H
#define ADDINCOMEBOX_H

#include <QDialog>

namespace Ui {
class addIncomeBox;
}

class addIncomeBox : public QDialog
{
    Q_OBJECT

public:
    explicit addIncomeBox(QWidget *parent = nullptr);
    ~addIncomeBox();

private:
    Ui::addIncomeBox *ui;
};

#endif // ADDINCOMEBOX_H
