#ifndef LEZIONITABLEMODEL_H
#define LEZIONITABLEMODEL_H

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
#include <iostream>


class lezionitablemodel : public QAbstractTableModel{
    Q_OBJECT
public:
    lezionitablemodel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    bool insertRows(int position, int rows, const QModelIndex &parent);
    bool removeRows(int row, int count, const QModelIndex &parent);
    void setListaLezioni(contenitore<lezione> _listaLezioni);
    lezionitablemodel(contenitore<lezione> _listaLezioni, QObject *parent = nullptr);
    bool contains(const lezione& _lez);
    contenitore<giornoLezione> getListaGiornoLezione(int row);
private:
    contenitore<lezione> listaLezioni;
};

#endif // LEZIONITABLEMODEL_H
