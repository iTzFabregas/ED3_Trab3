#include "classes.hpp"

using namespace std;

bool no_lista_compare (const no_lista a,const no_lista b)
{
    return a.idPoPsConectado < b.idPoPsConectado;
}


void Graph::insert_edge(Vertex vertex1, no_lista aresta1) { //paramentro idConecta

    map<int, Vertex>::iterator it;
    it = this->graph.find(vertex1.idConecta);
    if (it != this->graph.end()) {
        vertex1.lista_adj = it->second.lista_adj;
    }
    if (aresta1.velocidade >= 0 ) {
        vertex1.lista_adj.push_front(aresta1);
        vertex1.lista_adj.sort(no_lista_compare);
    }

    if (it == this->graph.end()) {
        graph.insert(make_pair(vertex1.idConecta, vertex1));

    } else {
        it->second = vertex1;
    }

    if (aresta1.velocidade >= 0) {
        it = this->graph.find(aresta1.idPoPsConectado);
        Vertex vertex2;
        if (it != this->graph.end()) {
            vertex2 = it->second;
        } else {
            vertex2.idConecta = aresta1.idPoPsConectado;
        }
        no_lista aresta2;
        aresta2.idPoPsConectado = vertex1.idConecta;
        aresta2.velocidade = aresta1.velocidade;
        vertex2.lista_adj.push_front(aresta2);
        vertex2.lista_adj.sort(no_lista_compare);
        

        if (it == this->graph.end()) {
            graph.insert(make_pair(vertex2.idConecta, vertex2));
            
        } else {
            it->second.lista_adj = vertex2.lista_adj;
        }
    }
    this->num_vert = this->graph.size();
}

void Graph::print_graph() {

    map<int, Vertex>::iterator it;
    list<no_lista>::iterator jt;

    for(it=graph.begin(); it!=graph.end(); ++it){
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
        it = this->graph.find(current.first);
        Vertex current_vertex = it->second;

        queue.pop();

        if (visited[current_vertex.idConecta] == false) {
            visited[current_vertex.idConecta] == true;

            list<no_lista>::iterator jt;

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

/*
struct no_lista{
    int idPoPsConectado;
    int velocidade;
};

struct Vertex{
    int idConecta;
    string nomePoPs;
    string nomePais;
    string siglaPais;

    list<no_lista> lista_adj;
}; 

class Graph {
private:
    map<int, Vertex> graph;
    map<int, Vertex>::iterator it;

public:
    Graph() {
        // O MAP JA ESTA VAZIO
    }

    bool insert_edge(Vertex vertex1, no_lista vertex2) { //paramentro idConecta

        it = this->graph.find(vertex1.idConecta);
        if (it == this->graph.end()) {
            // TO-DO adicionar um vertice no map
            graph[vertex1.idConecta] = vertex1;
            // TO-DO colocar o vertice na lista de adjacencia
            vertex1.lista_adj.push_front(vertex2); // PROBLEMA SE ATUALZIA O VERTICE DEPOS
        } else { 
            // TO-DO colocar o vertice na lista de adjacencia
            vertex1.lista_adj.push_front(vertex2);
        }
    }

    bool exist_edge() {

    }

    void print_graph() {

    }

    ~Graph() {
        
    }
};
*/


/*
class Lista_adj {
private:
    

public:

    Lista_adj() {

    }
    Lista_adj() {

    }
};


class Vertex {
 private:
    int idConecta;  
    char nomePoPs[42];
    char nomePais[42];
    char siglaPais[3];

    Lista_adj lista;
    
 public:
    Vertex() {

    }

    ~Vertex() {

    }
};
*/

