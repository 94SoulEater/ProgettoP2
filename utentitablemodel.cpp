#include "utentitablemodel.h"

using std::cout; using std::endl;

void utentitablemodel::aggiungiUtente(puntatoresmart<utente> _utente){
    beginInsertRows(QModelIndex(), 0, 0);
    listaUtenti.push(_utente);
    endInsertRows();
}

void utentitablemodel::aggiungiUtenti(){
    professore* provaIns1 = new professore("Francesco", "Ranzato", "FRTCSL03L49F205V", "+393190231829", "ranzato@gmail.com", 31, 1, 1976, "Veneto", "Padova", "San Giacomo", "31000",  "91", "Ordinario", 21);
    tutor* provaIns2 = new tutor("Luca", "Gualtieri","LRCCRC05T15C351I", "+393202222686", "gualtieri.l@gmail.com", 10, 2, 1999, "Veneto", "Caselle d'altivole", "San Francesco", "31044", "21", 1193422, triennale, "Informatica", 2, false, 0, 10, 11, 2018);
    studente* provaIns3 = new studente("Andrea", "Trentini", "LFNSLV07L17D612W", "+393492947120", "a.trentini@hotmail.it", 21, 12, 1998, "Toscana", "Firenze", "San Torriceno", "30200", "9", 1183920, magistrale, "Psicologia", 3, false, 0, 20, 8, 2017);
    studente* provaIns4 = new studente("Isidoro", "Baresi", "NBLTCL06B60C351K", "+393294019283", "isibar97@protonmail.com", 9, 4, 1997, "Veneto", "Padova", "Sant Andrea", "31000", "21H", 1172121, triennale, "Informatica", 3, true, 1, 16, 7, 2016);
    professore* provaIns5 = new professore("Claudio", "Palazzi","CPPFBA03C27H501Y", "+393201521939", "cpalazzi@gmail.com", 18, 10, 1980, "Veneto", "Caerano di san marco", "San Marco", "31031", "xx-Bis", "Ordinario", 10);
    lezione provaLez1("Programmazione ad oggetti", "SC1167 - Informatica", "Lum250", 12);
    lezione provaLez2("Verifica del software", "SC1176 - LM Informatica", "P200", 12);
    lezione provaLez3("Sistemi Operativi", "SC1167 - Informatica", "P200", 10);
    provaLez1.addGiornoLezione("12,30", "14,30", Qt::Monday);
    provaLez2.addGiornoLezione("12,30", "14,30", Qt::Tuesday);
    provaLez3.addGiornoLezione("12,30", "14,30", Qt::Wednesday);
    provaLez1.addGiornoLezione("14,30", "16,30", Qt::Thursday);
    provaLez2.addGiornoLezione("14,30", "16,30", Qt::Wednesday);
    provaLez3.addGiornoLezione("14,30", "16,30", Qt::Monday);
    provaIns1->addLezione(provaLez1);
    provaIns1->addLezione(provaLez2);
    provaIns5->addLezione(provaLez3);
    ricerca provaRic1("G. Filè and F. Ranzato", "Improving abstract interpretations by systematic lifting to the powerset", "https://www.math.unipd.it/~ranzato/papers/ilps94.pdf", "The MIT Press", 1994);
    provaIns1->addRicerca(provaRic1);
    ricerca provaRic2("A. Cortesi, R. Giacobazzi, G. Filé, C. Palamidessi, and F. Ranzato", "Complementation in abstract interpretation", "https://www.math.unipd.it/~ranzato/papers/sas95.pdf", "Springer-Verlag", 1995);
    provaIns1->addRicerca(provaRic2);
    ricerca provaRic3("C. De Francesco, C. E. Palazzi, D. Ronzani","Fast Message Broadcasting in Vehicular Networks: Model Analysis and Performance Evaluation", "https://ieeexplore.ieee.org/document/9088960", "IEEE Communications Letters", 2020);
    provaIns5->addRicerca(provaRic3);
    listaUtenti.push(puntatoresmart<utente>(provaIns1)); //Ranzato
    listaUtenti.push(puntatoresmart<utente>(provaIns2)); //Gualtieri
    listaUtenti.push(puntatoresmart<utente>(provaIns3)); //Trentini
    listaUtenti.push(puntatoresmart<utente>(provaIns4)); //Baresi
    listaUtenti.push(puntatoresmart<utente>(provaIns5)); //Palazzi
}

utentitablemodel::utentitablemodel(QObject *parent)
    : QAbstractTableModel(parent), listaUtenti(){
    aggiungiUtenti();
}

