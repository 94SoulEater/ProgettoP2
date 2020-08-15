#ifndef PUNTATORESMART_H
#define PUNTATORESMART_H

template<class T>
class puntatoresmart{
private:
    T* puntatore;
public:
    puntatoresmart(const T* p=0);
    puntatoresmart(const puntatoresmart& x);
    ~puntatoresmart();
    puntatoresmart& operator=(const puntatoresmart& x);
    bool operator==(const puntatoresmart& x) const;
    T& operator*() const;
};

template <class T>
puntatoresmart<T>::puntatoresmart(const T* p): puntatore(p ? new T(*p) : 0){
}

template <class T>
puntatoresmart<T>::puntatoresmart(const puntatoresmart<T>& x):puntatore(x.puntatore ? new T(*(x.puntatore)) : 0){
}

template <class T>
puntatoresmart<T>::~puntatoresmart(){
    if(puntatore) delete puntatore;
}

template <class T>
puntatoresmart<T>& puntatoresmart<T>::operator=(const puntatoresmart& x){
    if(this != &x){
        delete puntatore;
        puntatore = x.puntatore ? new T(*(x.puntatore)) : 0;
    }
    return *this;
}

template <class T>
T& puntatoresmart<T>::operator*() const{
    return *puntatore;
}

template <class T>
bool puntatoresmart<T>::operator==(const puntatoresmart& x) const{
    return *puntatore == *(x.puntatore);
}

#endif // PUNTATORESMART_H