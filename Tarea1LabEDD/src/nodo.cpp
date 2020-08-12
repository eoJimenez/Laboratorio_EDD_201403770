#include "nodo.h"

Nodo::Nodo(int val)
{
    this->val=val;
    this->derecha=NULL;
    this->izquierda=NULL;
}

int Nodo::getVal(){return this->val;}
void Nodo::setVal(int val){this->val=val;}
void Nodo::setDerecha(Nodo *derecha){this->derecha=derecha;}
void Nodo::setIzquierda(Nodo *izquierda){this->izquierda=izquierda;}
Nodo* Nodo::getDerecha(){return this->derecha;}
Nodo* Nodo::getIzquierda(){return this->izquierda;}
