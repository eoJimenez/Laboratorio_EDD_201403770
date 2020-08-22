#ifndef ARBOLBB_H
#define ARBOLBB_H
#include "NodoABB.h"
#include <iostream>

using namespace std;

class ArbolBB
{
    public:
        NodoABB *Raiz;
        ArbolBB();
        ~ArbolBB();
        void Insertar(int Key);
        NodoABB *Eliminar(int Key);
        void Delete(NodoABB* Raiz);
        void recorridoPre();
        void recorridoIn();
        void recorridoPost();

    protected:

    private:
        void InsertarRecursivo(int Key, NodoABB *Hoja);
        NodoABB *EliminarRecursivo(int Key, NodoABB *Hoja);
        void recorridoPreorden(NodoABB*);
        void recorridoInorden(NodoABB*);
        void recorridoPostorden(NodoABB*);
};

#endif // ARBOLBB_H
