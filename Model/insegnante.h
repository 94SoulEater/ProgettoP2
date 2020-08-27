#ifndef INSEGNANTE_H
#define INSEGNANTE_H

#include <Model/utente.h>
#include <Model/lezione.h>
#include <Model/contenitore.h>
#include <QDate>

class insegnante : virtual public utente{
private:
    contenitore<lezione> lezioni;
public:
    insegnante(string="", string="", string="", string="", string="", int=1, int=1, int=1970, string="", string="", string="", string="", string="");
    ~insegnante() = default;
    virtual insegnante* clone() const = 0;
    virtual tipoutente getTipoUtente() const = 0;
    contenitore<lezione> getLezioni() const;
    void setLezioni(const contenitore<lezione> &_listaLezioni);
    void addLezione(const lezione& _lez);
    void removeLezione(const lezione& _lez);
};

#endif // INSEGNANTE_H
