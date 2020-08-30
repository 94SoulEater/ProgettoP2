#ifndef INSEGNANTE_H
#define INSEGNANTE_H

#include <Model/utente.h>
#include <Model/lezione.h>
#include <Model/contenitore.h>

class insegnante : virtual public utente{
private:
    contenitore<lezione> lezioni;
public:
    insegnante(string _nome="", string _cognome="", string _codiceFiscale="", string _telefono="", string _email="", int _giornoNascita=1, int _meseNascita=1, int _annoNascita=1970, string _regione="", string _comune="", string _via="", string _cap="", string _numeroCivico="");
    ~insegnante() = default;
    virtual insegnante* clone() const = 0;
    virtual tipoutente getTipoUtente() const = 0;
    contenitore<lezione> getLezioni() const;
    void setLezioni(const contenitore<lezione> &_listaLezioni);
    void addLezione(const lezione& _lez);
    void removeLezione(const lezione& _lez);
};

#endif // INSEGNANTE_H
