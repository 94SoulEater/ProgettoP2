#ifndef PROFESSORE_H
#define PROFESSORE_H

#include <Model/insegnante.h>
#include <Model/ricerca.h>
#include <vector>

using std::vector;

class professore : public insegnante{
private:
    string tipo;
    int anniServizio;
    vector<ricerca> ricerche;
public:
    professore(string="", int=0);
    ~professore() = default;
    string getTipo() const;
    void setTipo(const string &value);
    vector<ricerca> getRicerche() const;
    void addRicerca(const ricerca &_ric);
    void removeRicerca(const ricerca &_ric);
    int getAnniServizio() const;
    void setAnniServizio(int value);
};

#endif // PROFESSORE_H