bool utentitablemodel::contains(const puntatoresmart<utente>& _utente){
    return listaUtenti.contains(_utente);
}

int utentitablemodel::rowCount(const QModelIndex&) const{
    return listaUtenti.size();
}

int utentitablemodel::columnCount(const QModelIndex&) const{
    return 19;
}

QVariant utentitablemodel::data(const QModelIndex &index, int role) const{
    if (!index.isValid()) return QVariant();
    if (role == Qt::DisplayRole) {
        utente* utenteTemp = listaUtenti.value(index.row()).operator->();
        switch(index.column()){
        case 0: //Codice fiscale
            return QString::fromStdString(utenteTemp->getCodiceFiscale());
        case 1:{ //Matricola
            studente* tmp = dynamic_cast<studente*>(utenteTemp);
            if(tmp){
                return QString::number(tmp->getMatricola());
            }
            return QVariant();
        }
        case 2: //Nome
            return QString::fromStdString(utenteTemp->getNome());
        case 3: //Cognome
            return QString::fromStdString(utenteTemp->getCognome());
        case 4: //Data di nascita
            return QString(utenteTemp->getDataNascita().toString(Qt::RFC2822Date));
        case 5: //Numero di telefono
            return QString::fromStdString(utenteTemp->getTelefono());
        case 6: //Email
            return QString::fromStdString(utenteTemp->getEmail());
        case 7:{ //Corso di studi
            studente* tmp = dynamic_cast<studente*>(utenteTemp);
            if(tmp){
                return QString::fromStdString(tmp->getCorso());
            }
            return QVariant();
        }
        case 8:{ //Tipo di laurea
            studente* tmp = dynamic_cast<studente*>(utenteTemp);
            if(tmp){
                return QString::fromStdString(tmp->getLaurea());
            }
            return QVariant();
        }
        case 9:{ //Anno corso
            studente* tmp = dynamic_cast<studente*>(utenteTemp);
            if(tmp){
                return QString::number(tmp->getAnnoCorso());
            }
            return QVariant();
        }
        case 10:{ //Anni fuori corso
            studente* tmp = dynamic_cast<studente*>(utenteTemp);
            if(tmp){
                if(tmp->getFuoricorso()) return QString::number(tmp->getAnniFuoriCorso());
                else return QString::fromStdString("Regolare");
            }
            return QVariant();
        }
        case 11: //Tipo utente
            return QString::fromStdString(utente::fromTipoUtente(utenteTemp->getTipoUtente()));
        case 12:{ //Tipo professore
            professore* tmp = dynamic_cast<professore*>(utenteTemp);
            if(tmp){
                return QString::fromStdString(tmp->getTipo());
            }
            return QVariant();
        }
        case 13:{ //Anni di servizio
            professore* tmp = dynamic_cast<professore*>(utenteTemp);
            if(tmp){
                return QString::number(tmp->getAnniServizio());
            }
            return QVariant();
        }
        case 14: //Regione
            return QString::fromStdString(utenteTemp->getRegione());
        case 15: //Cap
            return QString::fromStdString(utenteTemp->getCap());
        case 16: //Comune
            return QString::fromStdString(utenteTemp->getComune());
        case 17: //Via
            return QString::fromStdString(utenteTemp->getVia());
        case 18: //Numerocivico
            return QString::fromStdString(utenteTemp->getNumeroCivico());
        case 19:{ //Data Iscrizione
            studente* tmp = dynamic_cast<studente*>(utenteTemp);
            if(tmp){
                return QString(tmp->getDataIscrizione().toString(Qt::RFC2822Date));
            }
            return QVariant();
        }
        default:
            return QVariant();
        }
    }
    return QVariant();
}

QVariant utentitablemodel::headerData(int section, Qt::Orientation orientation, int role) const{
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
        case 14:
            return QString("Regione");
        case 15:
            return QString("Cap");
        case 16:
            return QString("Comune");
        case 17:
            return QString("Via");
        case 18:
            return QString("Numero Civico");
        case 19:
            return QString("Data Iscrizione");
        }
    }
    return QVariant();
}

