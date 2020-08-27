#include "errore.h"

errore::errore(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Errore");
    //setMinimumSize(QSize(400, 250));
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    errLayout = new QHBoxLayout();
    messaggio=new QLabel("errore non hai inserito nome, cognome o codice fiscale");
    errLayout->addWidget(messaggio);

}
