#include <iostream>
#include "tadlistacircular.h"

int main()
{
    ListaCir<int> L;int i;
    for(i=0;i<10;i++)
    {
    L.insertar(i,L.inipos());
    }
    std::cout << L.elemento(L.inipos());
    L.~ListaCir();
    return 0;
}