#ifndef CATEGORY_H
#define CATEGORY_H

#include <QObject>


class Category
{
public:
    Category();
    Category(QString newTitle) { title = newTitle; }
    bool operator==(const Category &rhs) const { return rhs.title == this->title; }
    inline QString getTitle() { return title; }
    inline void setTitle(QString newTitle) { title = newTitle; }
    inline QString getDescription() { return description; }
    inline void setDescription(QString desc) { description = desc; }
private:
    QString title, description;
};

#endif // CATEGORY_H
