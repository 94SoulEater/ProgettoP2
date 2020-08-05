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

void professore::setRicerche(const vector<ricerca> &value){
    ricerche = value;
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
