#include "menudatiutente.h"

menudatiutente::menudatiutente(QWidget *parent) : QDialog(parent){
    setWindowTitle("Aggiungi utente");
    maindatiLayout = new QVBoxLayout();
    formLayoutUtente = new QGridLayout();

    tipoUtenteComboboxLabel = new QLabel("Tipo Utente:");
    tipoUtenteMenuComboBox = new QComboBox();
    tipoUtenteMenuComboBox->addItem(tr("Studente"));
    tipoUtenteMenuComboBox->addItem(tr("Professore"));
    tipoUtenteMenuComboBox->addItem(tr("Tutor"));
    formLayoutUtente->addWidget(tipoUtenteComboboxLabel, 0, 0);
    formLayoutUtente->addWidget(tipoUtenteMenuComboBox, 0, 1);

    connect(tipoUtenteMenuComboBox, SIGNAL(currentIndexChanged(QString)), this,SLOT (showRow(QString)));

    //UTENTE
    //codice fiscale
    codiceFiscaleLabel=new QLabel("Codice Fiscale:");
    codiceFiscaleLineEdit = new QLineEdit();
    QRegularExpression rx1("^[A-Z]{6}[0-9]{2}[A-Z][0-9]{2}[A-Z][0-9]{3}[A-Z]$");
    QValidator *validator1 = new QRegularExpressionValidator(rx1, this);
    codiceFiscaleLineEdit->setValidator(validator1);
    formLayoutUtente->addWidget(codiceFiscaleLabel, 1, 0);
    formLayoutUtente->addWidget(codiceFiscaleLineEdit, 1, 1);

    //cognome
    cognomeLabel=new QLabel("Cognome:");
    cognomeLineEdit = new QLineEdit();
    formLayoutUtente->addWidget(cognomeLabel, 2, 0);
    formLayoutUtente->addWidget(cognomeLineEdit, 2, 1);

    //nome
    nomeLabel=new QLabel("Nome:");
    nomeLineEdit = new QLineEdit();
    formLayoutUtente->addWidget(nomeLabel, 3, 0);
    formLayoutUtente->addWidget(nomeLineEdit, 3, 1);

    //data di nascita
    dataNascitaLabel=new QLabel("Data di Nascita:");
    dataNascitaEdit = new QDateEdit();
    dataNascitaEdit->setDisplayFormat("MMMM.dd.yyyy");
    dataNascitaEdit->setCalendarPopup(true);
    formLayoutUtente->addWidget(dataNascitaLabel, 4, 0);
    formLayoutUtente->addWidget(dataNascitaEdit, 4, 1);

    //email
    emailLabel=new QLabel("Email:");
    emailLineEdit = new QLineEdit();
    formLayoutUtente->addWidget(emailLabel, 5, 0);
    formLayoutUtente->addWidget(emailLineEdit, 5, 1);

    //telefono
    telefonoLabel=new QLabel("Telefono:");
    telefonoLineEdit = new QLineEdit();
    QRegularExpression rx2("^((00|\\+)39[\\. ]\?\?)\?\?3\\d{2}[\\. ]\?\?\\d{6,7}$");
    QValidator *validator2 = new QRegularExpressionValidator(rx2, this);
    telefonoLineEdit->setValidator(validator2);
    telefonoLineEdit->setPlaceholderText("+39 0000000000");
    formLayoutUtente->addWidget(telefonoLabel, 6, 0);
    formLayoutUtente->addWidget(telefonoLineEdit, 6, 1);

    //cap
    capLabel=new QLabel("CAP:");
    capLineEdit = new QLineEdit();
    capLineEdit->setValidator(new QIntValidator(this));
    formLayoutUtente->addWidget(capLabel, 7, 0);
    formLayoutUtente->addWidget(capLineEdit, 7, 1);

    //regione
    regioneLabel=new QLabel("Regione:");
    regioneLineEdit = new QLineEdit();
    formLayoutUtente->addWidget(regioneLabel, 8, 0);
    formLayoutUtente->addWidget(regioneLineEdit, 8, 1);

    //comune
    comuneLabel=new QLabel("Comune:");
    comuneLineEdit = new QLineEdit();
    formLayoutUtente->addWidget(comuneLabel, 9, 0);
    formLayoutUtente->addWidget(comuneLineEdit, 9, 1);

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

    maindatiLayout->addLayout(formLayoutUtente);
    maindatiLayout->addLayout(vnLayout);

    //riprendo layout
    formLayoutStudente=new QGridLayout();
    //STUDENTE
    //matricola
    matricolaLabel=new QLabel("Matricola:");
    matricolaLineEdit = new QLineEdit();
    matricolaLineEdit->setValidator(new QIntValidator(this));
    formLayoutStudente->addWidget(matricolaLabel, 0, 0);
    formLayoutStudente->addWidget(matricolaLineEdit, 0, 1);

    //laurea
    laureaLabel=new QLabel("Laurea:");
    laureaMenuComboBox=new QComboBox();
    laureaMenuComboBox->addItem("Triennale");
    laureaMenuComboBox->addItem("Magistrale");
    laureaMenuComboBox->addItem("Diploma Specializzazione");
    laureaMenuComboBox->addItem("Dottorato Ricerca");
    formLayoutStudente->addWidget(laureaLabel, 1, 0);
    formLayoutStudente->addWidget(laureaMenuComboBox, 1, 1);

    //corso
    corsoLabel=new QLabel("Corso:");
    corsoLineEdit = new QLineEdit();
    formLayoutStudente->addWidget(corsoLabel, 2, 0);
    formLayoutStudente->addWidget(corsoLineEdit, 2, 1);

    //annocorso
    annocorsoLabel=new QLabel("Anno Corso:");
    annocorsoLineEdit = new QLineEdit();
    annocorsoLineEdit->setValidator(new QIntValidator(this));
    formLayoutStudente->addWidget(annocorsoLabel, 3, 0);
    formLayoutStudente->addWidget(annocorsoLineEdit, 3, 1);

    //iscrizione
    dataIscrizioneLabel=new QLabel("Data di Iscrizione:");
    dataIscrizioneEdit = new QDateEdit();
    dataIscrizioneEdit->setDisplayFormat("MMMM.dd.yyyy");
    dataIscrizioneEdit->setCalendarPopup(true);
    formLayoutStudente->addWidget(dataIscrizioneLabel, 4, 0);
    formLayoutStudente->addWidget(dataIscrizioneEdit, 4, 1);

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

    maindatiLayout->addLayout(formLayoutStudente);
    maindatiLayout->addLayout(fuoriLayout);

    //riprendo layout
    formLayoutProf=new QGridLayout();

    //PROFESSORE
    //tipo
    tipoLabel=new QLabel("Tipo:");
    tipoLineEdit = new QLineEdit();
    formLayoutProf->addWidget(tipoLabel, 0, 0);
    formLayoutProf->addWidget(tipoLineEdit, 0, 1);

    //anni servizio
    anniServizioLabel=new QLabel("Anni Servizio:");
    anniServizioLineEdit = new QLineEdit();
    anniServizioLineEdit->setValidator(new QIntValidator(this));
    formLayoutProf->addWidget(anniServizioLabel, 1, 0);
    formLayoutProf->addWidget(anniServizioLineEdit, 1, 1);

    maindatiLayout->addLayout(formLayoutProf);

    //Ricerca
    aggRimuoviRicercaLayout = new QHBoxLayout();

    ricercaAggiungiButton= new QPushButton("Aggiungi Ricerca");
    aggRimuoviRicercaLayout->addWidget(ricercaAggiungiButton);

    ricercaModificaButton = new QPushButton("Modifica Ricerca");
    ricercaModificaButton->setEnabled(false);
    aggRimuoviRicercaLayout->addWidget(ricercaModificaButton);

    ricercaEliminaButton= new QPushButton("Elimina");
    ricercaEliminaButton->setEnabled(false);
    aggRimuoviRicercaLayout->addWidget(ricercaEliminaButton);

    ricTableLayout = new QHBoxLayout();
    modelloRicerche = new ricerchetablemodel(this);
    ricercheTableView = new QTableView();
    ricercheTableView->setModel(modelloRicerche);
    ricercheTableView->hideColumn(2);
    ricercheTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ricercheTableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    ricercheTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    //Seleziona una riga al posto di una singola cella
    ricercheTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ricTableLayout->addWidget(ricercheTableView);




    //elimina ricerca
    connect(ricercaEliminaButton, SIGNAL(clicked()), this, SLOT(eliminaRicerca()));

    //Apre nuova finestra per inserimento ricerca
    connect(ricercaAggiungiButton, SIGNAL(clicked()), this, SLOT(aggiungiRicerca()));

    //Modifica ricerca
    connect(ricercheTableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(modificaRicerca(QModelIndex)));
    connect(ricercaModificaButton, SIGNAL(clicked()), this, SLOT(modificaRicerca()));

    maindatiLayout->addLayout(aggRimuoviRicercaLayout);
    maindatiLayout->addLayout(ricTableLayout);

    //LEZIONE

    aggRimuoviLezioneLayout = new QHBoxLayout();

    lezioneAggiungiButton= new QPushButton("Aggiungi Lezione");
    aggRimuoviLezioneLayout->addWidget(lezioneAggiungiButton);

    //Apre nuova finestra per inserimento ricerca
    connect(lezioneAggiungiButton, SIGNAL(clicked()), this, SLOT(aggiungiLezione()));


    lezioneModificaButton= new QPushButton("Modifica Lezione");
    lezioneModificaButton->setEnabled(false);
    aggRimuoviLezioneLayout->addWidget(lezioneModificaButton);

    connect(lezioneModificaButton, SIGNAL(clicked()), this, SLOT(modificaLezione()));


    lezioneEliminaButton= new QPushButton("Elimina Lezione");
    lezioneEliminaButton->setEnabled(false);
    aggRimuoviLezioneLayout->addWidget(lezioneEliminaButton);

    //elimina lezione
    connect(lezioneEliminaButton, SIGNAL(clicked()), this, SLOT(eliminaLezione()));

    //inizialmente disabilitati

    lezTableLayout = new QHBoxLayout();
    modelloLezioni = new lezionitablemodel(this);
    lezioniTableView = new QTableView();
    oraridelegate = new comboboxdelegate(lezioniTableView);
    lezioniTableView->setModel(modelloLezioni);
    lezioniTableView->setItemDelegateForColumn(4,oraridelegate);
    lezioniTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    lezioniTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    lezioniTableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    //Seleziona una riga al posto di una singola cella
    lezioniTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    lezTableLayout->addWidget(lezioniTableView);

    maindatiLayout->addLayout(aggRimuoviLezioneLayout);
    maindatiLayout->addLayout(lezTableLayout);

    connect(lezioniTableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(modificaLezione(QModelIndex)));

    //connessione disabilitare modifica
    connect(lezioniTableView->selectionModel(),SIGNAL(selectionChanged(QItemSelection,QItemSelection)) ,this, SLOT(aggiornalezioneAzioni(QItemSelection,QItemSelection)));
    connect(ricercheTableView->selectionModel(),SIGNAL(selectionChanged(QItemSelection,QItemSelection)) ,this, SLOT(aggiornaricercaAzioni(QItemSelection,QItemSelection)));

    //aggiungi, annulla e cancella
    bottoniLayout = new QHBoxLayout();

    aggiungiMenuButton= new QPushButton("Aggiungi");
    annullaMenuButton= new QPushButton("Annulla inserimento");

    bottoniLayout->addWidget(aggiungiMenuButton);
    bottoniLayout->addWidget(annullaMenuButton);

    maindatiLayout->addLayout(bottoniLayout);

    connect(annullaMenuButton,SIGNAL(clicked()),this,SLOT(reject()));
    connect(aggiungiMenuButton, SIGNAL(clicked()), this, SLOT(accept()));

    setLayout(maindatiLayout);
}

