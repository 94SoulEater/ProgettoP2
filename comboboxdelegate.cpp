#include "comboboxdelegate.h"
comboboxdelegate::comboboxdelegate(QObject *parent)
    : QStyledItemDelegate(parent){
}

comboboxdelegate::~comboboxdelegate(){
}


QWidget* comboboxdelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,const QModelIndex &index)const{
    Q_UNUSED(option);
    Q_UNUSED(index);
    QComboBox* comboBox = new QComboBox(parent);
    return comboBox;
}


void comboboxdelegate::setEditorData(QWidget *editor, const QModelIndex &index) const{
    QComboBox *cb = qobject_cast<QComboBox *>(editor);
    cb->clear();
    Q_ASSERT(cb);
    QStringList tmp = index.model()->data(index, Qt::DisplayRole).toStringList();
    cb->addItems(tmp);
}

void comboboxdelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const{
    Q_UNUSED(editor);
    Q_UNUSED(model);
    Q_UNUSED(index);
}

void comboboxdelegate::updateEditorGeometry(QWidget *editor,
                                            const QStyleOptionViewItem &option,
                                            const QModelIndex &/* index */) const{
    editor->setGeometry(option.rect);
}
