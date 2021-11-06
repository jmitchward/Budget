#ifndef DATASTRUCTS_H
#define DATASTRUCTS_H

#include <QObject>
#include <QSet>

template <class T>
class budgetItem : public QObject {
public:
    QList<T> getValues() {
        return itemValues.values();
    }
    void addValues(T value) {
        if (!itemValues.contains(value)) {
            itemValues.insert(value);
        }
    }
    bool checkValues(T value) {
        return itemValues.contains(value);
    }
    QSet<T> itemValues;
};


class Category : public budgetItem<QString> {
    Q_OBJECT
    void init();
};

class Members : public budgetItem<QString> {
    Q_OBJECT
    void init();
};






#endif // DATASTRUCTS_H