#ifndef RICERCA_H
#define RICERCA_H

#include <string>
#include <QDate>

using std::string;

class ricerca{
private:
    string autori;
    string titolo;
    string link;
    string rivistaPubblicazione;
    QDate dataPubblicazione;
public:
    ricerca(string="", string="", string="", string="", int=1, int=1, int=1970);
    ~ricerca() = default;
    bool operator==(const ricerca&)const;
    bool operator!=(const ricerca&)const;
    QDate getDataPubblicazione() const;
    void setDataPubblicazione(const QDate &value);
    string getRivistaPubblicazione() const;
    void setRivistaPubblicazione(const string &value);
    string getLink() const;
    void setLink(const string &value);
    string getTitolo() const;
    void setTitolo(const string &value);
    string getAutori() const;
    void setAutori(const string &value);
};

#endif // RICERCA_H
