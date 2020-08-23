#ifndef MENUDATIUTENTE_H
#define MENUDATIUTENTE_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QComboBox>
#include <QFormLayout>
#include <QDateEdit>
#include <QCheckBox>
#include <QSpinBox>
#include "menuricerca.h"
#include "menulezione.h"



class menudatiutente : public QDialog{
    Q_OBJECT
public:
    menudatiutente(QWidget *parent = nullptr);

    QFormLayout *formLayout;
    QVBoxLayout *maindatiLayout;
    QHBoxLayout *bottoniLayout, *labelLayout, *aggiungiAnnullaMenuButtonLayout, *fuoriLayout, *vnLayout;
    QPushButton * aggiungiMenuButton, *annullaMenuButton, *cancellaMenuButton, *ricercaButton, *lezioneButton, *lezioneEliminaButton, *ricercaEliminaButton;
    QComboBox *tipoUtenteMenuComboBox, *laureaMenuComboBox;
    QLabel *codiceFiscaleLabel, *nomeLabel, *cognomeLabel, *dataNascitaLabel, *tipoUtenteLabel, *annifuoricorsoLabel, *fuoricorsoLabel, *viaLabel, *numeroCivicoLabel, *emailLabel,*telefonoLabel, *capLabel, *regioneLabel, *comuneLabel, *tipoLabel, *anniServizioLabel, *laureaLabel,*corsoLabel,*matricolaLabel,*annocorsoLabel, *dataIscrizioneLabel, *ricercaLabel, *lezioneLabel;
    QLineEdit *codiceFiscaleLineEdit, *nomeLineEdit, *cognomeLineEdit, *dataNascitaLineEdit, *emailLineEdit, *telefonoLineEdit, *capLineEdit, *regioneLineEdit, *comuneLineEdit, *viaLineEdit, *numeroCivicoLineEdit, *annocorsoLineEdit, *corsoLineEdit, *anniServizioLineEdit, *tipoLineEdit, *matricolaLineEdit;
    QDateEdit * dataNascitaEdit, *dataIscrizioneEdit, * dataPubblicazioneEdit;
    QCheckBox *checkBox;
    QSpinBox *spinBox;
    QLabel *titoloLabel, *autoriLabel, *linkLabel, *rivistaLabel, *dataPubblicazioneLabel, *materiaLabel, *corsoLezLabel, *creditiLabel, *stanzaLabel, *orarioLabel, *lezioneEliminaLabel, *ricercaEliminaLabel;
    QLineEdit *titoloLineEdit, *autoriLineEdit, *rivistaLineEdit, *linkLineEdit, *materiaLineEdit, *corsoLezLineEdit, *creditiLineEdit, *stanzaLineEdit, *orarioLineEdit;

private slots:
    void clear();
    void showRow(QString);
    void aggiungiLezione();
    void aggiungiRicerca();
    void eliminaLezione();
    void eliminaRicerca();
};

#endif // MENUDATIUTENTE_H
