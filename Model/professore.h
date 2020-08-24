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
    professore(string="", string="", string="", string="", string="", int=1, int=1, int=1970, string="", string="", string="", string="", string="", string="", int=0);
    ~professore() = default;
    virtual professore* clone() const override;
    virtual bool equals(utente* x) const override;
    tipoutente getTipoUtente() const;
    string getTipo() const;
    void setTipo(const string &value);
    contenitore<ricerca> getRicerche() const;
    void addRicerca(const ricerca &_ric);
    void removeRicerca(const ricerca &_ric);
    int getAnniServizio() const;
    void setAnniServizio(int value);
};

#endif // PROFESSORE_H
