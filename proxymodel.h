#ifndef PROXYMODEL_H
#define PROXYMODEL_H

#include "Model/contenitore.h"
#include "Model/utente.h"
#include <QSortFilterProxyModel>

class proxymodel : public QSortFilterProxyModel{
    Q_OBJECT
private:
    contenitore<int> colonneNascoste;
public:
    proxymodel(QObject *parent = nullptr);
    bool filterAcceptsColumn(int source_column, const QModelIndex&) const;
    void setFiltroColonne(tipoutente _tipoUtente);
};

#endif // PROXYMODEL_H
