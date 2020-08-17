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
#include "tablemodel.h"
#include <Qt>
#include <QApplication>
#include <QTime>
#include <iostream>

using namespace std;

using std::cout; using std::endl; using Qt::DayOfWeek;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    menu w;
    tablemodel modello;
    w.setModel(&modello);
    w.show();

    return a.exec();
}
