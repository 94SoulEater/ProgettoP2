#ifndef LEZIONE_H
#define LEZIONE_H

#include <QDate>
#include <string>

using std::string;

class lezione{
private:
    string materia;
    string corsoLaurea;
    string stanza;
    int crediti;

public:
    lezione(string="", string="", string="", int=0);
    ~lezione() = default;
    string getMateria() const;
    void setMateria(const string &value);
    string getCorsoLaurea() const;
    void setCorsoLaurea(const string &value);
    string getStanza() const;
    void setStanza(const string &value);
    int getCrediti() const;
    void setCrediti(int value);
};

#endif // LEZIONE_H
