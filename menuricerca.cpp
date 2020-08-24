#include "menuricerca.h"

menuricerca::menuricerca(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Aggiungi ricerca");
    //setMinimumSize(QSize(400, 250));
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    maindatiLayout = new QVBoxLayout();
    formLayout = new QFormLayout();

    //titolo
    titoloLabel=new QLabel("Titolo:");
    titoloLineEdit = new QLineEdit();
    formLayout->addRow(titoloLabel, titoloLineEdit);

    //autori
    autoriLabel=new QLabel("Autori:");
    autoriLineEdit = new QLineEdit();
    formLayout->addRow(autoriLabel, autoriLineEdit);

    //link
    linkLabel=new QLabel("Link:");
    linkLineEdit = new QLineEdit();
    formLayout->addRow(linkLabel, linkLineEdit);

    //rivista pubblicazione
    rivistaLabel=new QLabel("Rivista di Pubblicazione:");
    rivistaLineEdit = new QLineEdit();
    formLayout->addRow(rivistaLabel, rivistaLineEdit);

    //data di pubblicazione
    dataPubblicazioneLabel=new QLabel("Data di Pubblicazione:");
    dataPubblicazioneLineEdit = new QLineEdit();
    dataPubblicazioneLineEdit->setValidator(new QIntValidator(this));
    formLayout->addRow(dataPubblicazioneLabel, dataPubblicazioneLineEdit);


    maindatiLayout->addLayout(formLayout);

    //bottoni
    aggiungiRicercaButton= new QPushButton("Aggiungi Ricerca");
    annullaRicercaButton= new QPushButton("Annulla inserimento");

    bottoniRicercaLayout = new QHBoxLayout();
    bottoniRicercaLayout->addWidget(aggiungiRicercaButton);
    bottoniRicercaLayout->addWidget(annullaRicercaButton);

    maindatiLayout->addLayout(bottoniRicercaLayout);

    connect(annullaRicercaButton,SIGNAL(clicked()),this,SLOT(reject()));
    connect(aggiungiRicercaButton, SIGNAL(clicked()), this, SLOT(accept()));

    setLayout(maindatiLayout);
}
