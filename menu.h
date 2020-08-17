#ifndef MENU_H
#define MENU_H

#include "tablemodel.h"
#include "proxymodel.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMenuBar>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QTableView>
#include <QHeaderView>
#include <QSortFilterProxyModel>

class menu : public QWidget
{
    Q_OBJECT
public:
    menu(QWidget *parent = nullptr);
    ~menu();

private:
    QVBoxLayout *mainLayout;
    QHBoxLayout *aggiungiRimuoviButtonsLayout, *ricercaLayout, *visualizzazioneLayout;
    QPushButton *aggiungiButton, *rimuoviButton, *visualizzaButton;
    QLabel *cercaLabel, *perLabel;
    QLineEdit *cercaLineEdit;
    QComboBox *colonnaRicercaComboBox, *tipoUtenteComboBox;
    QTableView *utentiTableView;
    tablemodel *modello;
    proxymodel *modelloProxy;
    void addCLose();
};

#endif // MENU_H
