#ifndef CATEGORYEDITBOX_H
#define CATEGORYEDITBOX_H

#include <QStyledItemDelegate>
#include <QObject>
#include <QApplication>
#include <QComboBox>
#include <DTO/category.h>

class CategoryEditBox : public QStyledItemDelegate
{
    Q_OBJECT
public:
    CategoryEditBox(QObject *parent = 0);
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *parent, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    inline void setData(QList<QString> cat) {
        for ( auto title : cat ) {
            categories.append(title);
        }
    }

private:
    QList<QString> categories;
};

#endif // CATEGORYEDITBOX_H
