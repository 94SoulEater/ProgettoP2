#include "proxymodel.h"

proxymodel::proxymodel(QObject *parent):
    QSortFilterProxyModel(parent), colonneNascoste(), filtroTipoUtente(Utente){
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
    case Utente: //Mostra tutti gli utenti
        filtroUtente = true;
        break;
    case Studente: //Mostra studenti e tutor
        filtroUtente = sourceModel()->data(tipoUtente).toString().contains(QString::fromStdString("Studente"));
        filtroUtente = filtroUtente || sourceModel()->data(tipoUtente).toString().contains(QString::fromStdString("Tutor"));
        break;
    case Tutor: //Mostra solo tutor
        filtroUtente = sourceModel()->data(tipoUtente).toString().contains(QString::fromStdString("Tutor"));
        break;
    case Insegnante: //Mostra professori e tutor
        filtroUtente = sourceModel()->data(tipoUtente).toString().contains(QString::fromStdString("Tutor"));
        filtroUtente = filtroUtente || sourceModel()->data(tipoUtente).toString().contains(QString::fromStdString("Professore"));
        break;
    case Professore: //Mostra solo professori
        filtroUtente = sourceModel()->data(tipoUtente).toString().contains(QString::fromStdString("Professore"));
        break;
    }
    //Se l'utente appartiene al tipo selezionato e contiene la stringa cercata viene mostrato
    return (filtroUtente && sourceModel()->data(index).toString().contains(filterRegExp()));
}

bool proxymodel::isColonnaNascosta(int _col){
    return colonneNascoste.contains(_col);
}

//Mostra o nasconde colonne in base al tipo di utente da visualizzare
void proxymodel::setFiltroColonne(tipoutente _tipoUtente){
    filtroTipoUtente = _tipoUtente;
    colonneNascoste.clear();
    colonneNascoste.push(14); //Indirizzo nascosto
    colonneNascoste.push(15); //per tutti gli utenti
    colonneNascoste.push(16); //occupa troppo spazio
    colonneNascoste.push(17);
    colonneNascoste.push(18);
    colonneNascoste.push(19);
    if(_tipoUtente != Studente && _tipoUtente != Tutor){
        colonneNascoste.push(1); //Matricola
        colonneNascoste.push(7); //Corso
        colonneNascoste.push(8); //Laurea
        colonneNascoste.push(9); //Anno
        colonneNascoste.push(10);//Anni fuori corso
    }
    if(_tipoUtente != Professore){
        colonneNascoste.push(12); //Tipo professore
        colonneNascoste.push(13); //Anni di servizio
    }
    if(_tipoUtente == Professore || _tipoUtente == Tutor){
        colonneNascoste.push(11); //Tipo utente
    }
    if(_tipoUtente == Studente) colonneNascoste.push(0); //CodiceFiscale

    invalidateFilter();
    emit colonneModificate();
}

//Imposta la colonna per la ricerca testuale
void proxymodel::setColonnaRicerca(int _colonnaRicerca){
    colonnaRicerca = _colonnaRicerca;
    invalidateFilter();
}
