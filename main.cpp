#include <iostream>
#include "tadlistacircular.h"

int main()
{
    ListaCir<int> L;
    std::cout<<L.inipos();
    L.insertar(3,L.inipos());
    std::cout<<L.elemento(L.inipos());
    return 0;
}