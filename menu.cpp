#include "menu.h"

menu::menu(tablemodel *_model, QWidget *parent)
    : QWidget(parent){
    mainLayout = new QVBoxLayout(this);

    //Chiusura
    //addCLose();

    //Bottoni di aggiunta / rimozione utenti
    aggiungiRimuoviButtonsLayout = new QHBoxLayout();
    aggiungiButton= new QPushButton("Aggiungi utente");
    rimuoviButton= new QPushButton("Rimuovi utente");
    modificaButton= new QPushButton("Visualizza utente");
    rimuoviButton->setEnabled(false);
    modificaButton->setEnabled(false);
    aggiungiRimuoviButtonsLayout->addWidget(aggiungiButton);
    aggiungiRimuoviButtonsLayout->addWidget(modificaButton);
    aggiungiRimuoviButtonsLayout->addWidget(rimuoviButton);
    mainLayout->addLayout(aggiungiRimuoviButtonsLayout);

    //Apre nuova finestra per inserimento dati utente
    connect(aggiungiButton, SIGNAL(clicked()), this, SLOT(aggiungiUtente()));
    //Rimuove l'utente selezionato
    connect(rimuoviButton, SIGNAL(clicked()), this, SLOT(rimuoviUtente()));
    //Visualizza l'utente selezionato
    connect(modificaButton, SIGNAL(clicked()), this, SLOT(modificaUtente()));

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
    utentiTableView = new QTableView();
    utentiTableView->setModel(modelloProxy);
    utentiTableView->setSortingEnabled(true);
    utentiTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //Fa in modo che sizeHint() mostra tutte le colonne della tabella senza scrolling
    utentiTableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    //Seleziona una riga al posto di una singola cella
    utentiTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    mainLayout->addWidget(utentiTableView);

    //Quando vengono aggiunte/rimosse colonne aggiusta la loro dimensione per riempire tutto lo spazio a loro disposizione
    connect(modelloProxy, SIGNAL(colonneModificate()), utentiTableView->horizontalHeader(), SLOT(resizeSections()));

    //Quando viene selezionata una riga viene sbloccato il pulsante di rimozione, altrimenti viene bloccato
    connect(utentiTableView->selectionModel(),SIGNAL(selectionChanged(QItemSelection,QItemSelection)) ,this, SLOT(aggiornaAzioni(QItemSelection,QItemSelection)));

    //TEST
    connect(utentiTableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(modificaUtente(QModelIndex)));

    //Modalità Visualizzazione
    visualizzazioneLayout = new QHBoxLayout();
    visualizzaLabel = new QLabel("Visualizza");
    tipoUtenteComboBox = new QComboBox();
    tipoUtenteComboBox->addItem("Utenti");
    tipoUtenteComboBox->addItem("Studenti");
    tipoUtenteComboBox->addItem("Professori");
    tipoUtenteComboBox->addItem("Insegnanti");
    tipoUtenteComboBox->addItem("Tutor");

    visualizzaLabel->setAlignment(Qt::AlignCenter);
    visualizzazioneLayout->addWidget(visualizzaLabel);
    visualizzazioneLayout->addWidget(tipoUtenteComboBox);

    mainLayout->addLayout(visualizzazioneLayout);

    //Quando cambia il tipo utente selezionato aggiorna le colonne visibili
    connect(tipoUtenteComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(tipoUtenteComboBoxChanged(QString)));

    //Setup iniziale
    tipoUtenteComboBoxChanged("Utente");

    setLayout(mainLayout);


    //Imposta la dimensione della finestra in modo che tutte le colonne siano ben visibili in qualsiasi caso
    modelloProxy->setFiltroColonne(Tutor);
    setMinimumSize(sizeHint());
    modelloProxy->setFiltroColonne(Utente);

    //Allinea la finestra al centro dello schermo
    setGeometry(
            QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            size(),
            qApp->desktop()->availableGeometry()
        )
    );
}

