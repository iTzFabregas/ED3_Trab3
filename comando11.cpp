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
        if (reg->unidadeMedida == 'G') {
            no.velocidade = reg->velocidade * 1024;

        } else {
            no.velocidade = reg->velocidade;
        }

        graph.insert_edge(vertice, no);
        
    }

    return graph;
}

void command13(char* file_name) {
    Graph graph = command11(file_name);
    int n;
    cin >> n;

    int origin;
    int destination;
    for (int i = 0; i < n; i++) {

        cin >> origin;
        cin >> destination;
        int flux = graph.dijkstra(origin, destination);
        if (flux == -1) {
            cout << "O fluxo máximo entre " << origin << " e " << destination << ": " << graph.dijkstra(origin, destination) << endl;
        } else {
            cout << "O fluxo máximo entre " << origin << " e " << destination << ": " << graph.dijkstra(origin, destination) << "Mbps\n";
        }
        
        
    }

}