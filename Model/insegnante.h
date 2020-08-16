#ifndef INSEGNANTE_H
#define INSEGNANTE_H

#include <Model/utente.h>
#include <Model/lezione.h>
#include <QDate>
#include <vector>

using std::vector;

class insegnante : virtual public utente{
private:
    vector<lezione> lezioni;
public:
    insegnante(string="", string="", string="", string="", string="", int=1, int=1, int=1970, string="", string="", string="", string="", string="");
    ~insegnante() = default;
    tipoutente getTipoUtente() const;
    vector<lezione> getLezioni() const;
    void addLezione(const lezione);
    void removeLezione(const lezione);
};

#endif // INSEGNANTE_H