void menudatiutente::showRow(QString combo){
    if(combo=="Studente" || combo =="Tutor"){
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
        formLayoutStudente->activate();

        //campi prof
        tipoLineEdit->setVisible(false);
        tipoLabel->setVisible(false);
        anniServizioLineEdit->setVisible(false);
        anniServizioLabel->setVisible(false);
        formLayoutProf->invalidate();

        //ricerca
        ricercaAggiungiButton->setVisible(false);
        ricercaEliminaButton->setVisible(false);
        ricercheTableView->setVisible(false);
        ricercaModificaButton->setVisible(false);
        ricTableLayout->invalidate();
    }
    if(combo=="Tutor" || combo =="Professore"){
        //lezione
        lezioneAggiungiButton->setVisible(true);
        lezioneEliminaButton->setVisible(true);
        lezioniTableView->setVisible(true);
        lezioneModificaButton->setVisible(true);
        lezTableLayout->activate();
    }else{
        lezioneAggiungiButton->setVisible(false);
        lezioneEliminaButton->setVisible(false);
        lezioneModificaButton->setVisible(false);
        lezioniTableView->setVisible(false);
        lezTableLayout->invalidate();
    }
    if(combo=="Professore"){
        //matricola
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
        formLayoutStudente->invalidate();

        //campi prof
        tipoLineEdit->setVisible(true);
        tipoLabel->setVisible(true);
        anniServizioLineEdit->setVisible(true);
        anniServizioLabel->setVisible(true);
        formLayoutProf->activate();

        //ricerca e lezione
        ricercaAggiungiButton->setVisible(true);
        ricercaEliminaButton->setVisible(true);
        ricercheTableView->setVisible(true);
        ricercaModificaButton->setVisible(true);
        ricTableLayout->activate();
    }
    if(combo == "Professore"){
        ricercheTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        ricercheTableView->setMinimumSize(ricercheTableView->sizeHint());
    }
    if(combo == "Professore" || combo == "Tutor"){
        lezioniTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        lezioniTableView->setMinimumSize(lezioniTableView->sizeHint());
        QSize tmp = sizeHint();
        tmp.setWidth(tmp.width()+10);
        setMinimumSize(tmp);
        resize(sizeHint());
    }else{
        lezioniTableView->setMinimumSize(0,0);
        ricercheTableView->setMinimumSize(0,0);
        adjustSize();
    }
    if(combo == "Professore"){
        ricercheTableView->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
    }
    if(combo == "Professore" || combo == "Tutor"){
        lezioniTableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
        lezioniTableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
        lezioniTableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    }
}

