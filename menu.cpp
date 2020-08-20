#include "menu.h"

menu::menu(tablemodel *_model, QWidget *parent)
    : QWidget(parent){
    mainLayout = new QVBoxLayout(this);

    //Chiusura
    addCLose();

    //Bottoni di aggiunta / rimozione utenti
    aggiungiRimuoviButtonsLayout = new QHBoxLayout();
    aggiungiButton= new QPushButton("Aggiungi utente");
    rimuoviButton= new QPushButton("Rimuovi utente");
    rimuoviButton->setEnabled(false);
    aggiungiRimuoviButtonsLayout->addWidget(aggiungiButton);
    aggiungiRimuoviButtonsLayout->addWidget(rimuoviButton);
    mainLayout->addLayout(aggiungiRimuoviButtonsLayout);
        
    //Apre nuova finestra per inserimento dati utente
    connect(aggiungiButton, SIGNAL(clicked()), this, SLOT(aggiungiExec()));
    //Rimuove l'utente selezionato
    connect(rimuoviButton, SIGNAL(clicked()), this, SLOT(rimuoviUtente()));

    //Ricerca per campi
    ricercaLayout = new QHBoxLayout();
    cercaLabel = new QLabel("Cerca");
    perLabel = new QLabel("Per");
    cercaLineEdit = new QLineEdit();
    colonnaRicercaComboBox = new QComboBox();

    ricercaLayout->addWidget(cercaLabel);
    ricercaLayout->addWidget(cercaLineEdit);
    ricercaLayout->addWidget(perLabel);
    ricercaLayout->addWidget(colonnaRicercaComboBox);
    mainLayout->addLayout(ricercaLayout);
    
    //Ricerca per parola nella colonna selezionata
    connect(cercaLineEdit, SIGNAL(textChanged(QString)), this, SLOT(aggiornaFiltro()));
    //Aggiorna colonna selezionata per ricerca di parola
    connect(colonnaRicercaComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(aggiornaColonnaRicerca(QString)));

    //Lista Utenti

    modelloProxy = new proxymodel(this);
    modelloProxy->setSourceModel(_model);
    modelloProxy->setFiltroColonne(Utente);
    utentiTableView = new QTableView();
    utentiTableView->setModel(modelloProxy);
    utentiTableView->setSortingEnabled(true);
    utentiTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    utentiTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    mainLayout->addWidget(utentiTableView);

    //Quando vengono aggiunte/rimosse colonne aggiusta la loro dimensione per riempire tutto lo spazio a loro disposizione
    connect(modelloProxy, SIGNAL(colonneModificate()), utentiTableView->horizontalHeader(), SLOT(resizeSections()));
    //Quando viene selezionata una riga viene sbloccato il pulsante di rimozione, altrimenti viene bloccato
    connect(utentiTableView->selectionModel(),SIGNAL(selectionChanged(QItemSelection,QItemSelection)) ,this, SLOT(aggiornaAzioni(QItemSelection,QItemSelection)));

    //Modalità Visualizzazione
    visualizzazioneLayout = new QHBoxLayout();
    visualizzaLabel = new QLabel("Visualizza");
    tipoUtenteComboBox = new QComboBox();
    tipoUtenteComboBox->addItem("Utenti");
    tipoUtenteComboBox->addItem("Studenti");
    tipoUtenteComboBox->addItem("Professori");
    tipoUtenteComboBox->addItem("Insegnanti");
    tipoUtenteComboBox->addItem("Tutor");

    //Quando cambia il tipo utente selezionato aggiorna le colonne visibili
    connect(tipoUtenteComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(tipoUtenteComboBoxChanged(QString)));

    tipoUtenteComboBoxChanged("Utente");

    visualizzaLabel->setAlignment(Qt::AlignCenter);
    visualizzazioneLayout->addWidget(visualizzaLabel);
    visualizzazioneLayout->addWidget(tipoUtenteComboBox);
    mainLayout->addLayout(visualizzazioneLayout);

    setLayout(mainLayout);

}

//Aggiorna la combobox che filtra per colonne con i nuovi valori delle colonne
void menu::tipoUtenteComboBoxChanged(const QString &_string){
    modelloProxy->setFiltroColonne(utente::toTipoUtente(_string.toStdString()));
    colonnaRicercaComboBox->clear();
    QStringList headers;
    for(int i = 0; i < modelloProxy->columnCount(); i++){
      headers.append(modelloProxy->headerData(i, Qt::Horizontal).toString());
    }
    colonnaRicercaComboBox->addItems(headers);
}

//Nuova finestra aggiunta cliente
void menu::aggiungiExec(){
    menudatiutente aggiungi;
    if (aggiungi.exec()) {


        QString codiceFiscale = aggiungi.codiceFiscaleLineEdit->text();
        QString nome = aggiungi.nomeLineEdit->text();
        QString cognome = aggiungi.cognomeLineEdit->text();
        QString dataNascita = aggiungi.dataNascitaLineEdit->text();
        //QString cognome = aggiungi.cognomeText->text();
       // emit sendDetails(codiceFiscale, nome, cognome, dataNascita, tipoUtente);
    }
}

//Rimuove l'utente selezionato quando viene premuto il bottone
void menu::rimuoviUtente(){
    QItemSelectionModel *selectionModel = utentiTableView->selectionModel();
    QModelIndexList indexes = selectionModel->selectedRows();
    foreach (QModelIndex index, indexes) {
        int row = modelloProxy->mapToSource(index).row();
        modelloProxy->removeRows(row, 1, QModelIndex());
    }
}

//Disabilita il pulsante di rimozione utente se nessuna riga è selezionata
void menu::aggiornaAzioni(const QItemSelection &selected , const QItemSelection &deselected){
    Q_UNUSED(deselected);
    QModelIndexList indexes = selected.indexes();
    if (!indexes.isEmpty()) {
        rimuoviButton->setEnabled(true);
    } else {
        rimuoviButton->setEnabled(false);
    }
}

//Aggiorna il filtro per cercare nella colonna selezionata i valori nel QLineEdit di ricerca
void menu::aggiornaFiltro(){
    QRegExp regExp(cercaLineEdit->text(),
                   Qt::CaseInsensitive,
                   QRegExp::FixedString);
    modelloProxy->setFilterRegExp(regExp);
}

//Aggiorna la colonna di ricerca in base all'elemento selezionato nella ComboBox delle colonne
void menu::aggiornaColonnaRicerca(const QString& _colonna){
    for(int i = 0; i < modelloProxy->sourceModel()->columnCount(); i++){
        QString t = modelloProxy->sourceModel()->headerData(i, Qt::Horizontal).toString();
        if(!t.compare(_colonna, Qt::CaseSensitive)){
            modelloProxy->setColonnaRicerca(i);
            return;
        }
    }
}

menu::~menu(){
}

void menu::addCLose(){
    QMenuBar* menubar=new QMenuBar(this);
    QMenu* close=new QMenu("File", menubar);
    QAction* esci=new QAction("Esci", close);

    connect(esci,SIGNAL(triggered()),this,SLOT(close()));
    close->addAction(esci);
    menubar->addMenu(close);
    mainLayout->addWidget(menubar);
}



