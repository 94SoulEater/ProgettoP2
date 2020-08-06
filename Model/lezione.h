#ifndef LEZIONE_H
#define LEZIONE_H

#include <QTime>
#include <string>
#include <vector>

using std::string;
using std::vector;

struct giornoLezione{
    bool operator==(const giornoLezione &_lez)const{
        return (oraInizio==_lez.oraInizio && oraFine == _lez.oraFine && giornoSettimana == _lez.giornoSettimana);
    }
    QTime oraInizio;
    QTime oraFine;
    string giornoSettimana;
};

class lezione{
private:
    string materia;
    string corsoLaurea;
    string stanza;
    int crediti;
    vector<giornoLezione> giorniLezione;

public:
    lezione(string="", string="", string="", int=0);
    ~lezione() = default;
    bool operator==(const lezione&)const;
    string getMateria() const;
    void setMateria(const string &value);
    string getCorsoLaurea() const;
    void setCorsoLaurea(const string &value);
    string getStanza() const;
    void setStanza(const string &value);
    int getCrediti() const;
    void setCrediti(int value);
    vector<giornoLezione> getGiorniLezione() const;
    void addGiornoLezione(QTime, QTime, const string);
    void removeGiornoLezione(QTime, QTime, const string);
};

#endif // LEZIONE_H
