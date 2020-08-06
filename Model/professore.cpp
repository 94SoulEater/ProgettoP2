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

professore::professore(string _tipo, int _anniServizio):tipo(_tipo), anniServizio(_anniServizio), ricerche(){
}
