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

    //cognome
    cognomeLabel=new QLabel("Cognome:");
    cognomeLineEdit = new QLineEdit();
    formLayout->addRow(cognomeLabel, cognomeLineEdit);

    //nome
    nomeLabel=new QLabel("Nome:");
    nomeLineEdit = new QLineEdit();
    formLayout->addRow(nomeLabel, nomeLineEdit);

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

    //RICERCA
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
    dataPubblicazioneEdit = new QDateEdit();
    dataPubblicazioneEdit->setCalendarPopup(true);
    formLayout->addRow(dataPubblicazioneLabel, dataPubblicazioneEdit);

    //bottone
    ricercaLabel=new QLabel("Aggiungi Ricerca:");
    ricercaButton= new QPushButton("Aggiungi");
    formLayout->addRow(ricercaLabel,ricercaButton);

    ricercaEliminaLabel=new QLabel("Elimina Ricerca:");
    ricercaEliminaButton= new QPushButton("Elimina");
    formLayout->addRow(ricercaEliminaLabel,ricercaEliminaButton);

    //elimina ricerca
    connect(ricercaEliminaButton, SIGNAL(clicked()), this, SLOT(eliminaRicerca()));

    //Apre nuova finestra per inserimento ricerca
    connect(ricercaButton, SIGNAL(clicked()), this, SLOT(aggiungiRicerca()));

    //LEZIONE

    //materia
    materiaLabel=new QLabel("Materia:");
    materiaLineEdit = new QLineEdit();
    formLayout->addRow(materiaLabel, materiaLineEdit);

    //corso laurea
    corsoLezLabel=new QLabel("Corso Laurea:");
    corsoLezLineEdit = new QLineEdit();
    formLayout->addRow(corsoLezLabel, corsoLezLineEdit);


    //crediti
    creditiLabel=new QLabel("Crediti:");
    creditiLineEdit = new QLineEdit();
    creditiLineEdit->setValidator(new QIntValidator());
    formLayout->addRow(creditiLabel, creditiLineEdit);

    //stanza
    stanzaLabel=new QLabel("Stanza:");
    stanzaLineEdit = new QLineEdit();
    formLayout->addRow(stanzaLabel, stanzaLineEdit);

    //orario (?)(Vettore)
    orarioLabel=new QLabel("Orario Lezione:");
    orarioLineEdit = new QLineEdit();
    formLayout->addRow(orarioLabel, orarioLineEdit);

    //bottone
    lezioneLabel=new QLabel("Aggiungi Lezione:");
    lezioneButton= new QPushButton("Aggiungi");
    formLayout->addRow(lezioneLabel,lezioneButton);

    //Apre nuova finestra per inserimento ricerca
    connect(lezioneButton, SIGNAL(clicked()), this, SLOT(aggiungiLezione()));

    lezioneEliminaLabel=new QLabel("Elimina Lezione:");
    lezioneEliminaButton= new QPushButton("Elimina");
    formLayout->addRow(lezioneEliminaLabel,lezioneEliminaButton);

    //elimina ricerca
    connect(lezioneEliminaButton, SIGNAL(clicked()), this, SLOT(eliminaLezione()));

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
    ricercaLabel->setVisible(false);
    ricercaButton->setVisible(false);
    lezioneLabel->setVisible(false);
    lezioneButton->setVisible(false);
    ricercaEliminaLabel->setVisible(false);
    ricercaEliminaButton->setVisible(false);
    lezioneEliminaLabel->setVisible(false);
    lezioneEliminaButton->setVisible(false);

    //ricerca
    titoloLineEdit->setVisible(false);
    titoloLabel->setVisible(false);
    linkLineEdit->setVisible(false);
    linkLabel->setVisible(false);
    rivistaLineEdit->setVisible(false);
    rivistaLabel->setVisible(false);
    dataPubblicazioneEdit->setVisible(false);
    dataPubblicazioneLabel->setVisible(false);
    autoriLineEdit->setVisible(false);
    autoriLabel->setVisible(false);

    //lezione
    materiaLineEdit->setVisible(false);
    materiaLabel->setVisible(false);
    creditiLineEdit->setVisible(false);
    creditiLabel->setVisible(false);
    stanzaLineEdit->setVisible(false);
    stanzaLabel->setVisible(false);
    orarioLineEdit->setVisible(false);
    orarioLabel->setVisible(false);
   corsoLezLineEdit->setVisible(false);
  corsoLezLabel->setVisible(false);


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

    if(combo=="Studente"){
//campi
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
//lezione
      materiaLineEdit->setVisible(false);
      materiaLabel->setVisible(false);
      creditiLineEdit->setVisible(false);
      creditiLabel->setVisible(false);
      stanzaLineEdit->setVisible(false);
      stanzaLabel->setVisible(false);
      orarioLineEdit->setVisible(false);
      orarioLabel->setVisible(false);
     corsoLezLineEdit->setVisible(false);
    corsoLezLabel->setVisible(false);
//ricerca
    titoloLineEdit->setVisible(false);
    titoloLabel->setVisible(false);
    linkLineEdit->setVisible(false);
    linkLabel->setVisible(false);
    rivistaLineEdit->setVisible(false);
    rivistaLabel->setVisible(false);
    dataPubblicazioneEdit->setVisible(false);
    dataPubblicazioneLabel->setVisible(false);
    autoriLineEdit->setVisible(false);
    autoriLabel->setVisible(false);
//campi prof
      tipoLineEdit->setVisible(false);
      tipoLabel->setVisible(false);
     anniServizioLineEdit->setVisible(false);
     anniServizioLabel->setVisible(false);

     //ricerca e lezione
     ricercaLabel->setVisible(false);
     ricercaButton->setVisible(false);
     lezioneLabel->setVisible(false);
     lezioneButton->setVisible(false);
     lezioneEliminaLabel->setVisible(false);
     lezioneEliminaButton->setVisible(false);
     ricercaEliminaLabel->setVisible(false);
     ricercaEliminaButton->setVisible(false);

}
    if(combo=="Tutor"){
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
//ricerca
        titoloLineEdit->setVisible(false);
        titoloLabel->setVisible(false);
        linkLineEdit->setVisible(false);
        linkLabel->setVisible(false);
        rivistaLineEdit->setVisible(false);
        rivistaLabel->setVisible(false);
        dataPubblicazioneEdit->setVisible(false);
        dataPubblicazioneLabel->setVisible(false);
        autoriLineEdit->setVisible(false);
        autoriLabel->setVisible(false);
//campi prof
        tipoLineEdit->setVisible(false);
        tipoLabel->setVisible(false);
       anniServizioLineEdit->setVisible(false);
       anniServizioLabel->setVisible(false);
       //ricerca
       ricercaLabel->setVisible(false);
       ricercaButton->setVisible(false);
       ricercaEliminaLabel->setVisible(false);
       ricercaEliminaButton->setVisible(false);
//lezione
        lezioneLabel->setVisible(true);
        lezioneButton->setVisible(true);
        lezioneEliminaLabel->setVisible(true);
        lezioneEliminaButton->setVisible(true);
    }

    if(combo=="Professore"){
//campi studente e tutor
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
    //campi prof
    tipoLineEdit->setVisible(true);
     tipoLabel->setVisible(true);
    anniServizioLineEdit->setVisible(true);
      anniServizioLabel->setVisible(true);

      //ricerca e lezione
      ricercaLabel->setVisible(true);
      ricercaButton->setVisible(true);
      lezioneLabel->setVisible(true);
      lezioneButton->setVisible(true);
      lezioneEliminaLabel->setVisible(true);
      lezioneEliminaButton->setVisible(true);
      ricercaEliminaLabel->setVisible(true);
      ricercaEliminaButton->setVisible(true);

    }

}

