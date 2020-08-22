#include "tablemodel.h"

using std::cout; using std::endl;

void tablemodel::aggiungiUtenti(){
    professore* provaIns1 = new professore("Francesco", "Ranzato", "FRTCSL03L49F205V", "3190231829", "ranzato@gmail.com", 31, 1, 1976, "Veneto", "Padova", "San Giacomo", "31000",  "91", "Ordinario", 21);
    tutor* provaIns2 = new tutor("Luca", "Gualtieri","LRCCRC05T15C351I", "3202222686", "gualtieri.l@gmail.com", 10, 2, 1999, "Veneto", "Caselle d'altivole", "San Francesco", "31044", "21", 1193422, triennale, "Informatica", 2, false, 0, 10, 11, 2018);
    studente* provaIns3 = new studente("Andrea", "Trentini", "LFNSLV07L17D612W", "3492947120", "a.trentini@hotmail.it", 21, 12, 1998, "Toscana", "Firenze", "San Torriceno", "30200", "9", 1183920, magistrale, "Psicologia", 3, false, 0, 20, 8, 2017);
    studente* provaIns4 = new studente("Isidoro", "Baresi", "NBLTCL06B60C351K", "3294019283", "isibar97@protonmail.com", 9, 4, 1997, "Veneto", "Padova", "Sant Andrea", "31000", "21H", 1172121, triennale, "Informatica", 3, true, 1, 16, 7, 2016);
    professore* provaIns5 = new professore("Claudio", "Palazzi","CPPFBA03C27H501Y", "3201521939", "cpalazzi@gmail.com", 18, 10, 1980, "Veneto", "Caerano di san marco", "San Marco", "31031", "xx-Bis", "Ordinario", 10);
    lezione provaLez1("Programmazione ad oggetti", "SC1167 - Informatica", "Lum250", 12);
    lezione provaLez2("Verifica del software", "SC1176 - LM Informatica", "P200", 12);
    lezione provaLez3("Sistemi Operativi", "SC1167 - Informatica", "P200", 10);
    QTime oraInizio(12, 30), oraFine(14, 30);
    provaLez1.addGiornoLezione(oraInizio, oraFine, Qt::Monday);
    provaLez2.addGiornoLezione(oraInizio, oraFine, Qt::Tuesday);
    provaLez3.addGiornoLezione(oraInizio, oraFine, Qt::Wednesday);
    oraInizio = QTime(14, 30), oraFine = QTime(16, 30);
    provaLez1.addGiornoLezione(oraInizio, oraFine, Qt::Thursday);
    provaLez2.addGiornoLezione(oraInizio, oraFine, Qt::Wednesday);
    provaLez3.addGiornoLezione(oraInizio, oraFine, Qt::Monday);
    provaIns1->addLezione(provaLez1);
    provaIns1->addLezione(provaLez2);
    provaIns5->addLezione(provaLez3);
    ricerca provaRic1("G. Filè and F. Ranzato", "Improving abstract interpretations by systematic lifting to the powerset", "https://www.math.unipd.it/~ranzato/papers/ilps94.pdf", "The MIT Press", 1, 1, 1994);
    provaIns1->addRicerca(provaRic1);
    ricerca provaRic2("A. Cortesi, R. Giacobazzi, G. Filé, C. Palamidessi, and F. Ranzato", "Complementation in abstract interpretation", "https://www.math.unipd.it/~ranzato/papers/sas95.pdf", "Springer-Verlag", 1, 1, 1995);
    provaIns1->addRicerca(provaRic2);
    ricerca provaRic3("C. De Francesco, C. E. Palazzi, D. Ronzani","Fast Message Broadcasting in Vehicular Networks: Model Analysis and Performance Evaluation", "https://ieeexplore.ieee.org/document/9088960", "IEEE Communications Letters", 1, 4, 2020);
    provaIns5->addRicerca(provaRic3);
    listaUtenti.push(puntatoresmart<utente>(provaIns1));
    listaUtenti.push(puntatoresmart<utente>(provaIns2));
    listaUtenti.push(puntatoresmart<utente>(provaIns3));
    listaUtenti.push(puntatoresmart<utente>(provaIns4));
    listaUtenti.push(puntatoresmart<utente>(provaIns5));
}

tablemodel::tablemodel(QObject *parent)
    : QAbstractTableModel(parent), listaUtenti(){
    aggiungiUtenti();
}

int tablemodel::rowCount(const QModelIndex&) const{
    return listaUtenti.size();
}

int tablemodel::columnCount(const QModelIndex&) const{
    return 14;
}

