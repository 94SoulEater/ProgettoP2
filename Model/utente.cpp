#include "Model/utente.h"
using std::string;

tipoutente utente::getTipoUtente() const{
    return Utente;
}

string utente::fromTipoUtente(const tipoutente &_tipoUtente){
    switch(_tipoUtente){
    case Utente:
        return "Utente";
    case Studente:
        return "Studente";
    case Professore:
        return "Professore";
    case Insegnante:
        return "Insegnante";
    case Tutor:
        return "Tutor";
    }
}
tipoutente utente::toTipoUtente(const string &_tipoUtente){
    if(_tipoUtente == "Utente") return Utente;
    if(_tipoUtente == "Studente") return Studente;
    if(_tipoUtente == "Professore") return Professore;
    if(_tipoUtente == "Insegnante") return Insegnante;
    if(_tipoUtente == "Tutor") return Tutor;
}

string utente::getNumeroCivico() const{
    return numeroCivico;
}

void utente::setNumeroCivico(const string &value){
    numeroCivico = value;
}

string utente::getCap() const{
    return cap;
}

void utente::setCap(const string &value){
    cap = value;
}

string utente::getVia() const{
    return via;
}

void utente::setVia(const string &value){
    via = value;
}

string utente::getComune() const{
    return comune;
}

void utente::setComune(const string &value){
    comune = value;
}

string utente::getRegione() const{
    return regione;
}

void utente::setRegione(const string &value){
    regione = value;
}

QDate utente::getDataNascita() const{
    return dataNascita;
}

void utente::setDataNascita(const QDate &value){
    dataNascita = value;
}

string utente::getEmail() const{
    return email;
}

void utente::setEmail(const string &value){
    email = value;
}

string utente::getTelefono() const{
    return telefono;
}

void utente::setTelefono(const string &value){
    telefono = value;
}

string utente::getCodiceFiscale() const{
    return codiceFiscale;
}

void utente::setCodiceFiscale(const string &value){
    codiceFiscale = value;
}

string utente::getCognome() const{
    return cognome;
}

void utente::setCognome(const string &value){
    cognome = value;
}

string utente::getNome() const{
    return nome;
}

void utente::setNome(const string &value){
    nome = value;
}

utente::utente(string _nome, string _cognome, string _codiceFiscale, string _telefono, string _email, int _giornoNascita, int _meseNascita, int _annoNascita, string _regione, string _comune, string _via, string _cap, string _numeroCivico):nome(_nome), cognome(_cognome), codiceFiscale(_codiceFiscale), telefono(_telefono), email(_email), dataNascita(_annoNascita, _meseNascita, _giornoNascita), regione(_regione), comune(_comune), via(_via), cap(_cap), numeroCivico(_numeroCivico){
}


