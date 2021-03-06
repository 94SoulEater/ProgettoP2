#ifndef UTENTITABLEMODEL_H
#define UTENTITABLEMODEL_H

#include "Model/contenitore.h"
#include "Model/puntatoresmart.h"
#include "Model/utente.h"
#include "Model/professore.h"
#include "Model/tutor.h"
#include "Model/lezione.h"
#include "Model/ricerca.h"
#include "Model/insegnante.h"
#include "QAbstractTableModel"
#include <QTime>
#include <QModelIndex>

class utentitablemodel : public QAbstractTableModel{
    Q_OBJECT
public:
    utentitablemodel(QObject *parent = nullptr);
    utentitablemodel(contenitore<puntatoresmart<utente>> _listaUtenti, QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    bool insertRows(int position, int rows, const QModelIndex &parent) override;
    bool removeRows(int row, int count, const QModelIndex &parent) override;
    bool contains(const puntatoresmart<utente>& _utente);
    void aggiungiUtente(const puntatoresmart<utente> &_utente);
    contenitore<ricerca> getListaRicerche(int row);
    contenitore<lezione> getListaLezione(int row);
    void modificaUtente(int _row,const puntatoresmart<utente> &_utente);
private:
    contenitore<puntatoresmart<utente>> listaUtenti;
    void aggiungiUtenti();
};

#endif // UTENTITABLEMODEL_H
