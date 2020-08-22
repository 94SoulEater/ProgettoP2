#include "menudatiutente.h"

menudatiutente::menudatiutente(QWidget *parent) : QDialog(parent){
    setWindowTitle("Aggiungi utente");
    //setMinimumSize(QSize(400, 250));
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    maindatiLayout = new QVBoxLayout();
    formLayout = new QFormLayout();

    //tipo utente (non si possono istanziare utente e insegnante)
    QString prof="Professore";
    tipoUtenteMenuComboBox = new QComboBox();
    tipoUtenteMenuComboBox->addItem("Studente");
   tipoUtenteMenuComboBox->addItem(prof);
    tipoUtenteMenuComboBox->addItem("Tutor");
    formLayout->addRow(tr("Tipo Utente:"), tipoUtenteMenuComboBox);
     connect(tipoUtenteMenuComboBox, SIGNAL(currentIndexChanged(QString)), this,SLOT (showRow(QString)));



    //UTENTE
    //codice fiscale
     codiceFiscaleLabel=new QLabel("Codice Fiscale:");
    codiceFiscaleLineEdit = new QLineEdit();
    codiceFiscaleLineEdit->setInputMask("NNNNNNNNNNNNNNNN;");
    formLayout->addRow(codiceFiscaleLabel, codiceFiscaleLineEdit);

    //nome
    nomeLabel=new QLabel("Nome:");
    nomeLineEdit = new QLineEdit();
    formLayout->addRow(nomeLabel, nomeLineEdit);

    //cognome
    cognomeLabel=new QLabel("Cognome:");
    cognomeLineEdit = new QLineEdit();
    formLayout->addRow(cognomeLabel, cognomeLineEdit);

    //data di nascita
     dataNascitaLabel=new QLabel("Data di Nascita:");
    dataNascitaEdit = new QDateEdit();
    dataNascitaEdit->setCalendarPopup(true);
    formLayout->addRow(dataNascitaLabel, dataNascitaEdit);

    //email
    emailLabel=new QLabel("Email:");
    emailLineEdit = new QLineEdit();
    formLayout->addRow(emailLabel, emailLineEdit);

    //telefono
    telefonoLabel=new QLabel("Telefono:");
    telefonoLineEdit = new QLineEdit();
    telefonoLineEdit->setInputMask("+99 9999999999;");
    formLayout->addRow(telefonoLabel, telefonoLineEdit);

    //cap
    capLabel=new QLabel("CAP:");
    capLineEdit = new QLineEdit();
    capLineEdit->setValidator(new QIntValidator());
    formLayout->addRow(capLabel, capLineEdit);

    //regione
     regioneLabel=new QLabel("Regione:");
    regioneLineEdit = new QLineEdit();
    formLayout->addRow(regioneLabel, regioneLineEdit);

    //comune
     comuneLabel=new QLabel("Comune:");
    comuneLineEdit = new QLineEdit();
    formLayout->addRow(comuneLabel, comuneLineEdit);

    //via e numero
     viaLineEdit = new QLineEdit();
     numeroCivicoLineEdit = new QLineEdit();
   viaLabel = new QLabel("Via:");
    numeroCivicoLabel = new QLabel("Numero Civico:");

    vnLayout = new QHBoxLayout();
    vnLayout->addWidget(viaLabel);
    vnLayout->addWidget(viaLineEdit);
    vnLayout->addWidget(numeroCivicoLabel);
    vnLayout->addWidget(numeroCivicoLineEdit);

    maindatiLayout->addLayout(formLayout);
    maindatiLayout->addLayout(vnLayout);

    //riprendo layout
    formLayout=new QFormLayout();

    //PROFESSORE
    //tipo
     tipoLabel=new QLabel("Tipo:");
    tipoLineEdit = new QLineEdit();
    formLayout->addRow(tipoLabel, tipoLineEdit);

    //anni servizio
    anniServizioLabel=new QLabel("Anni Servizio:");
    anniServizioLineEdit = new QLineEdit();
    anniServizioLineEdit->setValidator(new QIntValidator());
    formLayout->addRow(anniServizioLabel, anniServizioLineEdit);

      //STUDENTE
    //matricola
    matricolaLabel=new QLabel("Matricola:");
    matricolaLineEdit = new QLineEdit();
    matricolaLineEdit->setValidator(new QIntValidator());
    formLayout->addRow(matricolaLabel, matricolaLineEdit);

    //laurea
    laureaLabel=new QLabel("Laurea:");
    laureaMenuComboBox=new QComboBox();
    laureaMenuComboBox->addItem("Triennale");
    laureaMenuComboBox->addItem("Magistrale");
    laureaMenuComboBox->addItem(" Diploma Specializzazione");
    laureaMenuComboBox->addItem(" Dottorato Ricerca");
    formLayout->addRow(laureaLabel, laureaMenuComboBox);

    //corso
    corsoLabel=new QLabel("Corso:");
    corsoLineEdit = new QLineEdit();
    formLayout->addRow(corsoLabel, corsoLineEdit);

    //annocorso
     annocorsoLabel=new QLabel("Anno Corso:");
    annocorsoLineEdit = new QLineEdit();
    annocorsoLineEdit->setValidator(new QIntValidator());
    formLayout->addRow(annocorsoLabel, annocorsoLineEdit);

    //iscrizione
     dataIscrizioneLabel=new QLabel("Data di Iscrizione:");
    dataIscrizioneEdit = new QDateEdit();
    dataIscrizioneEdit->setCalendarPopup(true);
    formLayout->addRow(dataIscrizioneLabel, dataIscrizioneEdit);

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

        //riprendo layout
   formLayout=new QFormLayout();

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

    // non visibili inizialmente
    tipoLineEdit->setVisible(false);
    tipoLabel->setVisible(false);
   anniServizioLineEdit->setVisible(false);
   anniServizioLabel->setVisible(false);

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

    matricolaLineEdit->clear();
    corsoLineEdit->clear();
    annocorsoLineEdit->clear();
    dataIscrizioneEdit->clear();
    spinBox->clear();

     tipoLineEdit->clear();
    anniServizioLineEdit->clear();
}

