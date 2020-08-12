#include "listadoble.h"

ListaDoble::ListaDoble()
{
    this->head=NULL;

}
ListaDoble::~ListaDoble(){
    Nodo* aux=this->head;
    Nodo* tmp;
    while(aux!=NULL){
        tmp=aux->getDerecha();
        delete aux;
        aux=tmp;
    }
}
void ListaDoble::insertarOrdenado(Nodo *nuevo){
    if(this->head==NULL){
        this->head=nuevo;
    }else{
        int valorcabeza=this->head->getVal();
        int valornuevo=nuevo->getVal();
        if(valornuevo<=valorcabeza){
            nuevo->setDerecha(this->head);
            this->head->setIzquierda(nuevo);
            this->head=nuevo;
        }else{
            Nodo* aux=this->head;
            while(aux!=NULL){
                if(aux->getIzquierda()!=NULL){
                    if(valornuevo>aux->getIzquierda()->getVal()&&valornuevo<=aux->getVal()){
                        Nodo *izq=aux->getIzquierda();
                        Nodo *der=aux;
                        izq->setDerecha(nuevo);
                        nuevo->setIzquierda(izq);
                        nuevo->setDerecha(der);
                        der->setIzquierda(nuevo);
                        break;
                    }
                }
                if(aux->getDerecha()==NULL){
                    aux->setDerecha(nuevo);
                    nuevo->setIzquierda(aux);
                    break;
                }
                aux=aux->getDerecha();
            }
        }
    }
}

string ListaDoble::generar(){
    ostringstream cadena;
    cadena<<"digraph G {"<<endl<<"node [shape = record, style=\"rounded,filled\"fillcolor=\"orange:red\",width=0.7,height=0.5];"<<endl;
    cadena<<"rankdir=LR;"<<endl;
    cadena<<generar(this->head)<<endl;
    cadena<<"}"<<endl;
    return cadena.str();
}
string ListaDoble::generar(Nodo* aux){
    ostringstream cadena;
    if(aux!=NULL){
        cadena<<"nodo"<<&(*aux)<<"[label=\""<<aux->getVal()<<"\"];"<<endl;
        Nodo* siguiente=aux->getDerecha();
        //Creacion de nodos

        cadena<< (siguiente==NULL?"":generar(siguiente));
        //Union de nodos
        if(siguiente!=NULL){
            cadena<<"nodo"<<&(*siguiente)<<"->nodo"<<&(*aux)<<";"<<endl;
            cadena<<"nodo"<<&(*aux)<<"->nodo"<<&(*siguiente)<<";"<<endl;
        }
    }
    return cadena.str();
}

void ListaDoble::imprimir(){
    Nodo* aux=this->head;
    while(aux!=NULL){
        cout<<"Elemento : "<<aux->getVal()<<endl;
        aux=aux->getDerecha();
    }
    cout<<"------------------------------"<<endl;
}

void ListaDoble::Eliminar(int indice){
    int contador = 1;
    Nodo *aux = this->head;
    Nodo *anterior = NULL;
    bool encontrado = false;
    if(head != NULL)
    {
        while(aux != NULL & encontrado != true)
        {
            if(contador == indice)
            {
                ///Esta porcion de codigo si funciona
                cout <<"\ indice encontrado ( "<<indice<<") Eliminado \n";
                if(aux == head)
                {
                    head = head->getDerecha();
                    head->getIzquierda() == NULL;
                }
                /// Aca hay errores de apundatores
                else if(aux->getDerecha() == NULL)
                {
                    cout << "\n segunda condicion Else If: "<< aux->getVal()<< "\n";
                    cout << anterior->getVal()<< "\n";
                    anterior->getDerecha() == NULL;
                    aux->getIzquierda() == NULL;
                    aux = anterior;

                }
                else
                {
                    cout << "\n tercera condicion Else \n\n";
                    anterior->getDerecha() == aux->getDerecha();
                    aux->getDerecha()->getIzquierda() == anterior;
                }
                cout << "\n Nodo Eliminado de la lista\n\n";
                encontrado = true;
            }
            anterior = aux;
            aux = aux->getDerecha();
            contador ++;
        }
        if(!encontrado)
        {
            cout << "\n Indice no encotrado\n\n";
        }
    }
    else
    {
        cout << "\n La lista se encuetra Vacia\n\n";
    }
}

void ListaDoble::Buscar(int indice)
{
    Nodo *actual = this->head;
    bool encontrado = false;
    int contador = 1;
    if(head != NULL)
    {
        while(actual != NULL && encontrado != true)
        {
            if(contador == indice)
            {
                encontrado = true;
                //return actual->getVal();
                cout << "El valor del nodo es: " << actual->getVal() <<"\n";
            }
            actual = actual->getDerecha();
            contador ++;
        }
        if(!encontrado)
        {
            cout << "\n Indice no Encontrado \n\n";
        }
    }
    else
    {
        cout << "\n Lista Vacia \n\n";
        //return NULL;
    }
}
