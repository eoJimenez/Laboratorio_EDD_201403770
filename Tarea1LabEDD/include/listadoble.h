#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include "nodo.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class ListaDoble
{
public:
    ListaDoble();
    ~ListaDoble();
    void insertarOrdenado(Nodo *nuevo);
    string generar();
    string generar(Nodo* aux);
    void imprimir();
    void Eliminar(int i);
    void Buscar(int i);
private:
    Nodo* head;
};

#endif // LISTADOBLE_H
