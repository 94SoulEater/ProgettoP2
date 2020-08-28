#include "menu.h"
#include <Qt>
#include <QApplication>
#include <QTime>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    menu w;
    w.show();
    return a.exec();
}
