#include "Model/professore.h"

string professore::getTipo() const{
    return tipo;
}

void professore::setTipo(const string &value){
    tipo = value;
}

vector<ricerca> professore::getRicerche() const{
    return ricerche;
}

void professore::addRicerca(const ricerca &_ric){
    ricerche.push_back(_ric);
}

void professore::removeRicerca(const ricerca &_ric){
    ricerche.erase(std::remove(ricerche.begin(), ricerche.end(), _ric), ricerche.end());
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
