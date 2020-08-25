#ifndef LEZIONE_H
#define LEZIONE_H

#include <Qt>
#include <QTime>
#include <string>
#include "Model/contenitore.h"

using std::string;
using Qt::DayOfWeek;

struct giornoLezione{
    bool operator==(const giornoLezione &_lez)const{
        return (oraInizio==_lez.oraInizio && oraFine == _lez.oraFine && giornoSettimana == _lez.giornoSettimana);
    }
    bool operator!=(const giornoLezione &_lez)const{
        return (oraInizio!=_lez.oraInizio || oraFine != _lez.oraFine || giornoSettimana != _lez.giornoSettimana);
    }
    string oraInizio;
    string oraFine;
    DayOfWeek giornoSettimana;
};

class lezione{
private:
    string materia;
    string corsoLaurea;
    string stanza;
    int crediti;
    contenitore<giornoLezione> giorniLezione;

public:
    lezione(string="", string="", string="", int=0);
    ~lezione() = default;
    bool operator==(const lezione&)const;
    bool operator!=(const lezione&)const;
    string getMateria() const;
    void setMateria(const string &value);
    string getCorsoLaurea() const;
    void setCorsoLaurea(const string &value);
    string getStanza() const;
    void setStanza(const string &value);
    int getCrediti() const;
    void setCrediti(int value);
    contenitore<giornoLezione> getGiorniLezione() const;
    void addGiornoLezione(string, string, DayOfWeek);
    void removeGiornoLezione(string, string, DayOfWeek);
};

#endif // LEZIONE_H
