#ifndef ADDEXPENSEBOX_H
#define ADDEXPENSEBOX_H

#include <QDialog>

namespace Ui {
class AddExpenseBox;
}

class AddExpenseBox : public QDialog {
    Q_OBJECT

public:
    explicit AddExpenseBox(QWidget *parent = nullptr);
    AddExpenseBox(QWidget *parent, QList<QString> cat, QList<QString> mem, QList<QString> strs);
    void setCategoryData(QList<QString>);
    void setMemberData(QList<QString>);
    ~AddExpenseBox();

signals:
    void newExpenseCreated(QList<QString>);
    void newExpenseNotCreated();

private:
    Ui::AddExpenseBox *ui;
    void accept() override;
    void reset();
};

#endif // ADDEXPENSEBOX_H
