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





class menudatiutente : public QDialog{
    Q_OBJECT
public:
    menudatiutente(QWidget *parent = nullptr);

    QFormLayout *formLayout;
    QVBoxLayout *maindatiLayout;
    QHBoxLayout *bottoniLayout, *labelLayout, *aggiungiAnnullaMenuButtonLayout, *fuoriLayout;
    QPushButton *aggiungiMenuButton, *annullaMenuButton, *cancellaMenuButton;
    QComboBox *tipoUtenteMenuComboBox, *laureaMenuComboBox;
    QLabel *codiceFiscaleLabel, *nomeLabel, *cognomeLabel, *dataNascitaLabel, *tipoUtenteLabel, *annifuoricorsoLabel, *fuoricorsoLabel;
    QLineEdit *codiceFiscaleLineEdit, *nomeLineEdit, *cognomeLineEdit, *dataNascitaLineEdit, *emailLineEdit, *telefonoLineEdit, *capLineEdit, *regioneLineEdit, *comuneLineEdit, *viaLineEdit, *numeroCivicoLineEdit, *annocorsoLineEdit, *corsoLineEdit, *anniServizioLineEdit, *tipoLineEdit;
    QDateEdit * dataNascitaEdit, *dataIscrizioneEdit;
    QCheckBox *checkBox;
    QSpinBox *spinBox;

private slots:
    void clear();
};

#endif // MENUDATIUTENTE_H
