#include "comboboxdelegate.h"
comboboxdelegate::comboboxdelegate(QObject *parent)
    : QStyledItemDelegate(parent){
}

comboboxdelegate::~comboboxdelegate(){
}


QWidget* comboboxdelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,const QModelIndex &index)const{
    QStringList values;
    values << "Enabled" << "Disabled";

    QComboBox* comboBox = new QComboBox(parent);
    comboBox->addItems(values);
    return comboBox;
}


void comboboxdelegate::setEditorData(QWidget *editor, const QModelIndex &index) const{
    QComboBox *cb = qobject_cast<QComboBox *>(editor);
    Q_ASSERT(cb);
    const QString currentText = index.data(Qt::EditRole).toString();
    const int cbIndex = cb->findText(currentText);
    if (cbIndex >= 0)
       cb->setCurrentIndex(cbIndex);
}


void comboboxdelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const{
    QComboBox *cb = qobject_cast<QComboBox *>(editor);
    Q_ASSERT(cb);
    model->setData(index, cb->currentText(), Qt::EditRole);
}

void comboboxdelegate::updateEditorGeometry(QWidget *editor,
                                           const QStyleOptionViewItem &option,
                                           const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}
