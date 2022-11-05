#ifndef ADDINCOMEBOX_H
#define ADDINCOMEBOX_H

#include <QDialog>

namespace Ui {
class addIncomeBox;
}

class AddIncomeBox : public QDialog {
    Q_OBJECT

public:
    explicit AddIncomeBox(QWidget *parent = nullptr);
    AddIncomeBox(QWidget *parent, QList<QString> cat, QList<QString> mem);
    void setCategoryData(QList<QString> categories);
    void setMemberData(QList<QString> members);
    ~AddIncomeBox();

signals:
    void newIncomeCreated(QList<QString>);
    void newIncomeNotCreated();

private:
    Ui::addIncomeBox *ui;
    void accept() override;
    void reset();
};

#endif // ADDINCOMEBOX_H
