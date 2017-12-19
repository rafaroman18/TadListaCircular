#include <iostream>
#include "tadlistacircular.h"

int main()
{
    ListaCir<int> L;
    L.insertar(3,L.inipos());
    L.insertar(2,L.inipos());
    L.insertar(1,L.inipos());
    std::cout << L.elemento(L.inipos());
    return 0;
}