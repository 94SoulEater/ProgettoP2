#include "studente.h"

using std::string;

tipoutente studente::getTipoUtente() const{
    return Studente;
}

int studente::getMatricola() const{
    return matricola;
}

void studente::setMatricola(int value){
    matricola = value;
}

string studente::getLaurea() const{
    switch(laurea){
    case 1:
        return "Triennale";
    case 2:
        return "Magistrale";
    case 3:
        return "Diploma Specializzazione";
    case 4:
        return "Dottorato Ricerca";
    default:
        return "";
    }
}

void studente::setLaurea(const string &value){
    if(value == "Triennale") laurea = triennale;
    if(value == "Magistrale") laurea = magistrale;
    if(value == "Diploma Specializzazione") laurea = diplSpecializzazione;
    if(value == "Dottorato Ricerca") laurea = dottRicerca;
}

void studente::setLaurea(const TipoLaurea &value){
    laurea = value;
}

string studente::getCorso() const{
    return corso;
}

void studente::setCorso(const string &value){
    corso = value;
}

int studente::getAnnoCorso() const{
    return annoCorso;
}

void studente::setAnnoCorso(int value){
    annoCorso = value;
}

bool studente::getFuoricorso() const{
    return fuoricorso;
}

void studente::setFuoricorso(bool value){
    fuoricorso = value;
}

int studente::getAnniFuoriCorso() const{
    return anniFuoriCorso;
}

void studente::setAnniFuoriCorso(int value){
    anniFuoriCorso = value;
}

int studente::getGiornoIscrizione() const
{
    return giornoIscrizione;
}

void studente::setGiornoIscrizione(int value)
{
    giornoIscrizione = value;
}

int studente::getMeseIscrizione() const
{
    return meseIscrizione;
}

void studente::setMeseIscrizione(int value)
{
    meseIscrizione = value;
}

int studente::getAnnoIscrizione() const
{
    return annoIscrizione;
}

void studente::setAnnoIscrizione(int value)
{
    annoIscrizione = value;
}

studente::studente(string _nome, string _cognome, string _codiceFiscale, string _telefono, string _email, int _giornoNascita, int _meseNascita, int _annoNascita, string _regione, string _comune, string _via, string _cap, string _numeroCivico, int _matricola, TipoLaurea _laurea, string _corso, int _annoCorso, bool _fuoriCorso, int _anniFuoriCorso, int _giornoIscrizione, int _meseIscrizione, int _annoIscrizione):utente(_nome, _cognome, _codiceFiscale, _telefono, _email, _giornoNascita, _meseNascita, _annoNascita, _regione, _comune, _via, _cap, _numeroCivico), matricola(_matricola), laurea(_laurea), corso(_corso), annoCorso(_annoCorso), fuoricorso(_fuoriCorso), anniFuoriCorso(_anniFuoriCorso), annoIscrizione(_annoIscrizione), meseIscrizione(_meseIscrizione), giornoIscrizione(_giornoIscrizione){
}

studente* studente::clone() const{
    return new studente(*this);
}

bool studente::equals(utente* x) const{
    if(!dynamic_cast<studente*>(x))return false;
    studente* y = dynamic_cast<studente*>(x);
    bool user = (getNome() == x->getNome() && getCognome() == x->getCognome() && getCodiceFiscale() == x->getCodiceFiscale() && getTelefono() == x->getTelefono() && getEmail() == x->getEmail() && getRegione() == x->getRegione() && getComune() == x->getComune() && getVia() ==x->getVia() && getNumeroCivico() == x->getNumeroCivico() && getCap() == x->getCap() && getGiornoNascita() == x->getGiornoNascita() && getMeseNascita() == x->getMeseNascita() && getAnnoNascita() == x->getAnnoNascita());
    bool student = (getMatricola() == y->getMatricola() && getLaurea() == y->getLaurea() && getCorso() == y->getCorso() && getAnnoCorso() == y->getAnnoCorso() && getFuoricorso() == y->getFuoricorso() && getAnniFuoriCorso() == y->getAnniFuoriCorso() && getGiornoIscrizione() == y->getGiornoIscrizione() && getMeseIscrizione() == y->getMeseIscrizione() && getAnnoIscrizione() == y->getAnnoIscrizione());
    return (user && student);
}
