#include "proxymodel.h"

proxymodel::proxymodel(QObject *parent):
    QSortFilterProxyModel(parent), colonneNascoste(){
}

bool proxymodel::filterAcceptsColumn(int source_column, const QModelIndex&) const{
    if(colonneNascoste.contains(source_column)) return false;
    else return true;
}

void proxymodel::setFiltroColonne(tipoutente _tipoUtente){
    switch(_tipoUtente){
    case Utente:
        colonneNascoste.clear();
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
}
