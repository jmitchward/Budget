#ifndef DATASTRUCTS_H
#define DATASTRUCTS_H

#include <QObject>
#include <QSet>

template <class T>
class budgetItem {
    Q_OBJECT
public:
    budgetItem();
    QList<T> getValues();
    void addValues(T);
    bool checkValues(T);
private:
    QSet<T> itemValues;
};


class Category : budgetItem<QString> {
    Q_OBJECT

public:
    Category();
    QList<QString> getCategories();
    void addCategory(QString);
    bool checkCategory(QString);

private:
    QSet<QString> expenseCategories;
};

class Members {
    Members();
    QList<QString> getMembers();
    void addMember(QString)
};






#endif // DATASTRUCTS_H
