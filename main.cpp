#include "university.h"
#include "Model/utente.h"
#include <QApplication>

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    //utente(string="", string="", string="", string="", string="", int=1, int=1, int=1970, string="", string="", string="", string="", string="")
    //nome(_nome), cognome(_cognome), codiceFiscale(_codiceFiscale), telefono(_telefono), email(_email), dataNascita(_annoNascita, _meseNascita, _giornoNascita), regione(_regione), comune(_comune), via(_via), cap(_cap), numeroCivico(_numeroCivico)
    utente s("Sergio", "Fichera", "FCHSRG96D08F519G","3456784253","sergiofichera@hotmail.it", 8,4,1996, "Lombardia","Milano","Via Bergamo","20019", "13");


    QApplication a(argc, argv);
    university w;
    w.show();

    return a.exec();
}
