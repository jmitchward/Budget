#ifndef AMOUNTEDITBOX_H
#define AMOUNTEDITBOX_H

#include <QStyledItemDelegate>
#include <QApplication>
#include <QPainter>

class AmountEditBox : public QStyledItemDelegate {
    Q_OBJECT

public:
    AmountEditBox(QObject* parent = 0);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // AMOUNTEDITBOX_H