void menudatiutente::showRow(QString combo)
{
    if(combo=="Studente" || combo=="Tutor"){

       matricolaLabel ->setVisible(true);
      matricolaLineEdit->setVisible(true);
       laureaLabel->setVisible(true);
      laureaMenuComboBox->setVisible(true);
      corsoLabel->setVisible(true);
      corsoLineEdit->setVisible(true);
      annocorsoLabel->setVisible(true);
      annocorsoLineEdit->setVisible(true);
      dataIscrizioneLabel->setVisible(true);
      dataIscrizioneEdit->setVisible(true);
      checkBox->setVisible(true);
      spinBox->setVisible(true);
      fuoricorsoLabel->setVisible(true);
      annifuoricorsoLabel->setVisible(true);

      tipoLineEdit->setVisible(false);
      tipoLabel->setVisible(false);
     anniServizioLineEdit->setVisible(false);
     anniServizioLabel->setVisible(false);

}
    if(combo=="Professore"){

        matricolaLineEdit->setVisible(false);
         matricolaLabel ->setVisible(false);
         laureaMenuComboBox->setVisible(false);
         laureaLabel->setVisible(false);
         corsoLineEdit->setVisible(false);
          corsoLabel->setVisible(false);
         annocorsoLineEdit->setVisible(false);
         annocorsoLabel->setVisible(false);
         dataIscrizioneEdit->setVisible(false);
         dataIscrizioneLabel->setVisible(false);
        checkBox->setVisible(false);
        spinBox->setVisible(false);
        fuoricorsoLabel->setVisible(false);
        annifuoricorsoLabel->setVisible(false);

    tipoLineEdit->setVisible(true);
     tipoLabel->setVisible(true);
    anniServizioLineEdit->setVisible(true);
      anniServizioLabel->setVisible(true);

    }
}
