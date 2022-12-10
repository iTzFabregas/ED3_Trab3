#include "register.hpp"
#include "classes.hpp"

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

    Graph graph; 
    Vertex vertice;
    no_lista no;

    for(int i = 0; i < header->proxRRN; i++){ //percorrer arquivo de dados
        read_register(file, reg);

        vertice.idConecta = reg->idConecta;
        vertice.nomePoPs = reg->nomePoPs;
        vertice.nomePais = reg->nomePais;
        vertice.siglaPais = reg->siglaPais;

        no.idPoPsConectado = reg->idPoPsConectado;
        no.velocidade = reg->velocidade;

        graph.insert_edge(vertice, no);
    }

    map<int, Vertex>::iterator it;
    for(it=graph.graph.begin(); it!=graph.graph.end(); ++it){
        cout << it->first << " => " << it->second.nomePoPs << '\n';
    }
}