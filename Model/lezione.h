#ifndef LEZIONE_H
#define LEZIONE_H

#include <string>
#include "Model/contenitore.h"

using std::string;

enum DayOfWeek{Monday = 1, Tuesday = 2, Wednesday = 3, Thursday = 4, Friday = 5, Saturday = 6, Sunday = 7};

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
    static string fromDayOfWeek(DayOfWeek _day);
    static DayOfWeek toDayOfWeek(const string &_day);
    string getMateria() const;
    void setMateria(const string &value);
    string getCorsoLaurea() const;
    void setCorsoLaurea(const string &value);
    string getStanza() const;
    void setStanza(const string &value);
    int getCrediti() const;
    void setCrediti(int value);
    contenitore<giornoLezione> getGiorniLezione();
    contenitore<string> getGiorniLezioneStringCont()const;
    void setGiorniLezione(const contenitore<string>&);
    void addGiornoLezione(string, string, DayOfWeek);
    void removeGiornoLezione(string, string, DayOfWeek);
    void clearGiorniLezione();
};

#endif // LEZIONE_H
