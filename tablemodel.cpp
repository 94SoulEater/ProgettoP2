#include "tablemodel.h"

tablemodel::tablemodel(QObject *parent)
    : QAbstractTableModel(parent){
}
//-------------------------------------------------------
int tablemodel::rowCount(const QModelIndex & /*parent*/) const{
    return 2;
}
//-------------------------------------------------------
int tablemodel::columnCount(const QModelIndex & /*parent*/) const{
    return 3;
}
//-------------------------------------------------------
QVariant tablemodel::data(const QModelIndex &index, int role) const{
    if (role == Qt::DisplayRole) {
        return QString("Row%1, Column%2")
                .arg(index.row() + 1)
                .arg(index.column() +1);
    }
    return QVariant();
}

QVariant tablemodel::headerData(int section, Qt::Orientation orientation, int role) const{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return QString("first");
        case 1:
            return QString("second");
        case 2:
            return QString("third");
        }
    }
    return QVariant();
}