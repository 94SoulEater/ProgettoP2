#ifndef MENU_H
#define MENU_H

#include "tablemodel.h"
#include "proxymodel.h"
#include "menudatiutente.h"
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
#include <QFormLayout>
#include <QtWidgets>
#include <QLineEdit>

class menu : public QWidget
{
    Q_OBJECT
public:
    menu(tablemodel *_model, QWidget *parent = nullptr);
    ~menu();

private slots:
    void tipoUtenteComboBoxChanged(const QString&);
    void rimuoviUtente();
    void aggiornaAzioni(const QItemSelection &selected , const QItemSelection &deselected);
    void aggiungiExec();
    void aggiornaFiltro();
    void aggiornaColonnaRicerca(const QString&);

private:
    QVBoxLayout *mainLayout;
    QHBoxLayout *aggiungiRimuoviButtonsLayout, *ricercaLayout, *visualizzazioneLayout;
    QPushButton *aggiungiButton, *rimuoviButton;
    QLabel *cercaLabel, *perLabel, *visualizzaLabel;
    QLineEdit *cercaLineEdit;
    QComboBox *colonnaRicercaComboBox, *tipoUtenteComboBox;
    QTableView *utentiTableView;
    proxymodel *modelloProxy;

    void addCLose();
    void setupColonneTableView(tipoutente _tipoutente);
};

#endif // MENU_H
