#include "lezionitablemodel.h"

lezionitablemodel::lezionitablemodel(QObject *parent)
    : QAbstractTableModel(parent), listaLezioni(){
}

lezionitablemodel::lezionitablemodel(contenitore<lezione> _listaLezioni, QObject *parent)
    : QAbstractTableModel(parent){

   setListaLezioni(_listaLezioni);
}

void lezionitablemodel::setListaLezioni(contenitore<lezione> _listaLezioni){
    beginInsertRows(QModelIndex(), 0, _listaLezioni.size()-1);
    listaLezioni = _listaLezioni;
    endInsertRows();
}

int lezionitablemodel::rowCount(const QModelIndex&) const{
    return listaLezioni.size();
}

int lezionitablemodel::columnCount(const QModelIndex&) const{
    return 5;
}

QVariant lezionitablemodel::data(const QModelIndex &index, int role) const{
    if (!index.isValid()) return QVariant();
    if (role == Qt::DisplayRole) {
        const lezione lezioneTemp = listaLezioni.value(index.row());
        switch(index.column()){
        case 0: //Materia
            return QString::fromStdString(lezioneTemp.getMateria());
        case 1: //Corsolaurea
            return QString::fromStdString(lezioneTemp.getCorsoLaurea());
        case 2: //Stanza
            return QString::fromStdString(lezioneTemp.getStanza());
        case 3: //Crediti
            return QString::number(lezioneTemp.getCrediti());
        case 4: {//Orario
            return lezioneTemp.getGiorniLezioneStringList();
        }
        default:
            return QVariant();
        }
    }
    return QVariant();
}

bool lezionitablemodel::setData(const QModelIndex &index, const QVariant &value, int role){
    if (index.isValid() && role == Qt::EditRole) {
        int row = index.row();
        lezione tmp = listaLezioni.value(row);

        switch(index.column()){
        case 0: //Materia
            tmp.setMateria(value.toString().toStdString());
            break;
        case 1: //Corsolaurea
            tmp.setCorsoLaurea(value.toString().toStdString());
            break;
        case 2: //Stanza
            tmp.setStanza(value.toString().toStdString());
            break;
        case 3: //Crediti
            tmp.setCrediti(value.toInt());
            break;
       case 4: //Orario
            tmp.setGiorniLezione(value.toStringList());
            break;
        }
        listaLezioni.replace(row, tmp);
        emit(dataChanged(index, index));
        return true;
    }
    return false;
}

QVariant lezionitablemodel::headerData(int section, Qt::Orientation orientation, int role) const{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return QString("Materia");
        case 1:
            return QString("Corso laurea");
        case 2:
            return QString("Stanza");
        case 3:
            return QString("Crediti");
        case 4:
           return QString("Orario");
        }
    }
    return QVariant();
}
Qt::ItemFlags lezionitablemodel::flags(const QModelIndex &index) const{
    if (!index.isValid())return Qt::ItemIsEnabled;
    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}
bool lezionitablemodel::insertRows(int position, int rows, const QModelIndex &index){
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position + rows - 1);
    for (int row = 0; row < rows; ++row) {
        listaLezioni.push(lezione());
    }
    endInsertRows();
    return true;
}

bool lezionitablemodel::removeRows(int position, int rows, const QModelIndex &index){
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), position, position + rows - 1);
    for (int row = 0; row < rows; ++row) {
        listaLezioni.remove(position);
    }
    endRemoveRows();
    return true;
}

bool lezionitablemodel::contains(const lezione& _lez){
    return listaLezioni.contains(_lez);
}

contenitore<giornoLezione> lezionitablemodel::getListaGiornoLezione(int row)
{
/*
   puntatoresmart<lezione> tmp= listaLezioni.value(row);
    if(dynamic_cast<lezione*>(tmp.operator->())){
       return dynamic_cast<lezione*>(tmp.operator->())->getGiorniLezione();
    }
    return contenitore<giornoLezione>();
*/
}