int menudatiutente::exec(){
    //Inizializza i campi nascosti mettendo l'indice a 0
    showRow(tipoUtenteMenuComboBox->currentText());
    return QDialog::exec();
}



void menudatiutente::accept()
{
    if(codiceFiscaleLineEdit->text().isEmpty()){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Errore: Non hai inserito il campo codice fiscale!");
        messageBox.setFixedSize(500,200);
    }
    else if(nomeLineEdit->text().isEmpty()){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Errore: Non hai inserito il campo nome!");
        messageBox.setFixedSize(500,200);
    }
    else if(cognomeLineEdit->text().isEmpty()){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Errore: Non hai inserito il campo cognome!");
        messageBox.setFixedSize(500,200);
    }
    else if(emailLineEdit->text().isEmpty()){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Errore: Non hai inserito il campo email!");
        messageBox.setFixedSize(500,200);
    }
    else if(telefonoLineEdit->text().isEmpty()){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Errore: Non hai inserito il campo telefono!");
        messageBox.setFixedSize(500,200);
    }
    else if( tipoUtenteMenuComboBox->currentText()!="Professore" && matricolaLineEdit->text().isEmpty()){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Errore: Non hai inserito il campo matricola!");
        messageBox.setFixedSize(500,200);
    }
    else
        QDialog::accept();
}

