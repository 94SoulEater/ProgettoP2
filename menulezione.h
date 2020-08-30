#ifndef MENULEZIONE_H
#define MENULEZIONE_H

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QtWidgets>
#include <QComboBox>
#include <QMessageBox>


class menulezione: public QDialog
{
    Q_OBJECT
public:
    menulezione(QWidget *parent = nullptr);

    QFormLayout *formLayout;
    QVBoxLayout *maindatiLayout;
    QHBoxLayout *bottoniLezioneLayout, *orarioLayout, *comboLayout;
    QLabel *materiaLabel, *corsoLabel, *creditiLabel, *stanzaLabel, *orarioInizioLabel, *orarioFineLabel, *orarioGiornoLabel;
    QLineEdit *materiaLineEdit, *corsoLineEdit, *creditiLineEdit, *stanzaLineEdit, *orarioInizioLineEdit,  *orarioFineLineEdit;
    QPushButton *aggiungiLezioneButton, *annullaLezioneButton, *aggiungiOrarioButton, *eliminaOrarioButton;
    QComboBox *combo, *orarioGiornoCombo;


public slots:
    void aggiungiCombo();
    void rimuoviDaCombo();


private slots:
    void accept() override;
};

#endif // MENULEZIONE_H
