#include "tablemodel.h"

using std::cout; using std::endl;

tablemodel::tablemodel(QObject *parent)
    : QAbstractTableModel(parent), listaUtenti(){
    professore provaIns1("Marco", "Dello Iacovo","ctflelo1239CFCFCF", "3201512686", "marco.delloiacovo99@gmail.com", 18, 10, 1999, "Veneto", "Caerano di san marco", "San marco", "31031", "xx-Bis", "Ordinario", 30);
    tutor provaIns2("Luca", "Gualtieri","ctflelo123qeweFCFCF", "3202222686", "gualtieri.l@gmail.com", 1, 9, 1999, "Veneto", "Caselle d'altivole", "San francesco", "31044", "xx-Bis", 1193422, triennale, "Informatica", 2, false, 0, 10, 11, 2018);
    lezione provaLez1("Programmazione ad oggetti", "SC1167 - Informatica", "Lum250", 12);
    lezione provaLez2("Verifica del software", "SC1176 - LM Informatica", "P200", 12);
    QTime oraInizio(12, 30), oraFine(14, 30);
    provaLez1.addGiornoLezione(oraInizio, oraFine, Qt::Monday);
    provaLez2.addGiornoLezione(oraInizio, oraFine, Qt::Tuesday);
    oraInizio = QTime(14, 30), oraFine = QTime(16, 30);
    provaLez1.addGiornoLezione(oraInizio, oraFine, Qt::Thursday);
    provaLez2.addGiornoLezione(oraInizio, oraFine, Qt::Wednesday);
    provaIns1.addLezione(provaLez1);
    provaIns1.addLezione(provaLez2);
    //provaIns1.removeLezione(provaLez2);
    ricerca provaRic1("G. Filè and F. Ranzato", "Improving abstract interpretations by systematic lifting to the powerset", "https://www.math.unipd.it/~ranzato/papers/ilps94.pdf", "The MIT Press", 1, 1, 1994);
    provaIns1.addRicerca(provaRic1);
    ricerca provaRic2 ("A. Cortesi, R. Giacobazzi, G. Filé, C. Palamidessi, and F. Ranzato", "Complementation in abstract interpretation", "https://www.math.unipd.it/~ranzato/papers/sas95.pdf", "Springer-Verlag", 1, 1, 1995);
    provaIns1.addRicerca(provaRic2);
    //provaIns1.removeRicerca(provaRic2);
    vector<lezione> provaLezVec1 = provaIns1.getLezioni();
    vector<ricerca> provaRicVec1 = provaIns1.getRicerche();
    vector<giornoLezione> provaGiorniLez1;
    //Stampa
    cout<<provaIns1.getNome()<<" "<<provaIns1.getCognome()<<" "<<provaIns1.getDataNascita().toString().toStdString()<<" "<<provaIns1.getAnniServizio()<<endl;
    for(auto it = provaLezVec1.begin(); it != provaLezVec1.end(); ++it){
        provaGiorniLez1 = it->getGiorniLezione();
        cout<<it->getCorsoLaurea()<<" "<<it->getMateria()<<" "<<it->getCrediti()<<" "<<it->getStanza()<<" Orari:"<<endl;
        for(auto it1 = provaGiorniLez1.begin(); it1 != provaGiorniLez1.end(); ++it1){
            cout<<"\t"<<it1->oraInizio.toString().toStdString()<<" - "<<it1->oraFine.toString().toStdString()<<" "<<it1->giornoSettimana<<endl;
        }
    }
    cout<<"Ricerche: "<<endl;
    for(auto it = provaRicVec1.begin(); it!=provaRicVec1.end(); ++it){
        cout<<"\t"<<it->getAutori()<<" "<<it->getTitolo()<<" "<<it->getLink()<<" "<<it->getRivistaPubblicazione()<<" "<<it->getDataPubblicazione().year()<<endl;
    }
    puntatoresmart<utente> punt1 = provaIns1.clone();
    puntatoresmart<utente> punt2 = provaIns2.clone();
    listaUtenti.push(punt1);
    listaUtenti.push(punt2);
}
//-------------------------------------------------------
int tablemodel::rowCount(const QModelIndex & /*parent*/) const{
    return listaUtenti.size();
}
//-------------------------------------------------------
int tablemodel::columnCount(const QModelIndex & /*parent*/) const{
    return 6;
}
//-------------------------------------------------------
QVariant tablemodel::data(const QModelIndex &index, int role) const{
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
            return QString::fromStdString(utente::fromTipoUtente((*(*it)).getTipoUtente()));
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
            return QString("Tipo Utente");
        }
    }
    return QVariant();
}

Qt::ItemFlags tablemodel::flags(const QModelIndex &index) const{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

bool tablemodel::setData(const QModelIndex &index, const QVariant &value, int role){
    if (index.isValid() && role == Qt::EditRole) {
        int row = index.row();
        puntatoresmart<utente> tmp = listaUtenti.value(row);

        switch(index.column()){
        case 0:
            (*tmp).setCodiceFiscale(value.toString().toStdString());
            break;
        case 1:
            break;
        case 2:
            (*tmp).setNome(value.toString().toStdString());
            break;
        case 3:
            (*tmp).setCognome(value.toString().toStdString());
            break;
        case 4:
            (*tmp).setDataNascita(QDate::fromString(value.toString()));
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