void menudatiutente::modificaLezione(const QModelIndex &index){
    QString materia;
    int crediti;
    QString corso;
    QString stanza;
    QStringList orari;

    int row;

    if(!index.isValid()){
        //Se sono selezionate più righe modifica la prima
        QModelIndexList indexes = lezioniTableView->selectionModel()->selectedRows();
        row = indexes.at(0).row();
    }else{
        row = index.row();
    }
    QModelIndex materiaIndex = modelloLezioni->index(row, 0, QModelIndex());
    materia = modelloLezioni->data(materiaIndex, Qt::DisplayRole).toString();
    QModelIndex corsoIndex = modelloLezioni->index(row, 1, QModelIndex());
    corso = modelloLezioni->data(corsoIndex, Qt::DisplayRole).toString();
    QModelIndex stanzaIndex = modelloLezioni->index(row, 2, QModelIndex());
    stanza = modelloLezioni->data(stanzaIndex, Qt::DisplayRole).toString();
    QModelIndex creditiIndex = modelloLezioni->index(row, 3, QModelIndex());
    crediti = modelloLezioni->data(creditiIndex, Qt::DisplayRole).toInt();
    QModelIndex orariIndex = modelloLezioni->index(row, 4, QModelIndex());
    orari = modelloLezioni->data(orariIndex, Qt::DisplayRole).toStringList();

    menulezione modifica;
    modifica.setWindowTitle(tr("Modifica lezione"));
    modifica.aggiungiLezioneButton->setText("Modifica");
    modifica.materiaLineEdit->setText(materia);
    modifica.corsoLineEdit->setText(corso);
    modifica.stanzaLineEdit->setText(stanza);
    modifica.creditiLineEdit->setText(QString::number(crediti));
    modifica.combo->setVisible(true);
    modifica.eliminaOrarioButton->setVisible(true);
    modifica.combo->addItems(orari);

    if (modifica.exec()) {

        materia = modifica.materiaLineEdit->text();
        crediti = modifica.creditiLineEdit->text().toInt();
        corso = modifica.corsoLineEdit->text();
        stanza = modifica.stanzaLineEdit->text();
        orari.clear();
        for(int i=0; i<modifica.combo->count(); i++){
            orari<<modifica.combo->itemText(i);
        }

        lezione lez(materia.toStdString(), corso.toStdString(), stanza.toStdString(), crediti);
        QStringList tmp2;
        QString tmpstring;
        QRegExp rx("[ ]");
        string oraInizio;
        string oraFine;
        DayOfWeek giornoSettimana;
        for(QStringList::const_iterator it = orari.begin(); it!=orari.end(); ++it){
            tmpstring = (*it);
            tmp2 = tmpstring.split(rx, QString::SkipEmptyParts);
            oraInizio = tmp2[0].toStdString();
            oraFine = tmp2[2].toStdString();
            giornoSettimana = lezione::toDayOfWeek(tmp2[3].toStdString());
            lez.addGiornoLezione(oraInizio, oraFine, giornoSettimana);
        }

        if (!modelloLezioni->contains(lez)) {
            QModelIndex index = modelloLezioni->index(row, 0, QModelIndex());
            modelloLezioni->setData(index, materia, Qt::EditRole);
            index = modelloLezioni->index(row, 1, QModelIndex());
            modelloLezioni->setData(index, corso, Qt::EditRole);
            index = modelloLezioni->index(row, 2, QModelIndex());
            modelloLezioni->setData(index, stanza, Qt::EditRole);
            index = modelloLezioni->index(row, 3, QModelIndex());
            modelloLezioni->setData(index, crediti, Qt::EditRole);
            index = modelloLezioni->index(row, 4, QModelIndex());
            modelloLezioni->setData(index, orari, Qt::EditRole);
        }
    }

}
void menudatiutente::modificaRicerca(const QModelIndex &index){
    QString autori;
    QString titolo;
    QString link;
    QString rivista;
    int anno;
    int row;
    if(!index.isValid()){
        //Se sono selezionate più righe modifica la prima
        QModelIndexList indexes = ricercheTableView->selectionModel()->selectedRows();
        row = indexes.at(0).row();
    }else{
        row = index.row();
    }
    QModelIndex autoriIndex = modelloRicerche->index(row, 0, QModelIndex());
    autori = modelloRicerche->data(autoriIndex, Qt::DisplayRole).toString();
    QModelIndex titoloIndex = modelloRicerche->index(row, 1, QModelIndex());
    titolo = modelloRicerche->data(titoloIndex, Qt::DisplayRole).toString();
    QModelIndex linkIndex = modelloRicerche->index(row, 2, QModelIndex());
    link = modelloRicerche->data(linkIndex, Qt::DisplayRole).toString();
    QModelIndex rivistaIndex = modelloRicerche->index(row, 3, QModelIndex());
    rivista = modelloRicerche->data(rivistaIndex, Qt::DisplayRole).toString();
    QModelIndex annoIndex = modelloRicerche->index(row, 4, QModelIndex());
    anno = modelloRicerche->data(annoIndex, Qt::DisplayRole).toInt();

    menuricerca modifica;
    modifica.setWindowTitle(tr("Modifica ricerca"));
    modifica.aggiungiRicercaButton->setText("Modifica");
    modifica.autoriLineEdit->setText(autori);
    modifica.titoloLineEdit->setText(titolo);
    modifica.linkLineEdit->setText(link);
    modifica.rivistaLineEdit->setText(rivista);
    modifica.dataPubblicazioneLineEdit->setText(QString::number(anno));

    if (modifica.exec()) {

        autori = modifica.autoriLineEdit->text();
        titolo = modifica.titoloLineEdit->text();
        link = modifica.linkLineEdit->text();
        rivista = modifica.rivistaLineEdit->text();
        anno = modifica.dataPubblicazioneLineEdit->text().toInt();

        ricerca ric(autori.toStdString(), titolo.toStdString(), link.toStdString(), rivista.toStdString(), anno);
        if (!modelloRicerche->contains(ric)) {
            QModelIndex index = modelloRicerche->index(row, 0, QModelIndex());
            modelloRicerche->setData(index, autori, Qt::EditRole);
            index = modelloRicerche->index(row, 1, QModelIndex());
            modelloRicerche->setData(index, titolo, Qt::EditRole);
            index = modelloRicerche->index(row, 2, QModelIndex());
            modelloRicerche->setData(index, link, Qt::EditRole);
            index = modelloRicerche->index(row, 3, QModelIndex());
            modelloRicerche->setData(index, rivista, Qt::EditRole);
            index = modelloRicerche->index(row, 4, QModelIndex());
            modelloRicerche->setData(index, anno, Qt::EditRole);
        }
    }
}

