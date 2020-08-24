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
#include <QTableView>
#include "menuricerca.h"
#include "menulezione.h"
#include "lezionitablemodel.h"
#include "ricerchetablemodel.h"


class menudatiutente : public QDialog{
    Q_OBJECT
public:
    menudatiutente(QWidget *parent = nullptr);

    QFormLayout *formLayoutUtente, *formLayoutProf, *formLayoutStudente;
    QVBoxLayout *maindatiLayout;
    QHBoxLayout *aggRimuoviLezioneLayout, *aggRimuoviRicercaLayout, *lezTableLayout, *ricTableLayout, *bottoniLayout, *labelLayout, *aggiungiAnnullaMenuButtonLayout, *fuoriLayout, *vnLayout;
    QPushButton *ricercaModificaButton, *lezioneModificaButton, *aggiungiMenuButton, *annullaMenuButton, *cancellaMenuButton, *ricercaAggiungiButton, *lezioneAggiungiButton, *lezioneEliminaButton, *ricercaEliminaButton;
    QComboBox *tipoUtenteMenuComboBox, *laureaMenuComboBox;
    QLabel *codiceFiscaleLabel, *nomeLabel, *cognomeLabel, *dataNascitaLabel, *tipoUtenteLabel, *annifuoricorsoLabel, *fuoricorsoLabel, *viaLabel, *numeroCivicoLabel, *emailLabel,*telefonoLabel, *capLabel, *regioneLabel, *comuneLabel, *tipoLabel, *anniServizioLabel, *laureaLabel,*corsoLabel,*matricolaLabel,*annocorsoLabel, *dataIscrizioneLabel, *ricercaLabel, *lezioneLabel;
    QLineEdit *codiceFiscaleLineEdit, *nomeLineEdit, *cognomeLineEdit, *dataNascitaLineEdit, *emailLineEdit, *telefonoLineEdit, *capLineEdit, *regioneLineEdit, *comuneLineEdit, *viaLineEdit, *numeroCivicoLineEdit, *annocorsoLineEdit, *corsoLineEdit, *anniServizioLineEdit, *tipoLineEdit, *matricolaLineEdit;
    QDateEdit * dataNascitaEdit, *dataIscrizioneEdit, * dataPubblicazioneEdit;
    QCheckBox *checkBox;
    QSpinBox *spinBox;
    QLabel  *lezioneEliminaLabel, *ricercaEliminaLabel;
    lezionitablemodel *modelloLezioni;
    ricerchetablemodel *modelloRicerche;
    QTableView *lezioniTableView, *ricercheTableView;

private slots:
    void clear();
    void showRow(QString);
    void aggiungiLezione();
    void aggiungiRicerca();
    void modificaLezione(const QModelIndex &index = QModelIndex());
    void modificaRicerca(const QModelIndex &index = QModelIndex());
    void eliminaLezione();
    void eliminaRicerca();
};

#endif // MENUDATIUTENTE_H