Qt::ItemFlags utentitablemodel::flags(const QModelIndex &index) const{
    if (!index.isValid())return Qt::ItemIsEnabled;
    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

bool utentitablemodel::setData(const QModelIndex &index, const QVariant &value, int role){
    if (index.isValid() && role == Qt::EditRole) {
        int row = index.row();
        puntatoresmart<utente> tmp = listaUtenti.value(row);

        switch(index.column()){
        case 0: //CodiceFiscale
            tmp->setCodiceFiscale(value.toString().toStdString());
            break;
        case 1: //Matricola
            if(dynamic_cast<studente*>(tmp.operator->())){
                dynamic_cast<studente*>(tmp.operator->())->setMatricola(value.toString().toInt());
            }
            break;
        case 2: //Nome
            tmp->setNome(value.toString().toStdString());
            break;
        case 3: //Cognome
            tmp->setCognome(value.toString().toStdString());
            break;
        case 4: //Data di nascita
            tmp->setDataNascita(QDate::fromString(value.toString(),  Qt::RFC2822Date));
            break;
        case 5: //Numero di telefono
            tmp->setTelefono(value.toString().toStdString());
            break;
        case 6: //Email
            tmp->setEmail(value.toString().toStdString());
            break;
        case 7: //Corso di studi
            if(dynamic_cast<studente*>(tmp.operator->())){
                dynamic_cast<studente*>(tmp.operator->())->setCorso(value.toString().toStdString());
            }
            break;
        case 8: //Tipo laurea
            if(dynamic_cast<studente*>(tmp.operator->())){
                dynamic_cast<studente*>(tmp.operator->())->setLaurea(value.toString().toStdString());
            }
            break;
        case 9: //Anno corso
            if(dynamic_cast<studente*>(tmp.operator->())){
                dynamic_cast<studente*>(tmp.operator->())->setAnnoCorso(value.toInt());
            }
            break;
        case 10: //Anni fuori corso
            if(dynamic_cast<studente*>(tmp.operator->())){
                if(value.toInt()){
                    dynamic_cast<studente*>(tmp.operator->())->setFuoricorso(true);
                    dynamic_cast<studente*>(tmp.operator->())->setAnniFuoriCorso(value.toInt());
                }else{
                    dynamic_cast<studente*>(tmp.operator->())->setFuoricorso(false);
                    dynamic_cast<studente*>(tmp.operator->())->setAnniFuoriCorso(0);
                }
            }
            break;
        case 11: //Tipo utente
            break;
        case 12: //Tipo professore
            if(dynamic_cast<professore*>(tmp.operator->())){
                dynamic_cast<professore*>(tmp.operator->())->setTipo(value.toString().toStdString());
            }
            break;
        case 13: //Anni di servizio
            if(dynamic_cast<professore*>(tmp.operator->())){
                dynamic_cast<professore*>(tmp.operator->())->setAnniServizio(value.toInt());
            }
            break;
        case 14: //Regione
            tmp->setRegione(value.toString().toStdString());
            break;
        case 15: //Cap
            tmp->setCap(value.toString().toStdString());
            break;
        case 16: //Comune
            tmp->setComune(value.toString().toStdString());
            break;
        case 17: //Via
            tmp->setVia(value.toString().toStdString());
            break;
        case 18: //Numero civico
            tmp->setNumeroCivico(value.toString().toStdString());
            break;
        case 19: //Data iscrizione
            if(dynamic_cast<studente*>(tmp.operator->())){
                dynamic_cast<studente*>(tmp.operator->())->setDataIscrizione(QDate::fromString(value.toString(),  Qt::RFC2822Date));
            }
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

bool utentitablemodel::insertRows(int position, int rows, const QModelIndex &index){
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position + rows - 1);
    for (int row = 0; row < rows; ++row) {
        listaUtenti.push(puntatoresmart<utente>());
    }
    endInsertRows();
    return true;
}

bool utentitablemodel::removeRows(int position, int rows, const QModelIndex &index){
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), position, position + rows - 1);
    for (int row = 0; row < rows; ++row) {
        listaUtenti.remove(position);
    }
    endRemoveRows();
    return true;
}

contenitore<ricerca> utentitablemodel::getListaRicerche(int row){
    puntatoresmart<utente> tmp = listaUtenti.value(row);
    if(dynamic_cast<professore*>(tmp.operator->())){
        return dynamic_cast<professore*>(tmp.operator->())->getRicerche();
    }
    return contenitore<ricerca>();
}

contenitore<lezione> utentitablemodel::getListaLezione(int row)
{
    puntatoresmart<utente> tmp = listaUtenti.value(row);
    if(dynamic_cast<insegnante*>(tmp.operator->())){
        return dynamic_cast<insegnante*>(tmp.operator->())->getLezioni();
    }
    return contenitore<lezione>();
}
