#include "menudatiutente.h"

menudatiutente::menudatiutente(QWidget *parent) : QDialog(parent){
    setWindowTitle("Aggiungi utente");
    //setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    maindatiLayout = new QVBoxLayout();
    formLayoutUtente = new QFormLayout();

    tipoUtenteMenuComboBox = new QComboBox();
    tipoUtenteMenuComboBox->addItem(tr("Studente"));
    tipoUtenteMenuComboBox->addItem(tr("Professore"));
    tipoUtenteMenuComboBox->addItem(tr("Tutor"));
    formLayoutUtente->addRow(tr("Tipo Utente:"), tipoUtenteMenuComboBox);
    connect(tipoUtenteMenuComboBox, SIGNAL(currentIndexChanged(QString)), this,SLOT (showRow(QString)));

    //UTENTE
    //codice fiscale
    codiceFiscaleLabel=new QLabel("Codice Fiscale:");
    codiceFiscaleLineEdit = new QLineEdit();
    codiceFiscaleLineEdit->setInputMask("NNNNNNNNNNNNNNNN;");
    formLayoutUtente->addRow(codiceFiscaleLabel, codiceFiscaleLineEdit);

    //cognome
    cognomeLabel=new QLabel("Cognome:");
    cognomeLineEdit = new QLineEdit();
    formLayoutUtente->addRow(cognomeLabel, cognomeLineEdit);

    //nome
    nomeLabel=new QLabel("Nome:");
    nomeLineEdit = new QLineEdit();
    formLayoutUtente->addRow(nomeLabel, nomeLineEdit);

    //data di nascita
    dataNascitaLabel=new QLabel("Data di Nascita:");
    dataNascitaEdit = new QDateEdit();
    dataNascitaEdit->setCalendarPopup(true);
    formLayoutUtente->addRow(dataNascitaLabel, dataNascitaEdit);

    //email
    emailLabel=new QLabel("Email:");
    emailLineEdit = new QLineEdit();
    formLayoutUtente->addRow(emailLabel, emailLineEdit);

    //telefono
    telefonoLabel=new QLabel("Telefono:");
    telefonoLineEdit = new QLineEdit();
    telefonoLineEdit->setInputMask("+99 9999999999;");
    formLayoutUtente->addRow(telefonoLabel, telefonoLineEdit);

    //cap
    capLabel=new QLabel("CAP:");
    capLineEdit = new QLineEdit();
    capLineEdit->setValidator(new QIntValidator(this));
    formLayoutUtente->addRow(capLabel, capLineEdit);

    //regione
    regioneLabel=new QLabel("Regione:");
    regioneLineEdit = new QLineEdit();
    formLayoutUtente->addRow(regioneLabel, regioneLineEdit);

    //comune
    comuneLabel=new QLabel("Comune:");
    comuneLineEdit = new QLineEdit();
    formLayoutUtente->addRow(comuneLabel, comuneLineEdit);

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
    formLayoutStudente=new QFormLayout();

    //STUDENTE
    //matricola
    matricolaLabel=new QLabel("Matricola:");
    matricolaLineEdit = new QLineEdit();
    matricolaLineEdit->setValidator(new QIntValidator(this));
    formLayoutStudente->addRow(matricolaLabel, matricolaLineEdit);

    //laurea
    laureaLabel=new QLabel("Laurea:");
    laureaMenuComboBox=new QComboBox();
    laureaMenuComboBox->addItem("Triennale");
    laureaMenuComboBox->addItem("Magistrale");
    laureaMenuComboBox->addItem("Diploma Specializzazione");
    laureaMenuComboBox->addItem("Dottorato Ricerca");
    formLayoutStudente->addRow(laureaLabel, laureaMenuComboBox);

    //corso
    corsoLabel=new QLabel("Corso:");
    corsoLineEdit = new QLineEdit();
    formLayoutStudente->addRow(corsoLabel, corsoLineEdit);

    //annocorso
    annocorsoLabel=new QLabel("Anno Corso:");
    annocorsoLineEdit = new QLineEdit();
    annocorsoLineEdit->setValidator(new QIntValidator(this));
    formLayoutStudente->addRow(annocorsoLabel, annocorsoLineEdit);

    //iscrizione
    dataIscrizioneLabel=new QLabel("Data di Iscrizione:");
    dataIscrizioneEdit = new QDateEdit();
    dataIscrizioneEdit->setCalendarPopup(true);
    formLayoutStudente->addRow(dataIscrizioneLabel, dataIscrizioneEdit);

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
    formLayoutProf=new QFormLayout();

    //PROFESSORE
    //tipo
    tipoLabel=new QLabel("Tipo:");
    tipoLineEdit = new QLineEdit();
    formLayoutProf->addRow(tipoLabel, tipoLineEdit);

    //anni servizio
    anniServizioLabel=new QLabel("Anni Servizio:");
    anniServizioLineEdit = new QLineEdit();
    anniServizioLineEdit->setValidator(new QIntValidator(this));
    formLayoutProf->addRow(anniServizioLabel, anniServizioLineEdit);

    maindatiLayout->addLayout(formLayoutProf);

    //Ricerca
    aggRimuoviRicercaLayout = new QHBoxLayout();

    ricercaAggiungiButton= new QPushButton("Aggiungi Ricerca");
    aggRimuoviRicercaLayout->addWidget(ricercaAggiungiButton);

    ricercaModificaButton = new QPushButton("Modifica Ricerca");
    aggRimuoviRicercaLayout->addWidget(ricercaModificaButton);

    ricercaEliminaButton= new QPushButton("Elimina");
    aggRimuoviRicercaLayout->addWidget(ricercaEliminaButton);

    ricTableLayout = new QHBoxLayout();
    modelloRicerche = new ricerchetablemodel(this);
    ricercheTableView = new QTableView();
    ricercheTableView->setModel(modelloRicerche);
    ricercheTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ricercheTableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    ricercheTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
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
    aggRimuoviLezioneLayout->addWidget(lezioneModificaButton);

    connect(lezioneModificaButton, SIGNAL(clicked()), this, SLOT(modificaLezione()));


    lezioneEliminaButton= new QPushButton("Elimina Lezione");
    aggRimuoviLezioneLayout->addWidget(lezioneEliminaButton);

    //elimina lezione
    connect(lezioneEliminaButton, SIGNAL(clicked()), this, SLOT(eliminaLezione()));

    lezTableLayout = new QHBoxLayout();
    modelloLezioni = new lezionitablemodel(this);
    lezioniTableView = new QTableView();
    lezioniTableView->setModel(modelloLezioni);
    lezioniTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    lezioniTableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    lezioniTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //Seleziona una riga al posto di una singola cella
    lezioniTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    lezTableLayout->addWidget(lezioniTableView);

    maindatiLayout->addLayout(aggRimuoviLezioneLayout);
    maindatiLayout->addLayout(lezTableLayout);

    connect(lezioniTableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(modificaLezione(QModelIndex)));

    //aggiungi, annulla e cancella
    bottoniLayout = new QHBoxLayout();

    aggiungiMenuButton= new QPushButton("Aggiungi");
    cancellaMenuButton= new QPushButton("Cancella tutto");
    annullaMenuButton= new QPushButton("Annulla inserimento");

    bottoniLayout->addWidget(aggiungiMenuButton);
    bottoniLayout->addWidget(cancellaMenuButton);
    bottoniLayout->addWidget(annullaMenuButton);

    maindatiLayout->addLayout(bottoniLayout);

    connect(annullaMenuButton,SIGNAL(clicked()),this,SLOT(reject()));
    connect(aggiungiMenuButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(cancellaMenuButton, SIGNAL(clicked()), this, SLOT(clear()));

    setLayout(maindatiLayout);

    //Inizializza i campi nascosti mettendo l'indice a 0
    showRow("Studente");
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

        //campi prof
        tipoLineEdit->setVisible(false);
        tipoLabel->setVisible(false);
        anniServizioLineEdit->setVisible(false);
        anniServizioLabel->setVisible(false);

        //ricerca
        ricercaAggiungiButton->setVisible(false);
        ricercaEliminaButton->setVisible(false);
        ricercheTableView->setVisible(false);
        ricercaModificaButton->setVisible(false);
    }
    if(combo=="Tutor" || combo =="Professore"){
        //lezione
        lezioneAggiungiButton->setVisible(true);
        lezioneEliminaButton->setVisible(true);
        lezioniTableView->setVisible(true);
        lezioneModificaButton->setVisible(true);
    }else{
        lezioneAggiungiButton->setVisible(false);
        lezioneEliminaButton->setVisible(false);
        lezioniTableView->setVisible(false);
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

        //campi prof
        tipoLineEdit->setVisible(true);
        tipoLabel->setVisible(true);
        anniServizioLineEdit->setVisible(true);
        anniServizioLabel->setVisible(true);

        //ricerca e lezione
        ricercaAggiungiButton->setVisible(true);
        ricercaEliminaButton->setVisible(true);
        ricercheTableView->setVisible(true);
        ricercaModificaButton->setVisible(true);
    }
    resize(sizeHint());
}

