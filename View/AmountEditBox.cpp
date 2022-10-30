#include "AmountEditBox.h"

AmountEditBox::AmountEditBox(QObject* parent ) : QStyledItemDelegate(parent) {}

void AmountEditBox::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    QString amount;
    double tableValue = index.model()->data(index, Qt::DisplayRole).toDouble();
    amount = QString("$%1").arg(tableValue, 4, 'f', 2);
//    amount.setNum(index.model()->data(index, Qt::DisplayRole).toDouble(), 'f', 4);
    painter->drawText( option.rect , Qt::AlignVCenter , amount );
}
