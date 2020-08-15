#include "tablemodel.h"

tablemodel::tablemodel(QObject *parent)
    : QAbstractTableModel(parent), listaUtenti(){
}
//-------------------------------------------------------
int tablemodel::rowCount(const QModelIndex & /*parent*/) const{
    return listaUtenti.size();
}
//-------------------------------------------------------
int tablemodel::columnCount(const QModelIndex & /*parent*/) const{
    return 5;
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
            return QString("Codice Fiscale");
        case 1:
            return QString("Nome");
        case 2:
            return QString("Cognome");
        case 3:
            return QString("Data di Nascita");
        case 4:
            return QString("Tipo Utente");
        }
    }
    return QVariant();
}

Qt::ItemFlags tablemodel::flags(const QModelIndex &index) const{
}

bool tablemodel::setData(const QModelIndex &index, const QVariant &value, int role){
}

bool tablemodel::insertRow(int row, const QModelIndex &parent){
}

bool tablemodel::removeRow(int row, const QModelIndex &parent){
}


