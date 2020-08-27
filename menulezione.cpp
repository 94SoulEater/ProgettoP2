#include "menulezione.h"


menulezione::menulezione(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Aggiungi lezione");
    //setMinimumSize(QSize(400, 250));
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    maindatiLayout = new QVBoxLayout();
    formLayout = new QFormLayout();

    //materia
    materiaLabel=new QLabel("Materia:");
    materiaLineEdit = new QLineEdit();
    formLayout->addRow(materiaLabel, materiaLineEdit);

    //corso laurea
    corsoLabel=new QLabel("Corso Laurea:");
    corsoLineEdit = new QLineEdit();
    formLayout->addRow(corsoLabel, corsoLineEdit);

    //crediti
    creditiLabel=new QLabel("Crediti:");
    creditiLineEdit = new QLineEdit();
    creditiLineEdit->setValidator(new QIntValidator(this));
    formLayout->addRow(creditiLabel, creditiLineEdit);

    //stanza
    stanzaLabel=new QLabel("Stanza:");
    stanzaLineEdit = new QLineEdit();
    formLayout->addRow(stanzaLabel, stanzaLineEdit);

    //combo
    comboLayout = new QHBoxLayout();
    combo=new QComboBox();
    eliminaOrarioButton=new QPushButton("Elimina Orario");
    comboLayout->addWidget(combo);
    comboLayout ->addWidget(eliminaOrarioButton);
    combo->setVisible(false);
    eliminaOrarioButton->setVisible(false);

    connect(eliminaOrarioButton,SIGNAL(clicked()),this,SLOT(rimuoviDaCombo()));

    //orario
    orarioLayout = new QHBoxLayout();
    orarioInizioLabel=new QLabel("Orario inizio:");
    orarioInizioLineEdit = new QLineEdit();
    orarioInizioLineEdit->setInputMask("99:99;");
    orarioFineLabel=new QLabel("Orario fine:");
    orarioFineLineEdit = new QLineEdit();
    orarioFineLineEdit->setInputMask("99:99;");
    orarioGiornoLabel=new QLabel("Giorno:");
    orarioGiornoLineEdit = new QLineEdit();
    aggiungiOrarioButton=new QPushButton("Aggiungi Orario");

    orarioLayout ->addWidget(orarioInizioLabel);
    orarioLayout ->addWidget(orarioInizioLineEdit);
    orarioLayout ->addWidget(orarioFineLabel);
    orarioLayout ->addWidget(orarioFineLineEdit);
    orarioLayout ->addWidget(orarioGiornoLabel);
    orarioLayout ->addWidget(orarioGiornoLineEdit);
    orarioLayout ->addWidget(aggiungiOrarioButton);

    connect(aggiungiOrarioButton,SIGNAL(clicked()),this,SLOT(aggiungiCombo()));

    maindatiLayout->addLayout(formLayout);
    maindatiLayout->addLayout(comboLayout);
    maindatiLayout->addLayout(orarioLayout);

    //bottoni
    aggiungiLezioneButton= new QPushButton("Aggiungi Lezione");
    annullaLezioneButton= new QPushButton("Annulla inserimento");

    bottoniLezioneLayout = new QHBoxLayout();
    bottoniLezioneLayout->addWidget(aggiungiLezioneButton);
    bottoniLezioneLayout->addWidget(annullaLezioneButton);

    maindatiLayout->addLayout(bottoniLezioneLayout);

    connect(annullaLezioneButton,SIGNAL(clicked()),this,SLOT(reject()));
    connect(aggiungiLezioneButton, SIGNAL(clicked()), this, SLOT(accept()));

    setLayout(maindatiLayout);
}

void menulezione::aggiungiCombo()
{
    combo->setVisible(true);
    eliminaOrarioButton->setVisible(true);
    QString orario=orarioInizioLineEdit->text()+" - "+orarioFineLineEdit->text()+"  "+orarioGiornoLineEdit->text();
    combo->addItem(orario);
    orarioInizioLineEdit->clear();
    orarioFineLineEdit->clear();
    orarioGiornoLineEdit->clear();
}

void menulezione::rimuoviDaCombo()
{
    combo->removeItem(combo->currentIndex());
}
