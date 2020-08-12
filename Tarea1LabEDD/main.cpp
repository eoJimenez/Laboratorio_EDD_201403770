#include <iostream>
#include "listadoble.h"
#include "nodo.h"
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    ListaDoble *list=new ListaDoble();
    Nodo *a,*b,*c,*d,*e,*f,*g,*h,*i,*j;
    a=new Nodo(20);
    b=new Nodo(25);
    c=new Nodo(2);
    d=new Nodo(201);
    e=new Nodo(80);
    f=new Nodo(10);
    g=new Nodo(1000);
    h=new Nodo(300);
    i=new Nodo(1);
    j=new Nodo(250);

    list->insertarOrdenado(a);
    list->insertarOrdenado(b);
    list->insertarOrdenado(c);
    list->insertarOrdenado(d);
    list->insertarOrdenado(e);
    list->insertarOrdenado(f);
    list->insertarOrdenado(g);
    list->insertarOrdenado(h);
    list->insertarOrdenado(i);
    list->insertarOrdenado(j);

    list->Buscar(10);
    list->Buscar(1);
    list->Buscar(5);
    list->Buscar(11);
    list->imprimir();


    list->Eliminar(10);
    list->imprimir();/*
    list->Eliminar();
    list->imprimir();*/
    ofstream file("salida.dot");
    file<<list->generar();
    file.close();

    system("dot -Tpng salida.dot -o imagen.png");
    delete list;
    return 0;
}
