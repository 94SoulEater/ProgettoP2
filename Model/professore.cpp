#include "Model/professore.h"

tipoutente professore::getTipoUtente() const{
    return Professore;
}

string professore::getTipo() const{
    return tipo;
}

void professore::setTipo(const string &value){
    tipo = value;
}

contenitore<ricerca> professore::getRicerche() const{
    return ricerche;
}

void professore::setRicerche(const contenitore<ricerca> &_listaRicerche){
    ricerche.clear();
    ricerche = _listaRicerche;
}

void professore::addRicerca(const ricerca &_ric){
    ricerche.push(_ric);
}

void professore::removeRicerca(const ricerca &_ric){
    ricerche.remove(_ric);
}

int professore::getAnniServizio() const
{
    return anniServizio;
}

void professore::setAnniServizio(int value)
{
    anniServizio = value;
}

professore::professore(string _nome, string _cognome, string _codiceFiscale, string _telefono, string _email, int _giornoNascita, int _meseNascita, int _annoNascita, string _regione, string _comune, string _via, string _cap, string _numeroCivico, string _tipo, int _anniServizio): utente(_nome, _cognome, _codiceFiscale, _telefono, _email, _giornoNascita, _meseNascita, _annoNascita, _regione, _comune, _via, _cap, _numeroCivico), tipo(_tipo), anniServizio(_anniServizio), ricerche(){
}

professore* professore::clone() const{
    return new professore(*this);
}