void menudatiutente::aggiungiLezione(){
    menulezione aggiungiLezione;

    if (aggiungiLezione.exec()) {
        QString materia = aggiungiLezione.materiaLineEdit->text();
        int crediti = aggiungiLezione.creditiLineEdit->text().toInt();
        QString corso = aggiungiLezione.corsoLineEdit->text();
        QString stanza = aggiungiLezione.stanzaLineEdit->text();
        QStringList orario;
        for(int i=0; i<aggiungiLezione.combo->count(); i++){
            orario<<aggiungiLezione.combo->itemText(i);
        }
        lezione lez(materia.toStdString(), corso.toStdString(), stanza.toStdString(), crediti);
        if (!modelloLezioni->contains(lez)) {
            modelloLezioni->insertRows(0, 1, QModelIndex());

            QModelIndex index = modelloLezioni->index(0, 0, QModelIndex());
            modelloLezioni->setData(index, materia, Qt::EditRole);
            index = modelloLezioni->index(0, 1, QModelIndex());
            modelloLezioni->setData(index, corso, Qt::EditRole);
            index = modelloLezioni->index(0, 2, QModelIndex());
            modelloLezioni->setData(index, stanza, Qt::EditRole);
            index = modelloLezioni->index(0, 3, QModelIndex());
            modelloLezioni->setData(index, crediti, Qt::EditRole);
            index = modelloLezioni->index(0, 4, QModelIndex());
            modelloLezioni->setData(index, orario, Qt::EditRole);
            lezioniTableView->openPersistentEditor(modelloLezioni->index(0,4));
        }
    }
}

