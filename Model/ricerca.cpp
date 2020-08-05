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

QDate ricerca::getDataPubblicazione() const{
    return dataPubblicazione;
}

void ricerca::setDataPubblicazione(const QDate &value){
    dataPubblicazione = value;
}

ricerca::ricerca(string _autori, string _titolo, string _link, string _rivistaPubblicazione, int _giornoPubblicazione, int _mesePubblicazione, int _annoPubblicazione):autori(_autori), titolo(_titolo), link(_link), rivistaPubblicazione(_rivistaPubblicazione), dataPubblicazione(_annoPubblicazione, _mesePubblicazione, _giornoPubblicazione){
}
