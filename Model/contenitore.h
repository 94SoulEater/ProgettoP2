#ifndef CONTENITORE_H
#define CONTENITORE_H
#include <string>

using std::string;

template <class T>
class contenitore{
    friend class iteratore;
    friend class iteratore_const;
private:
    class nodo{
    public:
        T info;
        nodo* next;
        nodo();
        ~nodo();
        nodo(const nodo&);
        nodo(const T&, nodo*);
    };
    nodo* head;
    static nodo* copia(nodo*);

public:
   class iteratore{
        friend class contenitore<T>;
    private:
        nodo* p;
        nodo* getNodo();
    public:
        iteratore();
        iteratore(nodo*);
        iteratore &operator++();
        iteratore &operator++(int);
        T &operator*();
        T *operator->();
        bool operator ==(const iteratore&)const;
        bool operator !=(const iteratore&)const;
    };
   class iteratore_const{
        friend class contenitore<T>;
    private:
        nodo* p;
        const nodo* getNodo() const;
    public:
        iteratore_const();
        iteratore_const(const iteratore&);
        iteratore_const(nodo*);
        iteratore_const& operator++();
        iteratore_const& operator++(int);
        const T& operator*() const;
        const T* operator->() const;
        bool operator==(const iteratore_const&)const;
        bool operator!=(const iteratore_const&)const;
    };
   contenitore();
   contenitore(const contenitore&);
   ~contenitore();

   void push(const T&);
   int size() const;
   void clear();
   bool contains(const T&) const;
   T& value(int _pos);
   void remove(int _pos);
   void replace(int _pos, const T&);

   iteratore begin();
   iteratore end();
   iteratore_const begin()const;
   iteratore_const end()const;


};

//Nodo---------------------------------------------------------

template<class T>
contenitore<T>::nodo::nodo(const T& _info, nodo* _next): info(_info), next(_next){
}

template<class T>
contenitore<T>::nodo::nodo(): next(0){
}

template<class T>
contenitore<T>::nodo::nodo(const nodo & _nodo): info(_nodo.info), next(_nodo.next){
}

template<class T>
contenitore<T>::nodo::~nodo(){
    if(next) delete next;
}

//Contenitore--------------------------------------------------

template<class T>
contenitore<T>::contenitore(): head(0){
}

template<class T>
contenitore<T>::contenitore(const contenitore& c): head(copia(c.head)){
}

template<class T>
contenitore<T>::~contenitore(){
    if(head) delete head;
}

template<class T>
typename contenitore<T>::nodo* contenitore<T>::copia(contenitore<T>::nodo *_head){
    if(_head==0)return 0;
    nodo* p=new nodo(_head->info,copia(_head->next));
    return p;
}

//Funzioni-Contenitore-----------------------------

template<class T>
void contenitore<T>::push(const T& t){
    head=new nodo(t, head);
}

template<class T>
int contenitore<T>::size() const{
    int count = 0;
    nodo* p = head;
    while(p){
        count++;
        p = p->next;
    }
    return count;
}

template<class T>
void contenitore<T>::clear(){
    if(head){
        delete head;
        head = 0;
    }
}

template<class T>
bool contenitore<T>::contains(const T& t) const{
    nodo* p = head;
    while(p){
        if(p->info == t) return true;
        p = p->next;
    }
    return false;
}

template<class T>
T& contenitore<T>::value(int _pos){
    iteratore it = begin();
    for(int i=0; i<_pos; i++) ++it;
    return *it;
}

template<class T>
void contenitore<T>::remove(int _pos){
    if (!head) return;
    nodo* p = head;
    if (_pos == 0){
        head = p->next;
        p->next = 0;
        delete p;
        return;
    }
    for (int i=0; p && i<_pos-1; i++) p = p->next;
    if (!p || !p->next) return;

    nodo *next = p->next->next;
    p->next->next = 0;
    delete p->next;
    p->next = next;
}

template<class T>
void contenitore<T>::replace(int _pos,const T& t){
    if (!head) return;
    nodo* p = head;
    if (_pos == 0){
        head = new nodo(t, p->next);
        p->next = 0;
        delete p;
        return;
    }
    for (int i=0; p && i<_pos-1; i++) p = p->next;
    if (!p || !p->next) return;

    nodo *next = p->next->next;
    p->next->next = 0;
    delete p->next;
    p->next = new nodo(t, next);
}

//Iteratore----------------------------------------

template<class T>
contenitore<T>::iteratore::iteratore(): p(0){
}

template<class T>
contenitore<T>::iteratore::iteratore(nodo* n): p(n){
}

template<class T>
typename contenitore<T>::iteratore &contenitore<T>::iteratore::operator++(){
    if(p) p=p->next;
    return *this;
}

template<class T>
typename contenitore<T>::iteratore &contenitore<T>::iteratore::operator++(int){
    iteratore aux= *this;
    if(p) p=p->next;
    return aux;
}

template<class T>
T& contenitore<T>::iteratore::operator*(){
    return p->info;
}

template<class T>
T* contenitore<T>::iteratore::operator->(){
    return &(p->info);
}

template<class T>
typename contenitore<T>::nodo* contenitore<T>::iteratore::getNodo(){
    return p;
}

template<class T>
bool contenitore<T>::iteratore::operator==(const contenitore<T>::iteratore& it)const{
    return p==it.p;
}

template<class T>
bool contenitore<T>::iteratore::operator !=(const contenitore<T>::iteratore& it)const{
    return p!=it.p;
}

template<class T>
typename contenitore<T>::iteratore contenitore<T>::begin(){
    return iteratore(head);
}

template<class T>
typename contenitore<T>::iteratore contenitore<T>::end(){
    return iteratore(0);
}

//Iteratore_const------------------------------------

template<class T>
contenitore<T>::iteratore_const::iteratore_const(): p(0){
}

template<class T>
contenitore<T>::iteratore_const::iteratore_const(const iteratore& i){
    p = i.p;
}

template<class T>
contenitore<T>::iteratore_const::iteratore_const(nodo* n): p(n){
}

template<class T>
typename contenitore<T>::iteratore_const &contenitore<T>::iteratore_const::operator++(){
    if(p) p=p->next;
    return *this;
}

template<class T>
typename contenitore<T>::iteratore_const &contenitore<T>::iteratore_const::operator++(int){
    iteratore aux= *this;
    if(p) p=p->next;
    return aux;
}

template<class T>
const T& contenitore<T>::iteratore_const::operator*() const{
    return p->info;
}

template<class T>
const T* contenitore<T>::iteratore_const::operator->() const{
    return &(p->info);
}

template<class T>
const typename contenitore<T>::nodo* contenitore<T>::iteratore_const::getNodo() const{
    return p;
}

template<class T>
bool contenitore<T>::iteratore_const::operator==(const contenitore<T>::iteratore_const& it)const{
    return p==it.p;
}

template<class T>
bool contenitore<T>::iteratore_const::operator !=(const contenitore<T>::iteratore_const& it)const{
    return p!=it.p;
}

template<class T>
typename contenitore<T>::iteratore_const contenitore<T>::begin()const{
    return iteratore_const(head);
}

template<class T>
typename contenitore<T>::iteratore_const contenitore<T>::end()const{
    return iteratore_const(0);
}

#endif // CONTENITORE_H
