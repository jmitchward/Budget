#include "MemberEditBox.h"

MemberEditBox::MemberEditBox(QObject *parent) : QStyledItemDelegate(parent) {
    this->members.clear();
}

QWidget *MemberEditBox::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    QComboBox *editor = new QComboBox(parent);
    if ( !members.isEmpty() ) {
        for ( auto member : members ) {
            editor->addItem(member);
        }
    }
    return editor;
}

void MemberEditBox::setEditorData(QWidget *editor, const QModelIndex &index) const {
    QComboBox *comboBox = static_cast<QComboBox *>(editor);
    QString value = index.model()->data(index, Qt::DisplayRole).toString();
    comboBox->setCurrentText(value);
    comboBox->showPopup();
}

void MemberEditBox::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const {
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    model->setData(index, comboBox->currentText(), Qt::EditRole);
    model->submit();
}

void MemberEditBox::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    editor->setGeometry(option.rect);
}

void MemberEditBox::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    QStyleOptionViewItem myOption = option;
    QString cat = index.data(Qt::DisplayRole).toString();
    myOption.text = cat;
    QApplication::style()->drawControl(QStyle::CE_ItemViewItem, &myOption, painter);
}
