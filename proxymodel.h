#ifndef PROXYMODEL_H
#define PROXYMODEL_H

#include "Model/contenitore.h"
#include "Model/utente.h"
#include "Model/puntatoresmart.h"
#include <QSortFilterProxyModel>

class proxymodel : public QSortFilterProxyModel{
    Q_OBJECT
private:
    contenitore<int> colonneNascoste;
    tipoutente filtroTipoUtente;
    int colonnaRicerca;
public:
    proxymodel(QObject *parent = nullptr);
    bool filterAcceptsColumn(int source_column, const QModelIndex&) const override;
    bool filterAcceptsRow(int source_row, const QModelIndex&) const override;
    void setFiltroColonne(tipoutente _tipoUtente);
    void setColonnaRicerca(int _colonnaRicerca);
    bool isColonnaNascosta(int _col);
signals:
    void colonneModificate();
};

#endif // PROXYMODEL_H
