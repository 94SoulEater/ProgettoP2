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


class menudatiutente : public QDialog{
    Q_OBJECT
public:
    menudatiutente(QWidget *parent = nullptr);

    QVBoxLayout *maindatiLayout;
    QHBoxLayout *labelLayout, *aggiungiAnnullaMenuButtonLayout;
    QPushButton *aggiungiMenuButton, *annullaMenuButton;
    QComboBox *tipoUtenteMenuComboBox;
    QLabel *codiceFiscaleLabel, *nomeLabel, *cognomeLabel, *dataNascitaLabel, *tipoUtenteLabel;
    QLineEdit *codiceFiscaleLineEdit, *nomeLineEdit, *cognomeLineEdit, *dataNascitaLineEdit;
};

#endif // MENUDATIUTENTE_H
