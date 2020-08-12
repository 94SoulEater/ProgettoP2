#ifndef CONTENITORE_H
#define CONTENITORE_H
#include <string>

using std::string;

template <class T>
class contenitore{
private:
    class punto{
        friend class contenitore<T>;
    private:
        T info;
        punto* next;
        punto(const T&, punto*=0);
        punto(const punto&);
        void distruggi();
    };
    punto *first,*last;
    static punto* copia(punto*, punto*&);

public:
    contenitore();
    contenitore(const T&);
    contenitore(const contenitore&);
    ~contenitore();
    contenitore & operator=(const contenitore&);

    class iteratore{
        friend class contenitore<T>;
    private:
        punto* p;
        iteratore(punto*);
    public:
        iteratore();
        iteratore& operator =(const iteratore&);
        iteratore &operator++();
        iteratore &operator++(int);
        T &operator*() const;
        T *operator->() const;
        bool operator ==(const iteratore&);
        bool operator !=(const iteratore&);
    };
    iteratore start();
    iteratore fine();
};

#endif // CONTENITORE_H

template<class T>
contenitore<T>::punto::punto(const T & pol, nodo* n): info(pol), next(n){
}

template<class T>
contenitore::punto::punto(const contenitore::punto & n): info(n.info), next(n.next){
}

template<class T>
void contenitore::punto::distruggi()
{
    if(next)  next->distruggi();
    delete this;
}


template<class T>
typename contenitore::punto *contenitore::copia(contenitore::punto *f, contenitore::punto *& l)
{
    if(f==0){
        l=0;
        return 0;
    }
    punto* punt=new punto(f->info,copia(f->next,l));
    if(f->next==0)
        l=punt;
    return punt;
}

template<class T>
contenitore::contenitore(): first(0), last(0){
}

template<class T>
contenitore<T>::contenitore(const T & pol): first(new punto(pol))
{
last=first;
}

template<class T>
contenitore::contenitore(const contenitore & c): first(copia(c.first,last)){
}

template<class T>
contenitore::~contenitore()
{
    if(first)
        first->distruggi();
}

template<class T>
contenitore &contenitore::operator=(const contenitore & c){
    if(this!=&c){
        if(first) delete first;
        first=copia(c.first,last);
    }
    return *this;
}

template<class T>
contenitore::iteratore::iteratore(contenitore::punto * punt): p(punt){
}

template<class T>
contenitore::iteratore::iteratore(): p(0){
}

template<class T>
typename contenitore::iteratore &contenitore::iteratore::operator =(const contenitore::iteratore & iter)
{
    p=iter.p;
    return *this;
}

template<class T>
typename contenitore::iteratore &contenitore::iteratore::operator++()
{
    if(p) p=p->next;
    return *this;
}

template<class T>
typename contenitore::iteratore &contenitore::iteratore::operator++(int)
{
    iteratore aux= *this;
    if(p) p=p->next;
    return aux;
}

template<class T>
T &contenitore::iteratore::operator*() const
{
    return p->info;
}

template<class T>
T *contenitore::iteratore::operator->() const
{
    return &(p->info);
}

template<class T>
bool contenitore::iteratore::operator ==(const contenitore::iteratore & iter)
{
    return p==iter.p;
}

template<class T>
bool contenitore::iteratore::operator !=(const contenitore::iteratore & iter)
{
    return p!=iter.p;
}


template<class T>
contenitore::iteratore contenitore::start()
{
    return iteratore(first);
}


template<class T>
contenitore::iteratore contenitore::fine()
{
    return iteratore(0);
}
