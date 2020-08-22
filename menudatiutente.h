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
    QHBoxLayout *bottoniLayout, *labelLayout, *aggiungiAnnullaMenuButtonLayout, *fuoriLayout, *vnLayout;
    QPushButton *aggiungiMenuButton, *annullaMenuButton, *cancellaMenuButton, *hideButton;
    QComboBox *tipoUtenteMenuComboBox, *laureaMenuComboBox;
    QLabel *codiceFiscaleLabel, *nomeLabel, *cognomeLabel, *dataNascitaLabel, *tipoUtenteLabel, *annifuoricorsoLabel, *fuoricorsoLabel, *viaLabel, *numeroCivicoLabel, *emailLabel,*telefonoLabel, *capLabel, *regioneLabel, *comuneLabel, *tipoLabel, *anniServizioLabel, *laureaLabel,*corsoLabel,*matricolaLabel,*annocorsoLabel, *dataIscrizioneLabel;
    QLineEdit *codiceFiscaleLineEdit, *nomeLineEdit, *cognomeLineEdit, *dataNascitaLineEdit, *emailLineEdit, *telefonoLineEdit, *capLineEdit, *regioneLineEdit, *comuneLineEdit, *viaLineEdit, *numeroCivicoLineEdit, *annocorsoLineEdit, *corsoLineEdit, *anniServizioLineEdit, *tipoLineEdit, *matricolaLineEdit;
    QDateEdit * dataNascitaEdit, *dataIscrizioneEdit;
    QCheckBox *checkBox;
    QSpinBox *spinBox;

private slots:
    void clear();
    void showRow(QString);
};

#endif // MENUDATIUTENTE_H
