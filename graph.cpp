#include "graph.hpp"

using namespace std;

// FUNÇÃO CRIADA PARA QUE O .sort() FUNCIONE PARA ORDENAR STRUCTS Edge
bool Edge_compare (const Edge a,const Edge b)
{
    return a.idPoPsConectado < b.idPoPsConectado;
}


void Graph::insert_edge(Vertex vertex1, Edge edge) { //paramentro idConecta

    map<int, Vertex>::iterator it;
    it = this->graph_map.find(vertex1.idConecta);

    // SE JA EXISTIR ESSE VERTICE, PUXA DO MAP AS INFORMAÇÕES QUE JA TEM
    if (it != this->graph_map.end()) {
        vertex1.lista_adj = it->second.lista_adj;
    }

    // SE TIVER UMA LIGAÇÃO, FAZ PUSH NA LISTA DE ADJACENCIA
    if (edge.velocidade >= 0 ) {
        vertex1.lista_adj.push_front(edge);
        vertex1.lista_adj.sort(Edge_compare);
    }

    // SE NAO TIVER O VERTICE NO MAP, INSERE, SE TIVER APENAS IGUALA AO VERTICE ATUALIZADO
    if (it == this->graph_map.end()) {
        graph_map.insert(make_pair(vertex1.idConecta, vertex1));

    } else {
        it->second = vertex1;
    }

    // SE TIVER LIGAÇÃO, VAI TER IDPOPS, ENTAO FAZER A MESMA IDEIA DE VERIFICAR SE
    // EXISTE E DAR INSERT OU APENAS DAR PUSH NA LISTA DE ADJACENCIA
    if (edge.velocidade >= 0) {
        it = this->graph_map.find(edge.idPoPsConectado);
        Vertex vertex2;
        if (it != this->graph_map.end()) {
            vertex2 = it->second;
        } else {
            vertex2.idConecta = edge.idPoPsConectado;
        }

        edge.idPoPsConectado = vertex1.idConecta;
        vertex2.lista_adj.push_front(edge);
        vertex2.lista_adj.sort(Edge_compare);

        if (it == this->graph_map.end()) {
            graph_map.insert(make_pair(vertex2.idConecta, vertex2));
            
        } else {
            it->second.lista_adj = vertex2.lista_adj;
        }
    }

    // ATUALIZA O NUMERO DE VERTICES
    this->num_vert = this->graph_map.size();
}

void Graph::print_graph() {

    map<int, Vertex>::iterator it;
    list<Edge>::iterator jt;

    for(it=graph_map.begin(); it!=graph_map.end(); ++it){
        for(jt = it->second.lista_adj.begin(); jt != it->second.lista_adj.end(); ++jt){
            cout << it->first << " " << it->second.nomePoPs << " "
            << it->second.nomePais << " "<< it->second.siglaPais << " "
            <<jt->idPoPsConectado <<" "<< jt->velocidade << "Mbps" << '\n';
        }        
    }
}

int Graph::dijkstra(int orig, int dest) {

    int distance[this->num_vert];
    bool visited[this->num_vert];

    // O GREATER FAZ COM QUE A MAX PRIORITY QUEUE, SEJA UMA MIN PRIORITY QUEUE
    priority_queue< 
                        pair<int,int>, 
                        vector< pair<int,int> >,
                        greater< pair<int,int> > 
                    > queue;

    // RESETA OS VETORES DE DISTANCIA E VISITADOS
    for (int i = 0; i < this->num_vert; i++) {
        distance[i] = INFINITE;
        visited[i] = false;
    }
    distance[orig] = 0;

    // COLOCA O VERTICE DA ORIGEM NA QUEUE 
    queue.push(make_pair(orig, distance[orig]));

    map<int, Vertex>::iterator it;
    while(!queue.empty()) {

        // PEGA O VALOR QUE ESTA NO TOPO DA PILHA
        pair<int, int> current = queue.top();
        it = this->graph_map.find(current.first);
        Vertex current_vertex = it->second;

        queue.pop();
        
        // SE ELE NÃO TIVER SIDO VISITADO AINDA
        if (visited[current_vertex.idConecta] == false) {
            visited[current_vertex.idConecta] == true;

            list<Edge>::iterator jt;

            // PERCORRE TODOS OS VERTICES ADJACENTES
            for(jt = current_vertex.lista_adj.begin(); jt != current_vertex.lista_adj.end(); jt++) {
                int adj_vertex = jt->idPoPsConectado;
                int cost = jt->velocidade;

                // RELAXAMENTO DA ARESTA
                if (distance[adj_vertex] > (distance[current_vertex.idConecta] + cost)) {
                    // ATUALIZA O NOVO VALOR DA DISTANCIA ATÉ ESSE VERTICE
                    distance[adj_vertex] = distance[current_vertex.idConecta] + cost;
                    queue.push(make_pair(adj_vertex, distance[adj_vertex]));
                }   
            }
        }
    }

    // SE A DISTANCIA AINDA FOR "INFINITA" QUER DIZER Q NAO FOI POSSÍVEL CHEGAR NESSE VERTICE
    if (distance[dest] != INFINITE) {
        return distance[dest];
    } else {
        return -1;
    }
}

/*
int Graph::dfs(){
    int num_cycles = 0;
    map<int, int> visited;

    map<int, Vertex>::iterator it;
    for(it=graph_map.begin(); it!=graph_map.end(); ++it){
        visited.insert(make_pair(it->first, WHITE));
    }

    list<Edge>::iterator jt;
    
    for(it=graph_map.begin(); it!=graph_map.end(); it++){
        visited[it->first] = GRAY;

        for(jt = it->second.lista_adj.begin(); jt != it->second.lista_adj.end(); jt++){
            if(visited[jt->idPoPsConectado] == WHITE){
                visited[jt->idPoPsConectado] = GRAY;
            } else if(visited[jt->idPoPsConectado] == GRAY){
                visited[jt->idPoPsConectado] = BLACK;
                num_cycles++;
                if(jt->idPoPsConectado == it->first){
                    break;
                }
            }
        }
    }

    return num_cycles;
}
*/

void Graph::dfs_cycle(int vertex, int parent, int colors[], int parents[], int& num_cycles) {
    
    if (colors[vertex] == BLACK) {
        return;
    }
    if (colors[vertex] == GRAY) {
        num_cycles++;
        return;
    }

    parents[vertex] = parent;
    colors[vertex] = GRAY;

    list<Edge>::iterator it;
    Vertex current = this->graph_map.find(vertex)->second;
    for(it = current.lista_adj.begin(); it != current.lista_adj.end(); it++) {

        if (it->idPoPsConectado == parents[vertex]) {
            continue;
        }
        dfs_cycle(it->idPoPsConectado, vertex, colors, parents, num_cycles);
    }

    colors[vertex] == BLACK;
}

int Graph::dfs() {

    int cores[this->num_vert];
    int parents[this->num_vert];
    map<int, Vertex>::iterator it;
    for(it = graph_map.begin(); it != graph_map.end(); it++) {
        cores[it->first] = WHITE;
    }

    int num_cycle = 0;
    dfs_cycle(1, -1, cores, parents, num_cycle);

    return num_cycle;
    
}
