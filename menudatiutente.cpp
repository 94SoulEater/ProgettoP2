#include "menudatiutente.h"

menudatiutente::menudatiutente(QWidget *parent) : QDialog(parent){
    setWindowTitle("Aggiungi utente");
    //setMinimumSize(QSize(400, 250));
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    maindatiLayout = new QVBoxLayout();
    formLayout = new QFormLayout();

    //tipo utente (non si possono istanziare utente e insegnante)
    tipoUtenteMenuComboBox = new QComboBox();
    tipoUtenteMenuComboBox->addItem("Studente");
    tipoUtenteMenuComboBox->addItem("Professore");
    tipoUtenteMenuComboBox->addItem("Tutor");
    formLayout->addRow(tr("Tipo Utente:"), tipoUtenteMenuComboBox);

    //UTENTE
    //codice fiscale
    codiceFiscaleLineEdit = new QLineEdit();
    codiceFiscaleLineEdit->setInputMask("NNNNNNNNNNNNNNNN;");
    formLayout->addRow(tr("Codice Fiscale:"), codiceFiscaleLineEdit);

    //nome
    nomeLineEdit = new QLineEdit();
    formLayout->addRow(tr("Nome:"), nomeLineEdit);

    //cognome
    cognomeLineEdit = new QLineEdit();
    formLayout->addRow(tr("Cognome:"), cognomeLineEdit);

    //data di nascita
    dataNascitaEdit = new QDateEdit();
    dataNascitaEdit->setCalendarPopup(true);
    formLayout->addRow(tr("Data di Nascita:"), dataNascitaEdit);

    //email
    emailLineEdit = new QLineEdit();
    formLayout->addRow(tr("Email:"), emailLineEdit);

    //telefono
    telefonoLineEdit = new QLineEdit();
    telefonoLineEdit->setInputMask("+99 9999999999;");
    formLayout->addRow(tr("Telefono:"), telefonoLineEdit);

    //cap
    capLineEdit = new QLineEdit();
    capLineEdit->setValidator(new QIntValidator());
    formLayout->addRow(tr("CAP:"), capLineEdit);

    //regione
    regioneLineEdit = new QLineEdit();
    formLayout->addRow(tr("Regione:"), regioneLineEdit);

    //comune
    comuneLineEdit = new QLineEdit();
    formLayout->addRow(tr("Comune:"), comuneLineEdit);

     viaLineEdit = new QLineEdit();
     numeroCivicoLineEdit = new QLineEdit();
   viaLabel = new QLabel("Via:");
    numeroCivicoLabel = new QLabel("Numero Civico:");

    fuoriLayout = new QHBoxLayout();
    fuoriLayout->addWidget(viaLabel);
    fuoriLayout->addWidget(viaLineEdit);
    fuoriLayout->addWidget(numeroCivicoLabel);
    fuoriLayout->addWidget(numeroCivicoLineEdit);

    maindatiLayout->addLayout(formLayout);
    maindatiLayout->addLayout(fuoriLayout);


    //riprendo layout
      formLayout = new QFormLayout();

      //STUDENTE
    //matricola
    matricolaLineEdit = new QLineEdit();
    matricolaLineEdit->setValidator(new QIntValidator());
    formLayout->addRow(tr("Matricola:"), matricolaLineEdit);

    //laurea
    laureaMenuComboBox = new QComboBox();
    laureaMenuComboBox->addItem("Triennale");
    laureaMenuComboBox->addItem("Magistrale");
    laureaMenuComboBox->addItem(" Diploma Specializzazione");
    laureaMenuComboBox->addItem(" Dottorato Ricerca");
    formLayout->addRow(tr("Tipo Laurea:"), laureaMenuComboBox);

    //corso
    corsoLineEdit = new QLineEdit();
    formLayout->addRow(tr("Corso:"), corsoLineEdit);

    //annocorso
    annocorsoLineEdit = new QLineEdit();
    annocorsoLineEdit->setValidator(new QIntValidator());
    formLayout->addRow(tr("Anno corso:"), annocorsoLineEdit);

    //iscrizione
    dataIscrizioneEdit = new QDateEdit();
    dataIscrizioneEdit->setCalendarPopup(true);
    formLayout->addRow(tr("Data di Iscrizione:"), dataIscrizioneEdit);

    //fuoricorso e annifuoricorso
    checkBox = new QCheckBox();
    spinBox = new QSpinBox();
    fuoricorsoLabel = new QLabel("Fuori Corso:");
    annifuoricorsoLabel = new QLabel("Anni Fuori Corso:");

    fuoriLayout = new QHBoxLayout();
    fuoriLayout->addWidget(fuoricorsoLabel);
    fuoriLayout->addWidget(checkBox);
    fuoriLayout->addWidget(annifuoricorsoLabel);
    fuoriLayout->addWidget( spinBox);

    maindatiLayout->addLayout(formLayout);
    maindatiLayout->addLayout(fuoriLayout);


    /*
    //PROFESSORE
    //tipo
    tipoLineEdit = new QLineEdit();
    formLayout->addRow(tr("Tipo:"), tipoLineEdit);

    //anni servizio
    anniServizioLineEdit = new QLineEdit();
    anniServizioLineEdit->setValidator(new QIntValidator());
    formLayout->addRow(tr("Anni di Servizio:"), anniServizioLineEdit);
*/


    //aggiungi, annulla e cancella
    aggiungiMenuButton= new QPushButton("Aggiungi");
    cancellaMenuButton= new QPushButton("Cancella tutto");
    annullaMenuButton= new QPushButton("Annulla inserimento");

    bottoniLayout = new QHBoxLayout();
    bottoniLayout->addWidget(aggiungiMenuButton);
    bottoniLayout->addWidget( cancellaMenuButton);
    bottoniLayout->addWidget(annullaMenuButton);

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
    dataNascitaEdit->clear();
    emailLineEdit->clear();
    telefonoLineEdit->clear();
    capLineEdit->clear();
    regioneLineEdit->clear();
    comuneLineEdit->clear();
    viaLineEdit->clear();
    numeroCivicoLineEdit->clear();
    corsoLineEdit->clear();
    annocorsoLineEdit->clear();
    dataIscrizioneEdit->clear();
    spinBox->clear();
    // tipoLineEdit->clear();
    //anniServizioLineEdit->clear();

}

