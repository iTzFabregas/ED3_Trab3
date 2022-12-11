#include "comando11.hpp"
#include "register.hpp"
#include "classes.hpp"

using namespace std;

Graph command11(char* file_name){
    FILE* file = fopen(file_name, "rb");
    if(file == NULL){
        //TO DO
    }

    Header_reg* header = create_header();
    if(header == NULL){
        //TO DO>
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
        fseek(file, (LEN_REG*i) + LEN_DISC_PAG, SEEK_SET);
        read_register(file, reg);

        vertice.idConecta = reg->idConecta;
        vertice.nomePoPs = reg->nomePoPs;
        vertice.nomePais = reg->nomePais;
        vertice.siglaPais = reg->siglaPais;

        no.idPoPsConectado = reg->idPoPsConectado;
        no.velocidade = reg->velocidade * 1024;

        graph.insert_edge(vertice, no);
        
    }

    map<int, Vertex>::iterator it;
    list<no_lista>::iterator jt;
    
    for(it=graph.graph.begin(); it!=graph.graph.end(); ++it){
        for(jt = it->second.lista_adj.begin(); jt != it->second.lista_adj.end(); ++jt){
            cout << it->first << " " << it->second.nomePoPs << " "
            << it->second.nomePais << " "<< it->second.siglaPais << " "
            <<jt->idPoPsConectado <<" "<< jt->velocidade << "Mbps" << '\n';
        }        
    }

    return graph;
}

void command13(char* file_name) {
    Graph graph = command11(file_name);
    cout << "sair\n";
    int n;
    cin >> n;

    int origin;
    int destination;

    int speed;
    for (size_t i = 0; i < n; i++) {

        

    }

}