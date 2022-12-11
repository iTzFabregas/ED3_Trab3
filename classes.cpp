#include "classes.hpp"

using namespace std;

bool Edge_compare (const Edge a,const Edge b)
{
    return a.idPoPsConectado < b.idPoPsConectado;
}


void Graph::insert_edge(Vertex vertex1, Edge aresta1) { //paramentro idConecta

    map<int, Vertex>::iterator it;
    it = this->graph_map.find(vertex1.idConecta);
    if (it != this->graph_map.end()) {
        vertex1.lista_adj = it->second.lista_adj;
    }
    if (aresta1.velocidade >= 0 ) {
        vertex1.lista_adj.push_front(aresta1);
        vertex1.lista_adj.sort(Edge_compare);
    }

    if (it == this->graph_map.end()) {
        graph_map.insert(make_pair(vertex1.idConecta, vertex1));

    } else {
        it->second = vertex1;
    }

    if (aresta1.velocidade >= 0) {
        it = this->graph_map.find(aresta1.idPoPsConectado);
        Vertex vertex2;
        if (it != this->graph_map.end()) {
            vertex2 = it->second;
        } else {
            vertex2.idConecta = aresta1.idPoPsConectado;
        }
        Edge aresta2;
        aresta2.idPoPsConectado = vertex1.idConecta;
        aresta2.velocidade = aresta1.velocidade;
        vertex2.lista_adj.push_front(aresta2);
        vertex2.lista_adj.sort(Edge_compare);
        

        if (it == this->graph_map.end()) {
            graph_map.insert(make_pair(vertex2.idConecta, vertex2));
            
        } else {
            it->second.lista_adj = vertex2.lista_adj;
        }
    }
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


    queue.push(make_pair(orig, distance[orig]));

    map<int, Vertex>::iterator it;
    while(!queue.empty()) {

        pair<int, int> current = queue.top();
        it = this->graph_map.find(current.first);
        Vertex current_vertex = it->second;

        queue.pop();

        if (visited[current_vertex.idConecta] == false) {
            visited[current_vertex.idConecta] == true;

            list<Edge>::iterator jt;

            for(jt = current_vertex.lista_adj.begin(); jt != current_vertex.lista_adj.end(); jt++) {
                int adj_vertex = jt->idPoPsConectado;
                int cost = jt->velocidade   ;

                // RELAXAMENTO DA ARESTA
                if (distance[adj_vertex] > (distance[current_vertex.idConecta] + cost) || distance[adj_vertex] == INFINITE) {///x
                    // ATUALIZA O NOVO VALOR DA DISTANCIA
                    distance[adj_vertex] = distance[current_vertex.idConecta] + cost;
                    queue.push(make_pair(adj_vertex, distance[adj_vertex]));
                }
            }
        }
    }
    if (distance[dest] != INFINITE) {
        return distance[dest];
    } else {
        return -1;
    }
}