void menudatiutente::aggiungiRicerca(){
    menuricerca aggiungiRicerca;
    if (aggiungiRicerca.exec()) {

        QString autori = aggiungiRicerca.autoriLineEdit->text();
        int anno = aggiungiRicerca.dataPubblicazioneLineEdit->text().toInt();
        QString titolo = aggiungiRicerca.titoloLineEdit->text();
        QString link = aggiungiRicerca.linkLineEdit->text();
        QString rivista = aggiungiRicerca.rivistaLineEdit->text();

        ricerca ric(autori.toStdString(), titolo.toStdString(), link.toStdString(), rivista.toStdString(), anno);
        if (!modelloRicerche->contains(ric)) {
            modelloRicerche->insertRows(0, 1, QModelIndex());

            QModelIndex index = modelloRicerche->index(0, 0, QModelIndex());
            modelloRicerche->setData(index, autori, Qt::EditRole);
            index = modelloRicerche->index(0, 1, QModelIndex());
            modelloRicerche->setData(index, titolo, Qt::EditRole);
            index = modelloRicerche->index(0, 2, QModelIndex());
            modelloRicerche->setData(index, link, Qt::EditRole);
            index = modelloRicerche->index(0, 3, QModelIndex());
            modelloRicerche->setData(index, rivista, Qt::EditRole);
            index = modelloRicerche->index(0, 4, QModelIndex());
            modelloRicerche->setData(index, anno, Qt::EditRole);
        }
    }
}

