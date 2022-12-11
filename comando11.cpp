#include "comando11.hpp"

using namespace std;

Graph command11(char* file_name){

    Graph graph; 

    FILE* file = fopen(file_name, "rb");
    if(file == NULL){
        cout << "Falha na execução da funcionalidade." << endl;
        return graph;
    }

    Header_reg* header = create_header();
    read_header(header, file);
    if (header->status == '0') {
        cout << "Falha na execução da funcionalidade." << endl;
        return graph;
    }

    Data_reg* reg = create_reg();

    Vertex vertice;
    Edge edge;

    for(int i = 0; i < header->proxRRN; i++){ //percorrer arquivo de dados
        fseek(file, (LEN_REG*i) + LEN_DISC_PAG, SEEK_SET);
        read_register(file, reg);

        vertice.idConecta = reg->idConecta;
        vertice.nomePoPs = reg->nomePoPs;
        vertice.nomePais = reg->nomePais;
        vertice.siglaPais = reg->siglaPais;

        edge.idPoPsConectado = reg->idPoPsConectado;
        if (reg->unidadeMedida == 'G') {
            edge.velocidade = reg->velocidade * 1024;

        } else {
            edge.velocidade = reg->velocidade;
        }

        graph.insert_edge(vertice, edge);
        
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
            cout << "Fluxo máximo entre " << origin << " e " << destination << ": " << graph.dijkstra(origin, destination) << endl;
        } else {
            cout << "Fluxo máximo entre " << origin << " e " << destination << ": " << graph.dijkstra(origin, destination) << "Mbps\n";
        }
        
        
    }

}