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


void inserir_ordenado(Lista* lista, Data_reg* reg){
    if(lista == NULL){
        //TO DO        
        return;
    }

    No_Lista *no = malloc(sizeof(No_Lista));
    if(no == NULL){
        //TO DO
        return;
    }
    no->idPoPsConectado = reg->idPoPsConectado;
    no->velocidade = reg->velocidade;

    if((*lista) == NULL){
        no->prox = NULL;
        no->ant = NULL;
        *lista = no;
        return;
    } else {
        No_Lista *ante, *atual = *lista;
        while(atual != NULL && atual->idPoPsConectado < reg->idPoPsConectado){
            ante = atual;
            atual = atual->prox;
        }

        if(atual == *lista){ //inserir no inicio
            no->ant = NULL;
            (*lista)->ant = no;
            no->prox = (*lista);
            *lista = no;
        } else {
            no->prox = ante->prox;
            no->ant = ante;
            ante->prox = no;
            
            if(atual != NULL){
                atual->ant = no;
            }
        }
        return;
    }
}