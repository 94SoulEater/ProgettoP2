#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include "Model/contenitore.h"
#include "Model/puntatoresmart.h"
#include "Model/utente.h"
#include "QAbstractTableModel"
#include <QModelIndex>

class tablemodel : public QAbstractTableModel{
    Q_OBJECT
public:
    tablemodel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
private:
    contenitore<puntatoresmart<utente>> listaUtenti;
};

#endif // TABLEMODEL_H
