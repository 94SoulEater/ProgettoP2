#ifndef PROFESSORE_H
#define PROFESSORE_H

#include <Model/insegnante.h>
#include <Model/ricerca.h>
#include <Model/contenitore.h>

class professore : public insegnante{
private:
    string tipo;
    int anniServizio;
    contenitore<ricerca> ricerche;
public:
    professore(string _nome="", string _cognome="", string _codiceFiscale="", string _telefono="", string _email="", int _giornoNascita=1, int _meseNascita=1, int _annoNascita=1970, string _regione="", string _comune="", string _via="", string _cap="", string _numeroCivico="", string _tipo="", int _anniServizio=0);
    ~professore() = default;
    virtual professore* clone() const override;
    virtual tipoutente getTipoUtente() const override;
    string getTipo() const;
    void setTipo(const string &value);
    contenitore<ricerca> getRicerche() const;
    void setRicerche(const contenitore<ricerca> &_listaRicerche);
    void addRicerca(const ricerca &_ric);
    void removeRicerca(const ricerca &_ric);
    int getAnniServizio() const;
    void setAnniServizio(int value);
};

#endif // PROFESSORE_H
