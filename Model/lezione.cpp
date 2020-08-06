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

vector<giornoLezione> lezione::getGiorniLezione() const{
    return giorniLezione;
}

//YET TO TEST, COULD BREAK EVERYTHING
void lezione::addGiornoLezione(QTime _inizio, QTime _fine, string _giorno){
    giornoLezione g = {_inizio, _fine, _giorno};
    giorniLezione.push_back(g);
}

void lezione::removeGiornoLezione(QTime _inizio, QTime _fine, string _giorno){
    giornoLezione g = {_inizio, _fine, _giorno};
    giorniLezione.erase(std::remove(giorniLezione.begin(), giorniLezione.end(), g), giorniLezione.end());
}

bool lezione::operator==(const lezione &_lez) const{
    if(!(materia==_lez.materia && stanza==_lez.stanza && crediti==_lez.crediti && corsoLaurea==_lez.corsoLaurea))return false;
    return std::equal(_lez.giorniLezione.begin(), _lez.giorniLezione.end(), giorniLezione.begin());
}

lezione::lezione(string _materia, string _corsolaurea, string _stanza, int _crediti):materia(_materia), corsoLaurea(_corsolaurea), stanza(_stanza), crediti(_crediti){
}
