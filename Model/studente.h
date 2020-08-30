#ifndef STUDENTE_H
#define STUDENTE_H

#include <Model/utente.h>

enum TipoLaurea{ triennale = 1, magistrale = 2, diplSpecializzazione = 3, dottRicerca = 4 };

class studente : virtual public utente{
private:
    int matricola;
    TipoLaurea laurea;
    string corso;
    int annoCorso;
    bool fuoricorso;
    int anniFuoriCorso;
    int annoIscrizione;
    int meseIscrizione;
    int giornoIscrizione;

public:
    studente(string _nome="", string _cognome="", string _codiceFiscale="", string _telefono="", string _email="", int _giornoNascita=1, int _meseNascita=1, int _annoNascita=1970, string _regione="", string _comune="", string _via="", string _cap="", string _numeroCivico="", int _matricola=0, TipoLaurea _laurea=triennale, string _corso="", int _annoCorso=0, bool _fuoriCorso=false, int _anniFuoriCorso=0, int _giornoIscrizione=1, int _meseIscrizione=1, int _annoIscrizione=1970);
    ~studente() = default;
    virtual studente* clone() const override;
    virtual tipoutente getTipoUtente() const override;
    int getMatricola() const;
    void setMatricola(int value);
    string getLaurea() const;
    void setLaurea(const TipoLaurea &value);
    void setLaurea(const string &value);
    string getCorso() const;
    void setCorso(const string &value);
    int getAnnoCorso() const;
    void setAnnoCorso(int value);
    bool getFuoricorso() const;
    void setFuoricorso(bool value);
    int getAnniFuoriCorso() const;
    void setAnniFuoriCorso(int value);
    int getGiornoIscrizione() const;
    void setGiornoIscrizione(int value);
    int getMeseIscrizione() const;
    void setMeseIscrizione(int value);
    int getAnnoIscrizione() const;
    void setAnnoIscrizione(int value);
};

#endif // STUDENTE_H
