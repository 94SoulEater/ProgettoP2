#ifndef UTENTE_H
#define UTENTE_H

#include <string>
#include <QDate>

using std::string;
using std::ostream;

class utente{
    friend ostream& operator <<(ostream&,const utente&);
private:
    string nome;
    string cognome;
    string codiceFiscale;
    string telefono;
    string email;
    QDate dataNascita;
    string regione;
    string comune;
    string via;
    string cap;
    string numeroCivico;

public:
    utente(string="", string="", string="", string="", string="", int=1, int=1, int=1970, string="", string="", string="", string="", string="");
    virtual ~utente() = default;
    virtual utente* clone() const = 0;
    string getNumeroCivico() const;
    void setNumeroCivico(const string &value);
    string getCap() const;
    void setCap(const string &value);
    string getVia() const;
    void setVia(const string &value);
    string getComune() const;
    void setComune(const string &value);
    string getRegione() const;
    void setRegione(const string &value);
    QDate getDataNascita() const;
    void setDataNascita(const QDate &value);
    string getEmail() const;
    void setEmail(const string &value);
    string getTelefono() const;
    void setTelefono(const string &value);
    string getCodiceFiscale() const;
    void setCodiceFiscale(const string &value);
    string getCognome() const;
    void setCognome(const string &value);
    string getNome() const;
    void setNome(const string &value);

};


#endif // UTENTE_H