void menudatiutente::aggiungiLezione()
{
    menulezione aggiungiLezione;
    if (aggiungiLezione.exec()) {
        materiaLineEdit->setVisible(true);
        materiaLabel->setVisible(true);
        creditiLineEdit->setVisible(true);
        creditiLabel->setVisible(true);
        stanzaLineEdit->setVisible(true);
        stanzaLabel->setVisible(true);
        orarioLineEdit->setVisible(true);
        orarioLabel->setVisible(true);
       corsoLezLineEdit->setVisible(true);
    corsoLezLabel->setVisible(true);
    }
}

void menudatiutente::aggiungiRicerca()
{
     menuricerca aggiungiRicerca;
     if (aggiungiRicerca.exec()) {
         titoloLineEdit->setVisible(true);
         titoloLabel->setVisible(true);
         linkLineEdit->setVisible(true);
         linkLabel->setVisible(true);
         rivistaLineEdit->setVisible(true);
         rivistaLabel->setVisible(true);
         dataPubblicazioneEdit->setVisible(true);
         dataPubblicazioneLabel->setVisible(true);
         autoriLineEdit->setVisible(true);
         autoriLabel->setVisible(true);
     }
}

void menudatiutente::eliminaLezione()
{
    materiaLineEdit->setVisible(false);
    materiaLabel->setVisible(false);
    creditiLineEdit->setVisible(false);
    creditiLabel->setVisible(false);
    stanzaLineEdit->setVisible(false);
    stanzaLabel->setVisible(false);
    orarioLineEdit->setVisible(false);
    orarioLabel->setVisible(false);
   corsoLezLineEdit->setVisible(false);
   corsoLezLabel->setVisible(false);
}

void menudatiutente::eliminaRicerca()
{
    titoloLineEdit->setVisible(false);
    titoloLabel->setVisible(false);
    linkLineEdit->setVisible(false);
    linkLabel->setVisible(false);
    rivistaLineEdit->setVisible(false);
    rivistaLabel->setVisible(false);
    dataPubblicazioneEdit->setVisible(false);
    dataPubblicazioneLabel->setVisible(false);
    autoriLineEdit->setVisible(false);
    autoriLabel->setVisible(false);

}
