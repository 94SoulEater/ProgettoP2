#include "proxymodel.h"

proxymodel::proxymodel(QObject *parent):
    QSortFilterProxyModel(parent), colonneNascoste(){
}

bool proxymodel::filterAcceptsColumn(int source_column, const QModelIndex&) const{
    if(colonneNascoste.contains(source_column)) return false;
    else return true;
}

bool proxymodel::filterAcceptsRow(int source_row, const QModelIndex &sourceParent) const{
    QModelIndex index = sourceModel()->index(source_row, colonnaRicerca, sourceParent);
    return (sourceModel()->data(index).toString().contains(filterRegExp()));
}

void proxymodel::setFiltroColonne(tipoutente _tipoUtente){
    colonneNascoste.clear();
    switch(_tipoUtente){
    case Utente:
        colonneNascoste.push(1);
        break;
    case Studente:
        break;
    case Professore:
        break;
    case Insegnante:
        break;
    case Tutor:
        break;
    }
    invalidateFilter();
    emit colonneModificate();
}

void proxymodel::setColonnaRicerca(int _colonnaRicerca){
    colonnaRicerca = _colonnaRicerca;
    invalidateFilter();
}
