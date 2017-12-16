#ifndef TADCIRCULAR_TADLISTACIRCULAR_H
#define TADCIRCULAR_TADLISTACIRCULAR_H
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
inline ListaCir<T>::ListaCir():L(new nodo(T())){};

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
    nodo*q=L;
    for(nodo*r=l.L->sig;r;r=r->sig)
    {
        q->sig=new nodo(r->elto);
        q=q->sig;
    }
    q->sig=L->sig;                  //Añade al siguiente puntero, la posicion inicial
    L->sig=q;                       //Coloca la cabcera L en el ultimo elemento
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
    if(!p->sig)
    {
        p->sig=new nodo(x,p->sig);
        L->sig=p->sig;                          //Añadimos esta linea para que si
    }                                           //nos encontramos el caso de una lista
    else                                        //vacia o que quiera colocar en la ultima posicion
        p->sig=new nodo(x,p->sig);              //la funcion recoloque el puntero L hacia el ultimo

}


//Precondicion: L=(a1,a2,...an,a1),1<=p<=n
//Postcondicion: L=(a1,a2,...a(p-1),a(p+1),...an,a1)
template <typename T>
inline void ListaCir<T>::eliminar(ListaCir<T>::posicion p)
{
    assert(p->sig);
    nodo* q=p->sig;
    p->sig=q->sig;
    L->sig=p;                                   //L apunta ahora al ultimo
    delete q;
}

//Precondicion: L=(a1,a2,...an,a1, y 1<=p<=n
//Postcondicion: Devuelve el elemento ubicado en la posicion p, es decir, ap
template<typename T>
inline const T& ListaCir<T>::elemento(ListaCir<T>::posicion p) const
{
    assert(p->sig);
    return p->sig->elto;
}

//Postcondicion:Devuelve la posicion p que ocupa el elemento x en la lista, si este no se
//encuentra en ella, devuelve POS_NULA
template <typename T>
posicion buscar(const T& x)const
{

}


//Precondiciones:L=(a1,a2,...an,a1)
//Postcondicion:Devuelve una posicion indeterminada de la lista, si esta vacia,
//devuelve POS_NULA
posicion inipos() const
{

}


//Precondicion:L=(a1,a2,...an,a1) y 1<=p<=n
//Postcondicion:Devuelve la siguiente posicion a la actual p
posicion siguiente(posicion p)const
{

}


//Precondicion: L=(a1,a2,...,an,a1) y 1<=p<=n
//Postcondicion: Devuelve la anterior posicion de p
posicion anterior (posicion p) const
{

}



#endif //TADCIRCULAR_TADLISTACIRCULAR_H
