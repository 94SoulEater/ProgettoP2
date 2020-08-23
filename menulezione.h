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

class menulezione: public QDialog
{
    Q_OBJECT
public:
    menulezione(QWidget *parent = nullptr);

    QFormLayout *formLayout;
    QVBoxLayout *maindatiLayout;
    QHBoxLayout *bottoniLezioneLayout;
    QLabel *materiaLabel, *corsoLabel, *creditiLabel, *stanzaLabel, *orarioLabel;
    QLineEdit *materiaLineEdit, *corsoLineEdit, *creditiLineEdit, *stanzaLineEdit, *orarioLineEdit;
     QPushButton *aggiungiLezioneButton, *annullaLezioneButton;
};

#endif // MENULEZIONE_H
