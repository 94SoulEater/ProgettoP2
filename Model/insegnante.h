#ifndef INSEGNANTE_H
#define INSEGNANTE_H

#include <Model/utente.h>
#include <Model/lezione.h>
#include <QDate>
#include <vector>

using std::vector;

//prova

class insegnante : virtual public utente{
private:
    vector<lezione> lezioni;
public:
    insegnante(string="", string="", string="", string="", string="", int=1, int=1, int=1970, string="", string="", string="", string="", string="");
    ~insegnante() = default;
    vector<lezione> getLezioni() const;
    void setLezioni(const vector<lezione> &value);
};

#endif // INSEGNANTE_H