QVariant tablemodel::data(const QModelIndex &index, int role) const{
    if (!index.isValid()) return QVariant();
    if (role == Qt::DisplayRole) {
        contenitore<puntatoresmart<utente>>::iteratore_const it = listaUtenti.begin();
        switch(index.column()){
        case 0:
            for(int i=0; i<index.row(); i++) ++it;
            return QString::fromStdString((*(*it)).getCodiceFiscale());
        case 1:{
            for(int i=0; i<index.row(); i++) ++it;
            studente* tmp = dynamic_cast<studente*>((*it).operator ->());
            if(tmp){
                return QString::number(tmp->getMatricola());
            }
            return QVariant();
        }
        case 2:
            for(int i=0; i<index.row(); i++) ++it;
            return QString::fromStdString((*(*it)).getNome());
        case 3:
            for(int i=0; i<index.row(); i++) ++it;
            return QString::fromStdString((*(*it)).getCognome());
        case 4:
            for(int i=0; i<index.row(); i++) ++it;
            return QString((*(*it)).getDataNascita().toString());
        case 5:
            for(int i=0; i<index.row(); i++) ++it;
            return QString::fromStdString((*(*it)).getTelefono());
        case 6:
            for(int i=0; i<index.row(); i++) ++it;
            return QString::fromStdString((*(*it)).getEmail());
        case 7:{
            for(int i=0; i<index.row(); i++) ++it;
            studente* tmp = dynamic_cast<studente*>((*it).operator ->());
            if(tmp){
                return QString::fromStdString(tmp->getCorso());
            }
            return QVariant();
        }
        case 8:{
            for(int i=0; i<index.row(); i++) ++it;
            studente* tmp = dynamic_cast<studente*>((*it).operator ->());
            if(tmp){
                return QString::fromStdString(tmp->getLaurea());
            }
            return QVariant();
        }
        case 9:{
            for(int i=0; i<index.row(); i++) ++it;
            studente* tmp = dynamic_cast<studente*>((*it).operator ->());
            if(tmp){
                return QString::number(tmp->getAnnoCorso());
            }
            return QVariant();
        }
        case 10:{
            for(int i=0; i<index.row(); i++) ++it;
            studente* tmp = dynamic_cast<studente*>((*it).operator ->());
            if(tmp){
                if(tmp->getFuoricorso()) return QString::number(tmp->getAnniFuoriCorso());
                else return QString::fromStdString("Regolare");
            }
            return QVariant();
        }
        case 11:
            for(int i=0; i<index.row(); i++) ++it;
            return QString::fromStdString(utente::fromTipoUtente((*(*it)).getTipoUtente()));
        case 12:{
            for(int i=0; i<index.row(); i++) ++it;
            professore* tmp = dynamic_cast<professore*>((*it).operator ->());
            if(tmp){
                return QString::fromStdString(tmp->getTipo());
            }
            return QVariant();
        }
        case 13:{
            for(int i=0; i<index.row(); i++) ++it;
            professore* tmp = dynamic_cast<professore*>((*it).operator ->());
            if(tmp){
                return QString::number(tmp->getAnniServizio());
            }
            return QVariant();
        }
        default:
            return QVariant();
        }
    }
    return QVariant();
}

QVariant tablemodel::headerData(int section, Qt::Orientation orientation, int role) const{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return QString("Codice Fiscale");
        case 1:
            return QString("Matricola");
        case 2:
            return QString("Nome");
        case 3:
            return QString("Cognome");
        case 4:
            return QString("Data di Nascita");
        case 5:
            return QString("Telefono");
        case 6:
            return QString("Email");
        case 7:
            return QString("Corso");
        case 8:
            return QString("Tipo corso");
        case 9:
            return QString("Anno");
        case 10:
            return QString("Fuori corso");
        case 11:
            return QString("Tipo Utente");
        case 12:
            return QString("Tipo Professore");
        case 13:
            return QString("Anni di servizio");
        }
    }
    return QVariant();
}

Qt::ItemFlags tablemodel::flags(const QModelIndex &index) const{
    if (!index.isValid())return Qt::ItemIsEnabled;
    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

bool tablemodel::setData(const QModelIndex &index, const QVariant &value, int role){
    if (index.isValid() && role == Qt::EditRole) {
        int row = index.row();
        puntatoresmart<utente> tmp = listaUtenti.value(row);

        switch(index.column()){
        case 0:
            tmp->setCodiceFiscale(value.toString().toStdString());
            break;
        case 1:
            if(dynamic_cast<studente*>(tmp.operator->())){
                dynamic_cast<studente*>(tmp.operator->())->setMatricola(value.toString().toInt());
            }
            break;
        case 2:
            tmp->setNome(value.toString().toStdString());
            break;
        case 3:
            tmp->setCognome(value.toString().toStdString());
            break;
        case 4:
            tmp->setDataNascita(QDate::fromString(value.toString()));
            break;
        case 5:
            tmp->setTelefono(value.toString().toStdString());
            break;
        case 6:
            tmp->setEmail(value.toString().toStdString());
            break;
        default:
            return false;
        }
        listaUtenti.replace(row, tmp);
        emit(dataChanged(index, index));
        return true;
    }

    return false;
}

bool tablemodel::insertRows(int position, int rows, const QModelIndex &index){
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; ++row) {
        listaUtenti.push(puntatoresmart<utente>());
    }

    endInsertRows();
    return true;
}

bool tablemodel::removeRows(int position, int rows, const QModelIndex &index){
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; ++row) {
        listaUtenti.remove(position);
    }
    endRemoveRows();
    return true;
}

