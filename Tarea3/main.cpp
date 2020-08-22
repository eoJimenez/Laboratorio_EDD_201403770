#include <iostream>
#include "ArbolBB.h"

using namespace std;

int main()
{
    ArbolBB *arbol = new ArbolBB();
    arbol->Insertar(10);
    arbol->Insertar(1);
    arbol->Insertar(20);
    arbol->Insertar(15);
    arbol->Insertar(8);
    arbol->Insertar(96);
    arbol->Insertar(23);
    arbol->Insertar(4);
    arbol->Insertar(7);
    arbol->Insertar(32);
    arbol->recorridoIn();
    cout << "\n";
    arbol->recorridoPre();
    cout << "\n";
    arbol->recorridoPost();
    cout << "\n";
    arbol->Eliminar(1);
    arbol->Eliminar(15);
    arbol->Eliminar(96);
    arbol->recorridoIn();
    cout << "\n";
    delete arbol;
    return 0;
}