//Imposta la dimensione delle colonne adatta al contenuto della tabella
void menu::setupColonneTableView(tipoutente _tipoutente){
    utentiTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    if(_tipoutente != Studente) utentiTableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    utentiTableView->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);
    utentiTableView->horizontalHeader()->setSectionResizeMode(5, QHeaderView::ResizeToContents);
    if(_tipoutente != Tutor){
        utentiTableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    }else{
        utentiTableView->horizontalHeader()->setSectionResizeMode(6, QHeaderView::ResizeToContents);
    }
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
    setupColonneTableView(utente::toTipoUtente(_string.toStdString()));
}

//Nuova finestra aggiunta cliente
void menu::aggiungiUtente(){
    menudatiutente aggiungi;
    if (aggiungi.exec()) {
        /*
        QString codiceFiscale = aggiungi.codiceFiscaleLineEdit->text();
        QString nome = aggiungi.nomeLineEdit->text();
        QString cognome = aggiungi.cognomeLineEdit->text();
        QString dataNascita = aggiungi.dataNascitaLineEdit->text();
        std::cout<<codiceFiscale.toStdString()<<" "<<nome.toStdString()<<" "<<cognome.toStdString()<<" "<<dataNascita.toStdString()<<std::endl;
        */
        // emit sendDetails(codiceFiscale, nome, cognome, dataNascita, tipoUtente);
    }
}

void menu::modificaUtente(const QModelIndex &index){
    QString nome;
    QString cognome;
    QString codiceFiscale;
    QString telefono;
    QString email;
    QDate dataNascita;
    QString regione;
    QString comune;
    QString via;
    QString cap;
    QString numeroCivico;
    int row;

    if(!index.isValid()){
        //Se sono selezionate più righe modifica la prima
        QModelIndexList indexes = utentiTableView->selectionModel()->selectedRows();
        row = modelloProxy->mapToSource(indexes.at(0)).row();
    }else{
        row = modelloProxy->mapToSource(index).row();
    }
    QModelIndex codiceFiscaleIndex = modelloProxy->sourceModel()->index(row, 0, QModelIndex());
    codiceFiscale = modelloProxy->sourceModel()->data(codiceFiscaleIndex, Qt::DisplayRole).toString();

    QModelIndex nomeIndex = modelloProxy->sourceModel()->index(row, 2, QModelIndex());
    nome = modelloProxy->sourceModel()->data(nomeIndex, Qt::DisplayRole).toString();

    QModelIndex cognomeIndex = modelloProxy->sourceModel()->index(row, 3, QModelIndex());
    cognome = modelloProxy->sourceModel()->data(cognomeIndex, Qt::DisplayRole).toString();

    QModelIndex dataNascitaIndex = modelloProxy->sourceModel()->index(row, 4, QModelIndex());
    dataNascita = QDate::fromString(modelloProxy->sourceModel()->data(dataNascitaIndex, Qt::DisplayRole).toString());

    QModelIndex telefonoIndex = modelloProxy->sourceModel()->index(row, 5, QModelIndex());
    telefono = modelloProxy->sourceModel()->data(telefonoIndex, Qt::DisplayRole).toString();

    QModelIndex emailIndex = modelloProxy->sourceModel()->index(row, 6, QModelIndex());
    email = modelloProxy->sourceModel()->data(emailIndex, Qt::DisplayRole).toString();

    menudatiutente modifica;
    modifica.setWindowTitle(tr("Modifica utente"));
    modifica.nomeLineEdit->setText(nome);
    modifica.cognomeLineEdit->setText(cognome);
    modifica.codiceFiscaleLineEdit->setText(codiceFiscale);
    modifica.dataNascitaEdit->setDate(dataNascita);
    modifica.telefonoLineEdit->setText(telefono);
    modifica.emailLineEdit->setText(email);

    if (modifica.exec()) {
        //...
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
        modificaButton->setEnabled(true);
    } else {
        rimuoviButton->setEnabled(false);
        modificaButton->setEnabled(false);
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
/*Aggiunge barra menu
void menu::addCLose(){
    QMenuBar* menubar=new QMenuBar(this);
    QMenu* close=new QMenu("File", menubar);
    QAction* esci=new QAction("Esci", close);

    connect(esci,SIGNAL(triggered()),this,SLOT(close()));
    close->addAction(esci);
    menubar->addMenu(close);
    mainLayout->addWidget(menubar);
}
*/



