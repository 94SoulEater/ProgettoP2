#include "menudatiutente.h"

menudatiutente::menudatiutente(QWidget *parent) : QDialog(parent){
    setWindowTitle("Aggiungi utente");
    setMinimumSize(QSize(400, 250));
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
/*
    maindatiLayout = new QVBoxLayout(this);

    //codice fiscale
    labelLayout = new QHBoxLayout();
    codiceFiscaleLabel = new QLabel("Codice Fiscale");
    codiceFiscaleLineEdit = new QLineEdit();
    codiceFiscaleLabel->setAlignment(Qt::AlignCenter);
    labelLayout->addWidget(codiceFiscaleLabel);
    labelLayout->addWidget(codiceFiscaleLineEdit);
    maindatiLayout->addLayout(labelLayout);

    //nome
    labelLayout = new QHBoxLayout();
    nomeLabel = new QLabel("Nome");
    nomeLineEdit = new QLineEdit();
    nomeLabel->setAlignment(Qt::AlignCenter);
    labelLayout->addWidget(nomeLabel);
    labelLayout->addWidget(nomeLineEdit);
    maindatiLayout->addLayout(labelLayout);

    //cognome
    labelLayout = new QHBoxLayout();
    cognomeLabel = new QLabel("Cognome");
    cognomeLineEdit = new QLineEdit();
    cognomeLabel->setAlignment(Qt::AlignCenter);
    labelLayout->addWidget(cognomeLabel);
    labelLayout->addWidget(cognomeLineEdit);
    maindatiLayout->addLayout(labelLayout);

    //data di nascita
    labelLayout = new QHBoxLayout();
    dataNascitaLabel = new QLabel("Data di Nascita");
    dataNascitaLineEdit = new QLineEdit();
    dataNascitaLabel->setAlignment(Qt::AlignCenter);
    labelLayout->addWidget(dataNascitaLabel);
    labelLayout->addWidget(dataNascitaLineEdit);
    maindatiLayout->addLayout(labelLayout);

    //tipo utente
    labelLayout = new QHBoxLayout();
    tipoUtenteLabel = new QLabel("Tipo Utente");
    tipoUtenteMenuComboBox = new QComboBox();
    tipoUtenteMenuComboBox->addItem("Utente");
    tipoUtenteMenuComboBox->addItem("Studente");
    tipoUtenteMenuComboBox->addItem("Professore");
    tipoUtenteMenuComboBox->addItem("Insegnante");
    tipoUtenteMenuComboBox->addItem("Tutor");
    tipoUtenteLabel->setAlignment(Qt::AlignLeft);
    labelLayout->addWidget(tipoUtenteLabel);
    labelLayout->addWidget( tipoUtenteMenuComboBox);
    maindatiLayout->addLayout(labelLayout);

    //aggiungi e annulla
    aggiungiAnnullaMenuButtonLayout = new QHBoxLayout();
    aggiungiMenuButton= new QPushButton("Aggiungi");
    aggiungiAnnullaMenuButtonLayout->addWidget(aggiungiMenuButton);
    cancellaMenuButton= new QPushButton("Cancella tutto");
    aggiungiAnnullaMenuButtonLayout->addWidget(cancellaMenuButton);
    annullaMenuButton= new QPushButton("Annulla inserimento");
    aggiungiAnnullaMenuButtonLayout->addWidget(annullaMenuButton);
    maindatiLayout->addLayout(aggiungiAnnullaMenuButtonLayout);

    connect(annullaMenuButton,SIGNAL(clicked()),this,SLOT(reject()));
    connect(aggiungiMenuButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(cancellaMenuButton, SIGNAL(clicked()), this, SLOT(clear()));

    setLayout(maindatiLayout);
*/

    formLayout = new QFormLayout(this);

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

     //tipo utente
     tipoUtenteMenuComboBox = new QComboBox();
     tipoUtenteMenuComboBox->addItem("Utente");
     tipoUtenteMenuComboBox->addItem("Studente");
     tipoUtenteMenuComboBox->addItem("Professore");
     tipoUtenteMenuComboBox->addItem("Insegnante");
     tipoUtenteMenuComboBox->addItem("Tutor");
    formLayout->addRow(tr("Tipo Utente:"), tipoUtenteMenuComboBox);

     //aggiungi, annulla e cancella
     aggiungiMenuButton= new QPushButton("Aggiungi");
     cancellaMenuButton= new QPushButton("Cancella tutto");
     annullaMenuButton= new QPushButton("Annulla inserimento");
   formLayout->addRow(aggiungiMenuButton);
   formLayout->addRow( cancellaMenuButton);
   formLayout->addRow(annullaMenuButton);

     connect(annullaMenuButton,SIGNAL(clicked()),this,SLOT(reject()));
     connect(aggiungiMenuButton, SIGNAL(clicked()), this, SLOT(accept()));
     connect(cancellaMenuButton, SIGNAL(clicked()), this, SLOT(clear()));


    setLayout(formLayout);
}

void menudatiutente::clear(){
    codiceFiscaleLineEdit->clear();
    nomeLineEdit->clear();
    cognomeLineEdit->clear();
    dataNascitaLineEdit->clear();
    tipoUtenteMenuComboBox->clear();
    tipoUtenteMenuComboBox->addItem("Utente");
    tipoUtenteMenuComboBox->addItem("Studente");
    tipoUtenteMenuComboBox->addItem("Professore");
    tipoUtenteMenuComboBox->addItem("Insegnante");
    tipoUtenteMenuComboBox->addItem("Tutor");
}