void menudatiutente::eliminaLezione(){
    QItemSelectionModel *selectionModel = lezioniTableView->selectionModel();
    QList<int> rows;
    foreach (QModelIndex index, selectionModel->selectedRows()){
        rows.append(index.row());
    }
    //Ordina la lista di righe in ordine decrescende, così da
    //non modificare gli indici successivi a quello rimosso e
    //non saper più che elemento rimuovere (Solo per rimozioni multiple)
    std::sort(rows.rbegin(), rows.rend());
    foreach(int row, rows){
        modelloLezioni->removeRows(row, 1, QModelIndex());
    }
}

void menudatiutente::eliminaRicerca(){
    QItemSelectionModel *selectionModel = ricercheTableView->selectionModel();
    QList<int> rows;
    foreach (QModelIndex index, selectionModel->selectedRows()){
        rows.append(index.row());
    }
    //Ordina la lista di righe in ordine decrescende, così da
    //non modificare gli indici successivi a quello rimosso e
    //non saper più che elemento rimuovere (Solo per rimozioni multiple)
    std::sort(rows.rbegin(), rows.rend());
    foreach(int row, rows){
        modelloRicerche->removeRows(row, 1, QModelIndex());
    }
}

//Disabilita il pulsante di rimozione utente se nessuna riga è selezionata
void menudatiutente::aggiornalezioneAzioni(const QItemSelection &selected , const QItemSelection &deselected){
    Q_UNUSED(deselected);
    QModelIndexList indexes = selected.indexes();
    if (!indexes.isEmpty()) {
        lezioneEliminaButton->setEnabled(true);
        lezioneModificaButton->setEnabled(true);
    } else {
        lezioneEliminaButton->setEnabled(false);
        lezioneModificaButton->setEnabled(false);
    }

}

void menudatiutente::aggiornaricercaAzioni(const QItemSelection &selected, const QItemSelection &deselected)
{
    Q_UNUSED(deselected);
    QModelIndexList indexes = selected.indexes();
    if (!indexes.isEmpty()) {
        ricercaEliminaButton->setEnabled(true);
        ricercaModificaButton->setEnabled(true);
    } else {
        ricercaEliminaButton->setEnabled(false);
        ricercaModificaButton->setEnabled(false);
    }
}






