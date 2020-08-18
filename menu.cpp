#include "menu.h"

menu::menu(QWidget *parent)
    : QWidget(parent){
    mainLayout = new QVBoxLayout(this);

    //Chiusura
    addCLose();

    //Bottoni di aggiunta / rimozione utenti
    aggiungiRimuoviButtonsLayout = new QHBoxLayout();
    aggiungiButton = new QPushButton("Aggiungi Utente");
    rimuoviButton = new QPushButton("Rimuovi Utente");

    aggiungiRimuoviButtonsLayout->addWidget(aggiungiButton);
    aggiungiRimuoviButtonsLayout->addWidget(rimuoviButton);
    mainLayout->addLayout(aggiungiRimuoviButtonsLayout);

    //Ricerca per campi
    ricercaLayout = new QHBoxLayout();
    cercaLabel = new QLabel("Cerca");
    perLabel = new QLabel("Per");
    cercaLineEdit = new QLineEdit();
    colonnaRicercaComboBox = new QComboBox();
    colonnaRicercaComboBox->addItem("Test123");
    colonnaRicercaComboBox->addItem("Test456");

    ricercaLayout->addWidget(cercaLabel);
    ricercaLayout->addWidget(cercaLineEdit);
    ricercaLayout->addWidget(perLabel);
    ricercaLayout->addWidget(colonnaRicercaComboBox);
     mainLayout->addLayout(ricercaLayout);


    //Lista Utenti

    modelloProxy = new proxymodel(this);
    modelloProxy->setFiltroColonne(Utente);
    utentiTableView = new QTableView();
    utentiTableView->setModel(modelloProxy);
    utentiTableView->setSortingEnabled(true);
    utentiTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    mainLayout->addWidget(utentiTableView);
    connect(modelloProxy, SIGNAL(colonneModificate()), utentiTableView->horizontalHeader(), SLOT(resizeSections()));


    //Modalità Visualizzazione
    visualizzazioneLayout = new QHBoxLayout();
    visualizzaButton = new QPushButton("Visualizza");
    tipoUtenteComboBox = new QComboBox();
    tipoUtenteComboBox->addItem("Utenti");
    tipoUtenteComboBox->addItem("Studenti");
    tipoUtenteComboBox->addItem("Professori");
    tipoUtenteComboBox->addItem("Insegnanti");
    tipoUtenteComboBox->addItem("Tutor");
    connect(tipoUtenteComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(tipoUtenteComboBoxChanged(QString)));

    visualizzazioneLayout->addWidget(visualizzaButton);
    visualizzazioneLayout->addWidget(tipoUtenteComboBox);
    mainLayout->addLayout(visualizzazioneLayout);

    setLayout(mainLayout);

}

void menu::setModel(tablemodel *_model){
    modelloProxy->setSourceModel(_model);
}

void menu::tipoUtenteComboBoxChanged(const QString &_string){
    modelloProxy->setFiltroColonne(utente::toTipoUtente(_string.toStdString()));
}

//Nuova finestra aggiunta cliente
void menu::aggiungiClicked()
{
    connect(aggiungiButton, SIGNAL(clicked()), this, SLOT(aggiungiExec()) );
}

void menu::aggiungiExec()
{
    QDialog aggiungi;
        aggiungi.setWindowTitle("Aggiungi utente");
       aggiungi.setMinimumSize(QSize(300, 150));
        aggiungi.setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
   aggiungi.exec();
}

menu::~menu(){
}

void menu::addCLose()
{

    QMenuBar* menubar=new QMenuBar(this);
    QMenu* close=new QMenu("File", menubar);
    QAction* esci=new QAction("Esci", close);

     connect(esci,SIGNAL(triggered()),this,SLOT(close()));
    close->addAction(esci);
    menubar->addMenu(close);
    mainLayout->addWidget(menubar);

}

