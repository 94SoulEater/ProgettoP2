#include "menu.h"

menu::menu(QWidget *parent) : QWidget(parent)
{
       //aggiungere il menu
       addMenu();
}

void menu::addMenu()
{
    QMenuBar* menubar=new QMenuBar(this);
    QMenu* Menu=new QMenu("File", menubar);
    QAction* exit=new QAction("Exit", Menu);

     //signal triggered() e lo slot close()
      connect(exit,SIGNAL(triggered()),this,SLOT(close()));

    //aggiungo le azioni al menu
    Menu->addAction(exit);

    //aggiungo il menu alla barra
    menubar->addMenu(Menu);

    //aggiungere la barra al layout
   mainLayout->addWidget(menubar);

}
