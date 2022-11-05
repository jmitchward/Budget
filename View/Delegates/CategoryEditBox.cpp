#include "CategoryEditBox.h"

CategoryEditBox::CategoryEditBox(QObject *parent) : QStyledItemDelegate(parent) {
    this->categories.clear();
}

QWidget *CategoryEditBox::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    QComboBox *editor = new QComboBox(parent);
    if ( !categories.isEmpty() ) {
        for ( auto category : categories ) {
            editor->addItem(category);
        }
    }
    return editor;
}

void CategoryEditBox::setEditorData(QWidget *editor, const QModelIndex &index) const {
    QComboBox *comboBox = static_cast<QComboBox *>(editor);
    QString value = index.model()->data(index, Qt::DisplayRole).toString();
    comboBox->setCurrentText(value);
    comboBox->showPopup();
}

void CategoryEditBox::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const {
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    model->setData(index, comboBox->currentText(), Qt::EditRole);
    model->submit();
}

void CategoryEditBox::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    editor->setGeometry(option.rect);
}

void CategoryEditBox::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    QStyleOptionViewItem myOption = option;
    QString cat = index.data(Qt::DisplayRole).toString();
    myOption.text = cat;
    QApplication::style()->drawControl(QStyle::CE_ItemViewItem, &myOption, painter);
}

