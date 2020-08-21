#include "menudatiutente.h"

menudatiutente::menudatiutente(QWidget *parent) : QDialog(parent){
    setWindowTitle("Aggiungi utente");
    //setMinimumSize(QSize(400, 250));
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    maindatiLayout = new QVBoxLayout(this);
    formLayout = new QFormLayout();

    //codice fiscale
    codiceFiscaleLineEdit = new QLineEdit();
    formLayout->addRow(tr("Codice Fiscale:"), codiceFiscaleLineEdit);

    //nome
    nomeLineEdit = new QLineEdit();
    formLayout->addRow(tr("Nome:"), nomeLineEdit);

    //cognome
    cognomeLineEdit = new QLineEdit();
    formLayout->addRow(tr("Cognome:"), cognomeLineEdit);

    //data di nascita
    dataNascitaLineEdit = new QLineEdit();
    formLayout->addRow(tr("Data di Nascita:"), dataNascitaLineEdit);

    //tipo utente (non si possono istanziare utente e studente)
    tipoUtenteMenuComboBox = new QComboBox();
    tipoUtenteMenuComboBox->addItem("Studente");
    tipoUtenteMenuComboBox->addItem("Professore");
    tipoUtenteMenuComboBox->addItem("Tutor");
    formLayout->addRow(tr("Tipo Utente:"), tipoUtenteMenuComboBox);

    //aggiungi, annulla e cancella
    aggiungiMenuButton= new QPushButton("Aggiungi");
    cancellaMenuButton= new QPushButton("Cancella tutto");
    annullaMenuButton= new QPushButton("Annulla inserimento");

    bottoniLayout = new QHBoxLayout();


    bottoniLayout->addWidget(aggiungiMenuButton);
    bottoniLayout->addWidget( cancellaMenuButton);
    bottoniLayout->addWidget(annullaMenuButton);


    maindatiLayout->addLayout(formLayout);
    maindatiLayout->addLayout(bottoniLayout);

    connect(annullaMenuButton,SIGNAL(clicked()),this,SLOT(reject()));
    connect(aggiungiMenuButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(cancellaMenuButton, SIGNAL(clicked()), this, SLOT(clear()));


    setLayout(maindatiLayout);
}

void menudatiutente::clear(){
    codiceFiscaleLineEdit->clear();
    nomeLineEdit->clear();
    cognomeLineEdit->clear();
    dataNascitaLineEdit->clear();
}

