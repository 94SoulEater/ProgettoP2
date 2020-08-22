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
    QModelIndex tipoUtente = sourceModel()->index(source_row, 11, sourceParent);
    bool filtroUtente;
    switch(filtroTipoUtente){
    case Utente:
        filtroUtente = true;
        break;
    case Studente:
        filtroUtente = sourceModel()->data(tipoUtente).toString().contains(QString::fromStdString("Studente"));
        filtroUtente = filtroUtente || sourceModel()->data(tipoUtente).toString().contains(QString::fromStdString("Tutor"));
        break;
    case Tutor:
        filtroUtente = sourceModel()->data(tipoUtente).toString().contains(QString::fromStdString("Tutor"));
        break;
    case Insegnante:
        filtroUtente = sourceModel()->data(tipoUtente).toString().contains(QString::fromStdString("Tutor"));
        filtroUtente = filtroUtente || sourceModel()->data(tipoUtente).toString().contains(QString::fromStdString("Professore"));
        break;
    case Professore:
        filtroUtente = sourceModel()->data(tipoUtente).toString().contains(QString::fromStdString("Professore"));
        break;
    }
    return (filtroUtente && sourceModel()->data(index).toString().contains(filterRegExp()));
}

bool proxymodel::isColonnaNascosta(int _col){
    return colonneNascoste.contains(_col);
}

//Mostra o nasconde colonne in base al tipo di utente da visualizzare
void proxymodel::setFiltroColonne(tipoutente _tipoUtente){
    filtroTipoUtente = _tipoUtente;
    colonneNascoste.clear();
    switch(_tipoUtente){
    case Utente:
        colonneNascoste.push(1);
        colonneNascoste.push(7);
        colonneNascoste.push(8);
        colonneNascoste.push(9);
        colonneNascoste.push(10);
        colonneNascoste.push(12);
        colonneNascoste.push(13);
        break;
    case Studente:
        colonneNascoste.push(0);
        colonneNascoste.push(12);
        colonneNascoste.push(13);
        break;
    case Professore:
        colonneNascoste.push(1);
        colonneNascoste.push(7);
        colonneNascoste.push(8);
        colonneNascoste.push(9);
        colonneNascoste.push(10);
        colonneNascoste.push(11);
        break;
    case Insegnante:
        colonneNascoste.push(1);
        colonneNascoste.push(7);
        colonneNascoste.push(8);
        colonneNascoste.push(9);
        colonneNascoste.push(10);
        colonneNascoste.push(12);
        colonneNascoste.push(13);
        break;
    case Tutor:
        colonneNascoste.push(11);
        colonneNascoste.push(12);
        colonneNascoste.push(13);
        break;
    }
    invalidateFilter();
    emit colonneModificate();
}

//Imposta la colonna per la ricerca testuale
void proxymodel::setColonnaRicerca(int _colonnaRicerca){
    colonnaRicerca = _colonnaRicerca;
    invalidateFilter();
}
