#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "register.h"
#include "grafo.h"

void bubble_sort(Grafo* vetor[], int tamanho){
    Grafo* aux;

	for(int j=tamanho-1; j>=1; j--){
		for(int i=0; i<j; i++){
			if(vetor[i]->idConecta >vetor[i+1]->idConecta){
				aux=vetor[i];
                vetor[i]=vetor[i+1];
                vetor[i+1]=aux;
            }
        }
    }
}

void command11(char* file_name){
    FILE* file = fopen(file_name, "rb");
    if(file == NULL){
        //TO DO
    }

    Header_reg* header = create_header();
    if(header == NULL){
        //TO DO
    }
    read_header(header, file);

    Data_reg* reg = create_reg();
    if(reg == NULL){
        //TO DO
    }

    Grafo* grafo[header->proxRRN];
    for(int i = 0; i < header->proxRRN; i++){
        grafo[i] = criar_grafo();
    }

    for(int i = 0; i < header->proxRRN; i++){
        read_register(file, reg);

        for(int j = 0; j < header->proxRRN; j++){
            if(grafo[j]->idConecta == -1){ //posicao vazia
                grafo[j]->idConecta = reg->idConecta;
                strcpy(grafo[j]->nomePoPs, reg->nomePoPs);
                strcpy(grafo[j]->nomePais, reg->nomePais);
                strcpy(grafo[j]->siglaPais, reg->siglaPais);
                break;
            } else if(grafo[j]->idConecta == reg->idConecta){ //inserir na lista adj
                inserir_ordenado(grafo[j]->lista_adj, reg);
                break;
            }
        }
    }

    bubble_sort(grafo, header->proxRRN);

    for(int j = 0; j < header->proxRRN; j++){
        if(grafo[j]->idConecta == -1){
            continue;
        } else {
            printf("%d %s\n", grafo[j]->idConecta, grafo[j]->nomePais);
        }
    }
}