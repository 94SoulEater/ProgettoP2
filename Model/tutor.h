#ifndef TUTOR_H
#define TUTOR_H

#include <Model/studente.h>
#include <Model/insegnante.h>

class tutor : public studente, public insegnante{
public:
    tutor(string _nome="", string _cognome="", string _codiceFiscale="", string _telefono="", string _email="", int _giornoNascita=1, int _meseNascita=1, int _annoNascita=1970, string _regione="", string _comune="", string _via="", string _cap="", string _numeroCivico="", int _matricola=0, TipoLaurea _laurea=triennale, string _corso="", int _annoCorso=0, bool _fuoriCorso=false, int _anniFuoriCorso=0, int _giornoIscrizione=1, int _meseIscrizione=1, int _annoIscrizione=1970);
    ~tutor() = default;
    virtual tutor* clone() const override;
    tipoutente getTipoUtente() const override;
};

#endif // TUTOR_H
