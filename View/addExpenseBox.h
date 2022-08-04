#ifndef ADDEXPENSEBOX_H
#define ADDEXPENSEBOX_H

#include <QDialog>
#include "View/categoryEditBox.h"

namespace Ui {
class AddExpenseBox;
}

class AddExpenseBox : public QDialog {
    Q_OBJECT

public:
    explicit AddExpenseBox(QWidget *parent = nullptr);
    void setCategoryData(QList<QString>);
    ~AddExpenseBox();

private:
    Ui::AddExpenseBox *ui;
    CategoryEditBox *categoryEdit;
    void accept() override;
};

#endif // ADDEXPENSEBOX_H
