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
     QDate dataIscrizione;

public:
    studente(string="", string="", string="", string="", string="", int=1, int=1, int=1970, string="", string="", string="", string="", string="", int=0, TipoLaurea=triennale, string="", int=0,bool=false, int=0, int=1, int=1, int=1970);
    ~studente() = default;
    virtual studente* clone() const override;
    tipoutente getTipoUtente() const;
    int getMatricola() const;
    void setMatricola(int value);
    TipoLaurea getLaurea() const;
    void setLaurea(const TipoLaurea &value);
    string getCorso() const;
    void setCorso(const string &value);
    int getAnnoCorso() const;
    void setAnnoCorso(int value);
    bool getFuoricorso() const;
    void setFuoricorso(bool value);
    int getAnniFuoriCorso() const;
    void setAnniFuoriCorso(int value);
    QDate getDataIscrizione() const;
    void setDataIscrizione(const QDate &value);
};

#endif // STUDENTE_H
