#ifndef UTENTE_H
#define UTENTE_H

#include <string>

using std::string;

enum tipoutente{Utente=0, Studente=1, Professore=2, Insegnante=3, Tutor=4};

class utente{
private:
    string nome;
    string cognome;
    string codiceFiscale;
    string telefono;
    string email;
    int giornoNascita;
    int meseNascita;
    int annoNascita;
    string regione;
    string comune;
    string via;
    string cap;
    string numeroCivico;

public:
    utente(string="", string="", string="", string="", string="", int=1, int=1, int=1970, string="", string="", string="", string="", string="");
    virtual ~utente() = default;
    virtual utente* clone() const = 0;
    virtual tipoutente getTipoUtente() const = 0;
    static string fromTipoUtente(const tipoutente &_tipoUtente);
    static tipoutente toTipoUtente(const string &_tipoUtente);
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
    int getAnnoNascita() const;
    void setAnnoNascita(int value);
    int getMeseNascita() const;
    void setMeseNascita(int value);
    int getGiornoNascita() const;
    void setGiornoNascita(int value);
};


#endif // UTENTE_H
