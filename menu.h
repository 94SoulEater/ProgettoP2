#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMenuBar>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>

class menu : public QWidget
{
    Q_OBJECT
public:
    menu(QWidget *parent = nullptr);
    ~menu();

private:
    QVBoxLayout *mainLayout;
    QHBoxLayout *aggiungiRimuoviButtonsLayout, *ricercaLayout, *visualizzazioneLayout;
    QPushButton *aggiungiButton, *rimuoviButton;
    QLabel *cercaLabel, *perLabel, *visualizzaLabel;
    QLineEdit *cercaLineEdit;
    QComboBox *colonnaRicercaComboBox, *tipoUtenteComboBox;
};

#endif // MENU_H
