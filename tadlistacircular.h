#ifndef TADCIRCULAR_TADLISTACIRCULAR_H
#define TADCIRCULAR_TADLISTACIRCULAR_H
#define POS_NULA NULL
#include <iostream>
#include <cassert>
//ESPECIFICACION
/*
 Definicion:
 Una lista circular es una secuencia de elementos de un mismo tipo en la que todos tienen un predecesor
 y un sucesor, es decir, es una secuencia sin extremos. Su longitud coincide con el numero de elementos
 que la forman; si es 0, entonces la lista está vacía. Una lista circular de longitud n se puede representar
 de la forma
                L = (a1, a2, . . . , an, a1)
 donde repetimos a1 despues de an para indicar que el elemento que sigue a an es a1 y el anterior a este es
 an.
 Definimos una posicion como el lugar para indicar que ocupa un elemento en la lista. La constante POS_NULA
 denota una posicion inexistente
*/
template <typename T> class ListaCir
{
    struct nodo;
public:
    typedef nodo* posicion;
    ListaCir();
    ListaCir(const ListaCir<T>& l);
    ListaCir<T>&operator=(const ListaCir<T>& l);
    void insertar(const T& x,posicion p);
    void eliminar(posicion p);
    const T& elemento(posicion p)const;
    posicion buscar(const T& x)const;
    posicion inipos()const;
    posicion siguiente(posicion p)const;
    posicion anterior(posicion p)const ;
    ~ListaCir();

private:
    struct nodo
    {
        T elto;
        nodo* sig;
        nodo(const T& e,nodo*p=0):elto(e),sig(p){};
    };
    nodo* L;
    void copiar(const ListaCir<T>& l);
};
//Operaciones:

//Postcondicion: Crea  y devuelve una lista circular vacia
template <typename T>
inline ListaCir<T>::ListaCir():L(new nodo (T())){};

//Precondicion: L=(a1,a2,...,an,a1)
//Postcondicion:Devuelve la copia de un lista
template <typename T>
inline ListaCir<T>::ListaCir(const ListaCir<T> &l)
{
    copiar(l);
}

//Precondicion: L=(a1,a2,...,an,a1)
//Postcondicion: Devuelve una copia de la cadena L
template<typename T>
void ListaCir<T>::copiar(const ListaCir<T> &l)
{
    L = new nodo(T());
    posicion q=L;
    for(nodo*r=l.L->sig;r;r=r->sig)
    {
        q->sig=new nodo(r->elto);
        q=q->sig;
    }
    q->sig=L;                  //Añade al siguiente puntero, la posicion inicial
    L=q;                       //Coloca la cabcera L en el ultimo elemento
}

//Precondicion:Recibe una lista circular de la forma L=(a1,a2,...,an,a1)
//Postcondicion: Devuelve esa lista circular modificada, igualandola a la
// anterior al operador
template <typename T>
ListaCir<T>& ListaCir<T>::operator=(const ListaCir<T>& l)
{
    if(this!=&l)
    {
        this->~ListaCir();
        copiar(l);
    }
    return *this;
}
//Precondicion: L=() y p es irrelevante o bien, L=(a1,a2,...an,a1) y 1<=p<=n
//Postcondicion: Si L=(),entonces L=(x,x)
//(lista circular con un unico elemento)
//En caso contrario: L=(a1,a2...a(p-1),x,ap,...,an,a1)
template <typename T> inline
void ListaCir<T>::insertar(const T& x, ListaCir<T>::posicion p)
{
    if(!p)
    {
        p=new nodo(x,p);
        L=p;                                        //Añadimos esta linea para que si
        p->sig=p;
    }                                               //nos encontramos el caso de una lista
    else
                                        //vacia o que quiera colocar en la ultima posicion
        p->sig=new nodo(x,p->sig);                  //la funcion recoloque el puntero L hacia el ultimo
         if(p==this->L)
             L=p->sig;

}


//Precondicion: L=(a1,a2,...an,a1),1<=p<=n
//Postcondicion: L=(a1,a2,...a(p-1),a(p+1),...an,a1)
template <typename T>
inline void ListaCir<T>::eliminar(ListaCir<T>::posicion p)
{
    assert(p->sig);
    posicion q=p->sig;
    if(L==p)                        //Comprobamos que p no es fin
    {
        while(q->sig!=L)
        {
            q=q->sig;
        }
        p=q;
        p->sig=L->sig;
        L=p;
    }
    else {
        while(q->sig!=p)
        {
            q=q->sig;
        }
        p=q;
        q=q->sig;
        p->sig=q->sig;

    }}

//Precondicion: L=(a1,a2,...an,a1, y 1<=p<=n
//Postcondicion: Devuelve el elemento ubicado en la posicion p, es decir, ap
template<typename T>
inline const T& ListaCir<T>::elemento(ListaCir<T>::posicion p) const
{
    //assert(p->sig);           //Comprobamos que p no es fin
    return p->elto;
}

//Postcondicion:Devuelve la posicion p que ocupa el elemento x en la lista, si este no se
//encuentra en ella, devuelve POS_NULA
template <typename T>
typename ListaCir<T>::posicion
ListaCir<T>::buscar(const T& x) const
{
    nodo* q=L->sig;
    bool encontrado=false;
    while(q!=L && !encontrado)
    {
        if(q->sig->elto==x)
            encontrado=true;
        else q=q->sig;
    }
    if(!encontrado){ q->sig->elto=POS_NULA;}
    return q->sig;
}

//Precondiciones:L=(a1,a2,...an,a1)
//Postcondicion:Devuelve una posicion indeterminada de la lista, si esta vacia,
//devuelve POS_NULA
template <typename T>
typename ListaCir<T>::posicion
ListaCir<T>::inipos() const
{
    posicion NODO;

    if(!this->L->sig) NODO=POS_NULA; //Si el nodo tiene un unico elemento, creamos uno nuevo y le introducimos el valor de este mismo, es decir, lo enlazamos a él mismo

    else NODO=this->L;

    return NODO;
}


//Precondicion:L=(a1,a2,...an,a1) y 1<=p<=n
//Postcondicion:Devuelve la siguiente posicion a la actual p
template <typename T>
typename ListaCir<T>::posicion
ListaCir<T>::siguiente(ListaCir<T>::posicion p)const
{
    assert(p->sig);
    return p->sig;
}


//Precondicion: L=(a1,a2,...,an,a1) y 1<=p<=n
//Postcondicion: Devuelve la anterior posicion de p
template <typename T>
typename ListaCir<T>::posicion
ListaCir<T>::anterior (ListaCir<T>::posicion p) const
{
    assert(p->sig);
    nodo*q; //p no es la primera posicion
    for(q=L->sig;q->sig!=p;q=q->sig);
    return q;
}

template <typename T>
inline ListaCir<T>::~ListaCir()
{
    if(!L)  //Si la Lista esta vacia solo elimina la cabecera
    {
        nodo* q;
        while (L->sig != L)//Controlamos que la cabezera apunte a ella misma
        {
            q = L->sig;
            L->sig = q->sig;
            delete q;
        }
    }
    delete L;//eliminacion la cabecera
}
#endif //TADCIRCULAR_TADLISTACIRCULAR_H
