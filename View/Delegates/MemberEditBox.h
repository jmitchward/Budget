#ifndef MEMBEREDITBOX_H
#define MEMBEREDITBOX_H

#include <QStyledItemDelegate>
#include <QComboBox>
#include <QApplication>
#include <DTO/Member.h>

class MemberEditBox : public QStyledItemDelegate {
    Q_OBJECT
public:
    MemberEditBox();
    MemberEditBox(QObject *parent = 0);
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *parent, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    inline void setData(QList<QString> mbr) {
        for ( auto title : mbr ) {
            members.append(title);
        }
    }

private:
    QList<QString> members;
};

#endif // MEMBEREDITBOX_H
