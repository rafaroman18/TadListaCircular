#include <iostream>
#include "tadlistacircular.h"

int main()
{
    ListaCir<int> L;int i;
    i=0;
    for(i=0;i<10;i++)
    {
        L.insertar(i,L.inipos());
        std::cout<<L.elemento(L.inipos());
    }
    L.eliminar(L.inipos());
    std::cout<<std::endl;
    for(i=0;i<10;i++)
    {
        std::cout<<L.elemento(L.inipos());
    }
    std::cout<<std::endl;
    std::cout<<L.elemento(L.buscar(9));
    return 0;
}