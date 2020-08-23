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


     maindatiLayout->addLayout(formLayout);

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
