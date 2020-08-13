#include "ListaC.h"
#include <stdbool.h>

    void add(ListaC* l,NodoC* nuevo){
    if(l->head==NULL){
        l->head=nuevo;
    }else if(nuevo->val<=l->head->val){
        nuevo->derecha=l->head;
        l->head->izquierda=nuevo;
        l->head=nuevo;
    }else{
        NodoC* aux=l->head;
        while(aux->derecha!=NULL){
            if(aux->val>nuevo->val){
                    NodoC* ant=aux->izquierda;
                    ant->derecha=nuevo;
                    nuevo->izquierda=ant;
                    nuevo->derecha=aux;
                    aux->izquierda=nuevo;
                    return;
                }else if(nuevo->val<=aux->derecha->val){
                    NodoC *siguiente=aux->derecha;
                    aux->derecha=nuevo;
                    nuevo->derecha=aux;
                    nuevo->derecha=siguiente;
                    siguiente->izquierda=nuevo;
                    nuevo->izquierda=aux;
                    return;
                }
            aux=aux->derecha;
        }
        aux->derecha=nuevo;
        nuevo->izquierda=aux;
    }
}

void Liberar(ListaC* l){
    NodoA* aux=l->head;
    NodoA* tmp;
    while(aux!=NULL){
        tmp=aux->derecha;
        free(aux);
        aux=tmp;
    }
}

void imprimir(ListaC* l){
    NodoA* aux=l->head;
    while(aux!=NULL){
        printf("El valor es %i \n",aux->val);
        aux=aux->derecha;
    }
}
ListaC* nuevaLista(){
    ListaC* nueva=(ListaC*) malloc(sizeof(ListaC));
    nueva->head=NULL;
    return nueva;
}
void generar(ListaC* l){
    FILE * fp;
    fp=fopen("./cadigo.txt","w");
    if(fp==NULL){
        printf("Error");
        return;
    }
    char cad[1024];
    sprintf(cad,"digraph G{ \n rankdir=LR \n node [shape = record, style=\"rounded,filled\"fillcolor=\"orange:red\",width=0.7,height=0.5];\n");
    fputs(cad,fp);
    NodoC* aux;
    aux=l->head;
    guardarRecursivo(aux,fp,cad);
    sprintf(cad,"}\n");
    fputs(cad,fp);
    fclose(fp);
}

void guardarRecursivo(NodoC* aux,FILE* fp,char c[]){
    if(aux==NULL){
        return;
    }else{
        if(aux->derecha!=NULL){

            sprintf(c,"node%p[label=\"%i\"]\n",&(*aux),aux->val);
            fputs(c,fp);
            guardarRecursivo(aux->derecha,fp,c);
            sprintf(c,"node%p->node%p;\n node%p->node%p;\n",&(*aux),&(*aux->derecha),&(*aux->derecha),&(*aux));
            fputs(c,fp);
        }else{
            sprintf(c,"node%p[label=\"%i\"]\n",&(*aux),aux->val);
            fputs(c,fp);
        }
    }
}

void Buscar(ListaC* l, int indice)
{
    NodoC* aux;
    aux = l->head;
    bool encontrado = false;
    int contador = 1;
    if(aux != NULL)
    {
        while(aux != NULL && encontrado != true)
        {
            if(contador == indice)
            {
                encontrado = true;
            printf("\nEl valor del nodo es %i \n", aux->val);
            }
            aux = aux->derecha;
            contador++;
        }
        if(!encontrado)
        {
            printf("\nIndice no encontrado \n");
        }
    }
    else
    {
        printf("\nLista Vacia \n");
    }
}

void Eliminar(ListaC* l, int indice)
{
    int cont = 1;
    NodoC* aux;
    NodoC* temp;
    aux = l->head;
    temp = NULL;
    bool encontrado = false;
    if(l->head != NULL)
    {
        while(aux != NULL && encontrado != true)
        {
            if(cont == indice)
            {
                printf("\nIndice Encontrado %i\n",indice);
                printf("\nDato a Eliminar %i\n",aux->val);
                if(aux == l->head)
                {
                    l->head =l->head->derecha;
                    l->head->izquierda = NULL;
                }
                else if(aux->derecha == NULL)
                {
                    printf("el nodo a eliminar es el ultimo\n\n");
                    temp->derecha = NULL;
                    aux = temp;
                }
                else
                {
                    printf("el nodo a eliminar es de en medio\n\n");
                    temp->derecha = aux->derecha;
                    aux->derecha->izquierda = temp;
                }
                printf("NOdo Eliminado de la Lista\n\n");
                encontrado = true;
            }
            temp = aux;
            aux = aux->derecha;
            cont++;
        }
        if(!encontrado)
        {
            printf("\nIndice no Encontrado\n\n");
        }
    }
    else
    {
        printf("\nLa Lista esta Vacia");
    }
}
