#include "Model/lezione.h"

string lezione::getMateria() const{
    return materia;
}

void lezione::setMateria(const string &value){
    materia = value;
}

string lezione::getCorsoLaurea() const{
    return corsoLaurea;
}

void lezione::setCorsoLaurea(const string &value){
    corsoLaurea = value;
}

string lezione::getStanza() const{
    return stanza;
}

void lezione::setStanza(const string &value){
    stanza = value;
}

int lezione::getCrediti() const{
    return crediti;
}

void lezione::setCrediti(int value){
    crediti = value;
}

lezione::lezione(string _materia, string _corsolaurea, string _stanza, int _crediti):materia(_materia), corsoLaurea(_corsolaurea), stanza(_stanza), crediti(_crediti){
}
