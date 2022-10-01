#ifndef STORE_H
#define STORE_H

#include <QObject>

class Store {

public:
    Store();
    Store(QString storeName) { name = storeName; }
    bool operator==(const Store &rhs) const { return rhs.name == name; }
    bool operator<(const Store &rhs) const { return rhs.name == name; }
    inline QString getStoreName() { return name; }
    inline void setStoreName(QString storeName) { name = storeName; }
    inline QString getDescription() { return description; }
    inline void setDescription(QString desc) { description = desc; }
    inline QString getCategory() { return category; }
    inline void setCategory(QString cat) { category = cat; }
private:
    QString name, description, category;
};

#endif // STORE_H
