#include "menu.h"
#include "menu.h"
#include "Model/utente.h"
#include "Model/insegnante.h"
#include "Model/professore.h"
#include "Model/lezione.h"
#include "Model/tutor.h"
#include "Model/lezione.h"
#include "Model/ricerca.h"
#include "Model/contenitore.h"
#include "utentitablemodel.h"
#include <Qt>
#include <QApplication>
#include <QTime>
#include <iostream>

using namespace std;

using std::cout; using std::endl; using Qt::DayOfWeek;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    utentitablemodel modello;
    menu w(&modello);
    w.show();

    return a.exec();
}
