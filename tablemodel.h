#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include "Model/contenitore.h"
#include "Model/puntatoresmart.h"
#include "Model/utente.h"
#include "Model/professore.h" //
#include "Model/tutor.h" //
#include "Model/lezione.h" //
#include "Model/ricerca.h" //
#include "QAbstractTableModel"
#include <QTime> //
#include <QModelIndex>
#include <iostream>

class tablemodel : public QAbstractTableModel{
    Q_OBJECT
public:
    tablemodel(QObject *parent = nullptr);
    tablemodel(contenitore<puntatoresmart<utente>> _listaUtenti, QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    bool insertRow(int row, const QModelIndex &parent);
    bool removeRow(int row, const QModelIndex &parent);
private:
    contenitore<puntatoresmart<utente>> listaUtenti;
};

#endif // TABLEMODEL_H
