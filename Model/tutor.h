#ifndef TUTOR_H
#define TUTOR_H

#include <Model/studente.h>
#include <Model/insegnante.h>

class tutor : public studente, public insegnante{
public:
    tutor(string="", string="", string="", string="", string="", int=1, int=1, int=1970, string="", string="", string="", string="", string="", int=0, TipoLaurea=triennale, string="", int=0,bool=false, int=0, int=1, int=1, int=1970);
    ~tutor() = default;
    virtual tutor* clone() const override;
    virtual bool equals(utente* x) const override;
    tipoutente getTipoUtente() const;
};

#endif // TUTOR_H
