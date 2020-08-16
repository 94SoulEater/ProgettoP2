#include "menu.h"

menu::menu(QWidget *parent)
    : QWidget(parent){
    mainLayout = new QVBoxLayout(this);

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
    modello = new tablemodel();
    modelloProxy = new proxymodel();
    modelloProxy->setSourceModel(modello);
    modelloProxy->setFiltroColonne(Utente);
    utentiTableView = new QTableView();
    utentiTableView->setModel(modelloProxy);
    utentiTableView->setSortingEnabled(true);
    utentiTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    mainLayout->addWidget(utentiTableView);

    //Modalità Visualizzazione
    visualizzazioneLayout = new QHBoxLayout();
    visualizzaLabel = new QLabel("Visualizza");
    tipoUtenteComboBox = new QComboBox();
    tipoUtenteComboBox->addItem("Utenti");
    tipoUtenteComboBox->addItem("Studenti");
    tipoUtenteComboBox->addItem("Insegnanti");
    tipoUtenteComboBox->addItem("Professori");
    tipoUtenteComboBox->addItem("Tutor");

    visualizzazioneLayout->addWidget(visualizzaLabel);
    visualizzazioneLayout->addWidget(tipoUtenteComboBox);
    mainLayout->addLayout(visualizzazioneLayout);

    setLayout(mainLayout);
}

menu::~menu(){
}

