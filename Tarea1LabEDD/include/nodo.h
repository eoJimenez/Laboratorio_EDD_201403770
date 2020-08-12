#ifndef NODO_H
#define NODO_H
#include <iostream>

class Nodo
{
public:
    Nodo(int val);
    Nodo *getDerecha();
    Nodo *getIzquierda();
    void setDerecha(Nodo *derecha);
    void setIzquierda(Nodo *izquierda);
    void setVal(int val);
    int getVal();
private:
    Nodo *izquierda;
    Nodo *derecha;
    int val;
};

#endif // NODO_H
