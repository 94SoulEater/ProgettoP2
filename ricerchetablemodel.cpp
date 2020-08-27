#include "ricerchetablemodel.h"

ricerchetablemodel::ricerchetablemodel(QObject *parent)
    : QAbstractTableModel(parent), listaRicerche(){
}

void ricerchetablemodel::setListaRicerche(contenitore<ricerca> _listaRicerche){
    beginInsertRows(QModelIndex(), 0, _listaRicerche.size()-1);
    listaRicerche = _listaRicerche;
    endInsertRows();
}

contenitore<ricerca>& ricerchetablemodel::getListaRicerche(){
    return listaRicerche;
}

ricerchetablemodel::ricerchetablemodel(contenitore<ricerca> _listaRicerche, QObject *parent)
    : QAbstractTableModel(parent){
    setListaRicerche(_listaRicerche);
}

int ricerchetablemodel::rowCount(const QModelIndex&) const{
    return listaRicerche.size();
}

int ricerchetablemodel::columnCount(const QModelIndex&) const{
    return 5;
}

QVariant ricerchetablemodel::data(const QModelIndex &index, int role) const{
    if (!index.isValid()) return QVariant();
    if (role == Qt::DisplayRole) {
        const ricerca ricercaTemp = listaRicerche.value(index.row());
        switch(index.column()){
        case 0: //Autori
            return QString::fromStdString(ricercaTemp.getAutori());
        case 1: //Titolo
            return QString::fromStdString(ricercaTemp.getTitolo());
        case 2: //Link
            return QString::fromStdString(ricercaTemp.getLink());
        case 3: //Rivista Pubblicazione
            return QString::fromStdString(ricercaTemp.getRivistaPubblicazione());
        case 4: //Anno pubblicazione
            return QString::number(ricercaTemp.getAnnoPubblicazione());
        default:
            return QVariant();
        }
    }
    return QVariant();
}

bool ricerchetablemodel::setData(const QModelIndex &index, const QVariant &value, int role){
    if (index.isValid() && role == Qt::EditRole) {
        int row = index.row();
        ricerca tmp = listaRicerche.value(row);

        switch(index.column()){
        case 0: //Autori
            tmp.setAutori(value.toString().toStdString());
            break;
        case 1: //Titolo
            tmp.setTitolo(value.toString().toStdString());
            break;
        case 2: //Link
            tmp.setLink(value.toString().toStdString());
            break;
        case 3: //Rivista
            tmp.setRivistaPubblicazione(value.toString().toStdString());
            break;
        case 4: //Anno
            tmp.setAnnoPubblicazione(value.toInt());
            break;
        }
        listaRicerche.replace(row, tmp);
        emit(dataChanged(index, index));
        return true;
    }
    return false;
}

QVariant ricerchetablemodel::headerData(int section, Qt::Orientation orientation, int role) const{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return QString("Autori");
        case 1:
            return QString("Titolo");
        case 2:
            return QString("Link");
        case 3:
            return QString("Rivista");
        case 4:
            return QString("Anno");
        }
    }
    return QVariant();
}
Qt::ItemFlags ricerchetablemodel::flags(const QModelIndex &index) const{
    if (!index.isValid())return Qt::ItemIsEnabled;
    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}
bool ricerchetablemodel::insertRows(int position, int rows, const QModelIndex &index){
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position + rows - 1);
    for (int row = 0; row < rows; ++row) {
        listaRicerche.push(ricerca());
    }
    endInsertRows();
    return true;
}

bool ricerchetablemodel::removeRows(int position, int rows, const QModelIndex &index){
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), position, position + rows - 1);
    for (int row = 0; row < rows; ++row) {
        listaRicerche.remove(position);
    }
    endRemoveRows();
    return true;
}

bool ricerchetablemodel::contains(const ricerca& _lez){
    return listaRicerche.contains(_lez);
}
