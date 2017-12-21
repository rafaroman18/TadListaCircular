#include <iostream>
#include "tadlistacircular.h"
int main()
{
    using namespace std;
    ListaCir<int> L;int i;
    for(i=0;i<10;i++)
    {
        L.insertar(i,L.inipos());
    }
    //for(i=8;i!=0;i--){
    cout<<L.elemento(L.anterior(L.buscar(89)))<<endl;
    //}
    /*
    L.eliminar(L.buscar(9));
    for(int i=0;i<10;i++)
        cout<<L.elemento(L.buscar(i));
    cout<<endl;*/
    return 0;
}