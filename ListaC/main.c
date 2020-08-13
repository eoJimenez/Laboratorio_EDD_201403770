#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "ListaC.h"
#include "NodoC.h"
int main(){
    NodoA* a=newNodoC(10);
    NodoA* b=newNodoC(5);
    NodoC* c=newNodoC(25);
    NodoC* d=newNodoC(45);
    NodoA* e=newNodoC(20);
    NodoA* f=newNodoC(50);
    NodoC* g=newNodoC(2);
    NodoC* h=newNodoC(145);
    ListaC* l=nuevaLista();
    add(l,a);
    add(l,b);
    add(l,c);
    add(l,d);
    add(l,e);
    add(l,f);
    add(l,g);
    add(l,h);
    imprimir(l);
    Buscar(l,5);
    Eliminar(l,1);
    imprimir(l);
    Eliminar(l,4);
    imprimir(l);
    Eliminar(l,6);
    imprimir(l);
    generar(l);
    Liberar(l);
    free(l);
    return 0;
}

