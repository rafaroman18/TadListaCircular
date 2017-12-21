#include <iostream>
#include "tadlistacircular.h"
int main()
{
    using namespace std;
    ListaCir<int> L;int i;
    for(i=0;i<4;i++)
    {
        L.insertar(i,L.inipos());
    }
    /*for(i=9;i!=0;i--){
    cout<<L.elemento(L.anterior(L.buscar(i)))<<endl;
    }
    */
    L.eliminar(L.buscar(2));
    for(int i=0;i<3;i++)
        cout<<L.elemento(L.siguiente(L.inipos()));
    cout<<endl;
    return 0;
}