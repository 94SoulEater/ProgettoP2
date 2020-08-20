#ifndef MENUDATIUTENTE_H
#define MENUDATIUTENTE_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QWidget>


class menudatiutente : public QDialog{
    Q_OBJECT
public:
    menudatiutente(QWidget *parent = nullptr);

    QVBoxLayout *maindatiLayout;
    QHBoxLayout *labelLayout, *aggiungiMenuButtonLayout;
    QPushButton *aggiungiMenuButton;
    QLabel *codiceFiscaleLabel, *nomeLabel, *cognomeLabel, *dataNascitaLabel, *tipoUtenteLabel;
    QLineEdit *codiceFiscaleLineEdit, *nomeLineEdit, *cognomeLineEdit, *dataNascitaLineEdit, *tipoUtenteLineEdit;
};

#endif // MENUDATIUTENTE_H
