#include "ArbolBB.h"

ArbolBB::ArbolBB()
{
    Raiz = NULL;
}

ArbolBB::~ArbolBB()
{
    Delete(this->Raiz);
}
void ArbolBB::Delete(NodoABB *Raiz)
{
    if(Raiz == NULL)
    {
        return;
    }
    Delete(Raiz->Izquierda);
    Delete(Raiz->Derecha);
    delete Raiz;
}
void ArbolBB::Insertar(int Key)
{
    if(Raiz != NULL)
    {
        InsertarRecursivo(Key,Raiz);
    }
    else
    {
        Raiz = new NodoABB(Key);
        Raiz->Izquierda = NULL;
        Raiz->Derecha = NULL;
    }
}
void ArbolBB::InsertarRecursivo(int Key, NodoABB* Hoja)
{
    if(Key < Hoja->dato)
    {
        if(Hoja->Izquierda != NULL)
        {
            InsertarRecursivo(Key,Hoja->Izquierda);
        }
        else
        {
            Hoja->Izquierda = new NodoABB(Key);
            Hoja->Izquierda->Izquierda = NULL;
            Hoja->Izquierda->Derecha = NULL;
        }
    }
    else if(Key > Hoja->dato)
    {
        if(Hoja->Derecha != NULL)
        {
            InsertarRecursivo(Key, Hoja->Derecha);
        }
        else
        {
            Hoja->Derecha = new NodoABB(Key);
            Hoja->Derecha->Izquierda = NULL;
            Hoja->Derecha->Derecha = NULL;
        }
    }
}
NodoABB *ArbolBB::Eliminar(int Key)
{
    return EliminarRecursivo(Key,Raiz);
}
NodoABB *ArbolBB::EliminarRecursivo(int Key, NodoABB* Hoja)
{
    if(Hoja == NULL)
    {
        return Hoja;
    }
    if(Hoja->dato > Key)
    {
        Hoja->Izquierda = EliminarRecursivo(Key,Hoja->Izquierda);
        return Hoja;
    }
    else if(Hoja->dato < Key)
    {
        Hoja->Derecha = EliminarRecursivo(Key, Hoja->Derecha);
        return Hoja;
    }
    if(Hoja->Izquierda == NULL)
    {
        NodoABB *temp = Hoja->Derecha;
        delete Hoja;
        return temp;
    }
    else if(Hoja->Derecha == NULL)
    {
        NodoABB *temp = Hoja->Izquierda;
        delete Hoja;
        return temp;
    }
    else
    {
        NodoABB *aux = Hoja->Derecha;
        NodoABB *temp = Hoja->Derecha;
        while(temp->Izquierda != NULL)
        {
            aux = temp;
            temp = temp->Izquierda;
        }
        aux->Izquierda = temp->Derecha;
        Hoja->dato = temp->dato;
        delete temp;
        return Hoja;
    }
}
void ArbolBB::recorridoPre()
{
    if(Raiz != NULL)
    {
        recorridoPreorden(Raiz);
    }
}
void ArbolBB::recorridoPreorden(NodoABB* R)
{
    cout << R->dato << "-";
    if(R->Izquierda != NULL)
    {
        recorridoPreorden(R->Izquierda);
    }
    if(R->Derecha != NULL)
    {
        recorridoPreorden(R->Derecha);
    }
}
void ArbolBB::recorridoIn()
{
    if(Raiz != NULL)
    {
        recorridoInorden(Raiz);
    }
}
void ArbolBB::recorridoInorden(NodoABB*R)
{
    if(R->Izquierda != NULL)
    {
        recorridoInorden(R->Izquierda);
    }
    cout << R->dato << "-";
    if(R->Derecha != NULL)
    {
        recorridoInorden(R->Derecha);
    }
}
void ArbolBB::recorridoPost()
{
    if(Raiz != NULL)
    {
        recorridoPostorden(Raiz);
    }
}
void ArbolBB::recorridoPostorden(NodoABB* R)
{
    if(R->Izquierda != NULL)
    {
        recorridoPostorden(R->Izquierda);
    }
    if(R->Derecha != NULL)
    {
        recorridoPostorden(R->Derecha);
    }
    cout << R->dato << "-";
}


