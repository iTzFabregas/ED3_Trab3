#include<stdlib.h>

#include "grafo.h"
#include "register.h"

Lista* criar_lista(){
    Lista* lista = malloc(sizeof(Lista));
    if(lista == NULL){
        //TO DO
    }
    return lista;
}

Grafo* criar_grafo(){
    Grafo* grafo = malloc(sizeof(Grafo));
    grafo->idConecta = -1;

    grafo->lista_adj = criar_lista();

    return grafo;
}


void inserir_grafo(Grafo* grafo, Data_reg* reg){
    
    
}