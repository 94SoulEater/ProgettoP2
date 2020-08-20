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


class menudatiutente : public QDialog{
    Q_OBJECT
public:
    menudatiutente(QWidget *parent = nullptr);

    QFormLayout *formLayout;
    QVBoxLayout *maindatiLayout;
    QHBoxLayout *bottoniLayout, *labelLayout, *aggiungiAnnullaMenuButtonLayout;
    QPushButton *aggiungiMenuButton, *annullaMenuButton, *cancellaMenuButton;
    QComboBox *tipoUtenteMenuComboBox;
    QLabel *codiceFiscaleLabel, *nomeLabel, *cognomeLabel, *dataNascitaLabel, *tipoUtenteLabel;
    QLineEdit *codiceFiscaleLineEdit, *nomeLineEdit, *cognomeLineEdit, *dataNascitaLineEdit;

private slots:
    void clear();
};

#endif // MENUDATIUTENTE_H
