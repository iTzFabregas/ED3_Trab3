#include "commands.hpp"

using namespace std;

Graph command11(char* file_name){

    Graph graph; 

    // ABRE E FAZ A LEITURA DO HEADER PARA VER SE O ARQUIVO ESTA ESTÁVEL
    FILE* file = fopen(file_name, "rb");
    if(file == NULL){
        cout << "Falha na execução da funcionalidade." << endl;
        return graph;
    }

    Header_reg* header = create_header();
    read_header(header, file);
    if (header->status == '0') {
        fclose(file);
        cout << "Falha na execução da funcionalidade." << endl;
        return graph;
    }

    Data_reg* reg = create_reg();

    Vertex vertex;
    Edge edge;

    // PERCORRE TODOS OS REGISTROS DO ARQUIVO
    for(int i = 0; i < header->proxRRN; i++){
        fseek(file, (LEN_REG*i) + LEN_DISC_PAG, SEEK_SET);
        read_register(file, reg);

        // COLOCA AS INFORMAÇÕES TIRADAS DO ARQUIVO NO VERTICE
        vertex.idConecta = reg->idConecta;
        vertex.nomePoPs = reg->nomePoPs;
        vertex.nomePais = reg->nomePais;
        vertex.siglaPais = reg->siglaPais;

        // COLOCA AS INFORMAÇÕES TIRADAS DO ARQUIVO NA ARESTA
        edge.idPoPsConectado = reg->idPoPsConectado;
        if (reg->unidadeMedida == 'G') {
            edge.velocidade = reg->velocidade * 1024;

        } else {
            edge.velocidade = reg->velocidade;
        }

        // INSERE A ARESTA NO GRAFO
        graph.insert_edge(vertex, edge);
        
    }

    fclose(file);
    free(header);
    free(reg);
    return graph;
}

void command12(char* file_name){

    Graph graph = command11(file_name);
    cout << "Quantidade de ciclos: " << graph.dfs() << endl;

}

/*
void command13(char* file_name) {
    Graph graph = command11(file_name);
    int n;
    cin >> n;

    int origin;
    int destination;
    for (int i = 0; i < n; i++) {

        cin >> origin;
        cin >> destination;
        int max_flux;
        graph.dijkstra(origin, destination, &max_flux);
        if (max_flux == -1) {
            cout << "Fluxo máximo entre " << origin << " e " << destination << ": " << max_flux << endl;
        } else {
            cout << "Fluxo máximo entre " << origin << " e " << destination << ": " << max_flux << "Mbps\n";
        }
        
        
    }
}
*/

void command14(char* file_name) {

    // CHAMA O COMANDO 11 PARA CONSTRUIR O GRAFO
    Graph graph = command11(file_name);
    int n;
    cin >> n;

    int origin;
    int stop;
    int destination;

    for (size_t i = 0; i < n; i++) {
        cin >> origin;
        cin >> destination;
        cin >> stop;

        // CHAMA O DIJKSTRA PARA ACHAR O MLEHOR CAMINHO ENTRE OS VERTICES
        int flux1 = graph.dijkstra(origin, stop);
        int flux2 = graph.dijkstra(stop, destination);

        // PRINTA O MELHOR CAMINHO ACHADO, SE ACHADO
        if (flux1 == -1 || flux2 == -1) {
            cout << "Comprimento do caminho entre " << origin << " e " 
            << destination << " parando em " << stop << ": -1" << endl;
        } else {
            cout << "Comprimento do caminho entre " << origin << " e " 
            << destination << " parando em " << stop << ": " << flux1+flux2
            << "Mbps" << endl;
        }
    }
    
}