void menudatiutente::modificaLezione(const QModelIndex &index){
    QString materia;
    int crediti;
    QString corso;
    QString stanza;
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
    menulezione modifica;
    modifica.setWindowTitle(tr("Modifica lezione"));
    modifica.materiaLineEdit->setText(materia);
    modifica.corsoLineEdit->setText(corso);
    modifica.stanzaLineEdit->setText(stanza);
    modifica.creditiLineEdit->setText(QString::number(crediti));

    if (modifica.exec()) {
        materia = modifica.materiaLineEdit->text();
        crediti = modifica.creditiLineEdit->text().toInt();
        corso = modifica.corsoLineEdit->text();
        stanza = modifica.stanzaLineEdit->text();

        lezione lez(materia.toStdString(), corso.toStdString(), stanza.toStdString(), crediti);
        if (!modelloLezioni->contains(lez)) {
            QModelIndex index = modelloLezioni->index(row, 0, QModelIndex());
            modelloLezioni->setData(index, materia, Qt::EditRole);
            index = modelloLezioni->index(row, 1, QModelIndex());
            modelloLezioni->setData(index, corso, Qt::EditRole);
            index = modelloLezioni->index(row, 2, QModelIndex());
            modelloLezioni->setData(index, stanza, Qt::EditRole);
            index = modelloLezioni->index(row, 3, QModelIndex());
            modelloLezioni->setData(index, crediti, Qt::EditRole);
            //index = table->index(0, 1, QModelIndex());
            //modelloLezioni->setData(index, orari, Qt::EditRole);
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
            //index = table->index(0, 1, QModelIndex());
            //modelloLezioni->setData(index, orari, Qt::EditRole);
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


