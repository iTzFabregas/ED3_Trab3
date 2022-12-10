#include<stdio.h>
#include<stdlib.h>

#include "register.h"
#include "grafo.h"

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
            if(grafo[j]->idConecta == -1){
                
            }
        }
    } 
}