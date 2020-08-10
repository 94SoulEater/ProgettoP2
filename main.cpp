#include "university.h"
#include "Model/insegnante.h"
#include "Model/professore.h"
#include "Model/lezione.h"
#include "Model/lezione.h"
#include "Model/ricerca.h"
#include <Qt>
#include <QApplication>
#include <QTime>
#include <iostream>

using std::cout; using std::endl; using Qt::DayOfWeek;

int main(int argc, char *argv[]){
    /*  TEST CLASSI
    professore provaIns1("Marco", "Dello Iacovo","ctflelo1239CFCFCF", "3201512686", "marco.delloiacovo99@gmail.com", 18, 10, 1999, "Veneto", "Caerano di san marco", "San marco", "31031", "xx-Bis", "Ordinario", 30);
    lezione provaLez1("Programmazione ad oggetti", "SC1167 - Informatica", "Lum250", 12);
    lezione provaLez2("Verifica del software", "SC1176 - LM Informatica", "P200", 12);
    QTime oraInizio(12, 30), oraFine(14, 30);
    provaLez1.addGiornoLezione(oraInizio, oraFine, Qt::Monday);
    provaLez2.addGiornoLezione(oraInizio, oraFine, Qt::Tuesday);
    oraInizio = QTime(14, 30), oraFine = QTime(16, 30);
    provaLez1.addGiornoLezione(oraInizio, oraFine, Qt::Thursday);
    provaLez2.addGiornoLezione(oraInizio, oraFine, Qt::Wednesday);
    provaIns1.addLezione(provaLez1);
    provaIns1.addLezione(provaLez2);
    ricerca provaRic1("G. Filè and F. Ranzato", "Improving abstract interpretations by systematic lifting to the powerset", "https://www.math.unipd.it/~ranzato/papers/ilps94.pdf", "The MIT Press", 1, 1, 1994);
    provaIns1.addRicerca(provaRic1);
    provaRic1 = ricerca("A. Cortesi, R. Giacobazzi, G. Filé, C. Palamidessi, and F. Ranzato", "Complementation in abstract interpretation", "https://www.math.unipd.it/~ranzato/papers/sas95.pdf", "Springer-Verlag", 1, 1, 1995);
    provaIns1.addRicerca(provaRic1);
    vector<lezione> provaLezVec1 = provaIns1.getLezioni();
    vector<ricerca> provaRicVec1 = provaIns1.getRicerche();
    vector<giornoLezione> provaGiorniLez1;
    //Stampa
    cout<<provaIns1.getNome()<<" "<<provaIns1.getCognome()<<" "<<provaIns1.getDataNascita().toString().toStdString()<<" "<<provaIns1.getAnniServizio()<<endl;
    for(auto it = provaLezVec1.begin(); it != provaLezVec1.end(); ++it){
        provaGiorniLez1 = it->getGiorniLezione();
        cout<<it->getCorsoLaurea()<<" "<<it->getMateria()<<" "<<it->getCrediti()<<" "<<it->getStanza()<<" Orari:"<<endl;
        for(auto it1 = provaGiorniLez1.begin(); it1 != provaGiorniLez1.end(); ++it1){
            cout<<"\t"<<it1->oraInizio.toString().toStdString()<<" - "<<it1->oraFine.toString().toStdString()<<" "<<it1->giornoSettimana<<endl;
        }
    }
    cout<<"Ricerche: "<<endl;
    for(auto it = provaRicVec1.begin(); it!=provaRicVec1.end(); ++it){
        cout<<"\t"<<it->getAutori()<<" "<<it->getTitolo()<<" "<<it->getLink()<<" "<<it->getRivistaPubblicazione()<<" "<<it->getDataPubblicazione().year()<<endl;
    }
    */
    QApplication a(argc, argv);
    university w;
    w.show();

    return a.exec();
}
