#include "Model/ricerca.h"

string ricerca::getRivistaPubblicazione() const{
    return rivistaPubblicazione;
}

void ricerca::setRivistaPubblicazione(const string &value){
    rivistaPubblicazione = value;
}

string ricerca::getLink() const{
    return link;
}

void ricerca::setLink(const string &value){
    link = value;
}

string ricerca::getTitolo() const{
    return titolo;
}

void ricerca::setTitolo(const string &value){
    titolo = value;
}

string ricerca::getAutori() const{
    return autori;
}

void ricerca::setAutori(const string &value){
    autori = value;
}

int ricerca::getAnnoPubblicazione() const{
    return annoPubblicazione;
}

void ricerca::setAnnoPubblicazione(int value){
    annoPubblicazione = value;
}

bool ricerca::operator==(const ricerca &_ric) const{
    return (_ric.autori==autori && _ric.annoPubblicazione == annoPubblicazione && _ric.link==link && _ric.rivistaPubblicazione == rivistaPubblicazione && _ric.titolo==titolo);
}

bool ricerca::operator!=(const ricerca &_ric) const{
    return !(*this==_ric);
}

ricerca::ricerca(string _autori, string _titolo, string _link, string _rivistaPubblicazione, int _annoPubblicazione):autori(_autori), titolo(_titolo), link(_link), rivistaPubblicazione(_rivistaPubblicazione), annoPubblicazione(_annoPubblicazione){
}
