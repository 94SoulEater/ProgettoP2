#include "Model/insegnante.h"

vector<lezione> insegnante::getLezioni() const
{
    return lezioni;
}

void insegnante::setLezioni(const vector<lezione> &value)
{
    lezioni = value;
}

insegnante::insegnante(string _nome, string _cognome, string _codiceFiscale, string _telefono, string _email, int _giornoNascita, int _meseNascita, int _annoNascita, string _regione, string _comune, string _via, string _cap, string _numeroCivico): utente(_nome, _cognome, _codiceFiscale, _telefono, _email, _giornoNascita, _meseNascita, _annoNascita, _regione, _comune, _via, _cap, _numeroCivico), lezioni(){
}
