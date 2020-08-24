#ifndef MENURICERCA_H
#define MENURICERCA_H

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDateEdit>
#include <QFormLayout>
#include <QPushButton>


class menuricerca: public QDialog
{
    Q_OBJECT
public:
    menuricerca(QWidget *parent = nullptr);

    QFormLayout *formLayout;
    QVBoxLayout *maindatiLayout;
    QHBoxLayout *bottoniRicercaLayout;
    QLabel *titoloLabel, *autoriLabel, *linkLabel, *rivistaLabel, *dataPubblicazioneLabel;
    QLineEdit *dataPubblicazioneLineEdit, *titoloLineEdit, *autoriLineEdit, *rivistaLineEdit, *linkLineEdit;
     QPushButton *aggiungiRicercaButton, *annullaRicercaButton;
};

#endif // MENURICERCA_H
