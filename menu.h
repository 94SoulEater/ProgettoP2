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
#include <QFormLayout>
#include <QDialog>
#include <QWizard>
#include <QtWidgets>
#include <QLineEdit>
#include <set>

class menu : public QWidget
{
    Q_OBJECT
public:
    menu(QWidget *parent = nullptr);
    ~menu();
    void setModel(tablemodel *_model);

private slots:
    void tipoUtenteComboBoxChanged(const QString&);
    void aggiungiExec();

private:
    QVBoxLayout *mainLayout;
    QHBoxLayout *aggiungiRimuoviButtonsLayout, *ricercaLayout, *visualizzazioneLayout;
    QPushButton *aggiungiButton, *rimuoviButton, *visualizzaButton;
    QLabel *cercaLabel, *perLabel;
    QLineEdit *cercaLineEdit;
    QComboBox *colonnaRicercaComboBox, *tipoUtenteComboBox;
    QTableView *utentiTableView;
    proxymodel *modelloProxy;


    void addCLose();
 };

#endif // MENU_H
