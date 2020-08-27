#include "Model/lezione.h"

string lezione::getMateria() const{
    return materia;
}

string lezione::fromDayOfWeek(DayOfWeek _day){
    switch(_day){
    case DayOfWeek::Monday:
        return "Lunedì";
    case DayOfWeek::Tuesday:
        return "Martedì";
    case DayOfWeek::Wednesday:
        return "Mercoledì";
    case DayOfWeek::Thursday:
        return "Giovedì";
    case DayOfWeek::Friday:
        return "Venerdì";
    case DayOfWeek::Saturday:
        return "Sabato";
    case DayOfWeek::Sunday:
        return "Domenica";
    }
}

DayOfWeek lezione::toDayOfWeek(const string &_day){
    if(_day == "Lunedì") return DayOfWeek::Monday;
    if(_day == "Martedì") return DayOfWeek::Tuesday;
    if(_day == "Mercoledì") return DayOfWeek::Wednesday;
    if(_day == "Giovedì") return DayOfWeek::Thursday;
    if(_day == "Venerdì") return DayOfWeek::Friday;
    if(_day == "Sabato") return DayOfWeek::Saturday;
    if(_day == "Domenica") return DayOfWeek::Sunday;
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

contenitore<giornoLezione> lezione::getGiorniLezione(){
    return giorniLezione;
}
QStringList lezione::getGiorniLezioneStringList()const{
    QStringList temp;
    QString tempstr;
    QString oraIniz;
    QString oraFin;
    QString giornoSett;
    for(contenitore<giornoLezione>::iteratore_const it = giorniLezione.begin(); it != giorniLezione.end(); ++it){
        oraIniz = QString::fromStdString((*it).oraInizio);
        oraFin = QString::fromStdString((*it).oraFine);
        giornoSett = QString::fromStdString(fromDayOfWeek((*it).giornoSettimana));
        tempstr.append(oraIniz).append(" - ").append(oraFin).append("  ").append(giornoSett);
        temp << tempstr;
        tempstr.clear();
    }
    return temp;
}
void lezione::setGiorniLezione(const QStringList &_orari){

}

void lezione::addGiornoLezione(string _inizio, string _fine, DayOfWeek _giorno){
    giornoLezione g = {_inizio, _fine, _giorno};
    giorniLezione.push(g);
}

void lezione::removeGiornoLezione(string _inizio, string _fine, DayOfWeek _giorno){
    giornoLezione g = {_inizio, _fine, _giorno};
    giorniLezione.remove(g);
}

bool lezione::operator==(const lezione &_lez) const{
    if(!(materia==_lez.materia && stanza==_lez.stanza && crediti==_lez.crediti && corsoLaurea==_lez.corsoLaurea))return false;
    return _lez.giorniLezione == giorniLezione;
}

bool lezione::operator!=(const lezione &_lez) const{
    return !(*this==_lez);
}

lezione::lezione(string _materia, string _corsolaurea, string _stanza, int _crediti):materia(_materia), corsoLaurea(_corsolaurea), stanza(_stanza), crediti(_crediti){
}
