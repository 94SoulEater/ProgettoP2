#ifndef PROXYMODEL_H
#define PROXYMODEL_H

#include "Model/contenitore.h"
#include "Model/utente.h"
#include <QSortFilterProxyModel>

class proxymodel : public QSortFilterProxyModel{
    Q_OBJECT
private:
    contenitore<int> colonneNascoste;
    tipoutente filtroTipoUtente;
    int colonnaRicerca;
public:
    proxymodel(QObject *parent = nullptr);
    bool filterAcceptsColumn(int source_column, const QModelIndex&) const;
    bool filterAcceptsRow(int source_row, const QModelIndex&) const;
    void setFiltroColonne(tipoutente _tipoUtente);
    void setColonnaRicerca(int _colonnaRicerca);
signals:
    void colonneModificate();
};

#endif // PROXYMODEL_H
