#include "classes.hpp"

using namespace std;

void Graph::insert_edge(Vertex vertex1, no_lista aresta1) { //paramentro idConecta

    map<int, Vertex>::iterator it;
    it = this->graph.find(vertex1.idConecta);
    if (it != this->graph.end()) {
        vertex1.lista_adj = it->second.lista_adj;
    }
    if (aresta1.velocidade != -1) {
        vertex1.lista_adj.push_front(aresta1);
    }

    if (it == this->graph.end()) {
        graph.insert(make_pair(vertex1.idConecta, vertex1));

    } else {
        it->second = vertex1;
    }

    if (aresta1.velocidade != -1) {
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
        

        if (it == this->graph.end()) {
            graph.insert(make_pair(vertex2.idConecta, vertex2));
            
        } else {
            it->second.lista_adj = vertex2.lista_adj;
        }
    }
}

/*
struct no_lista{
    int idPoPsConectado;
    int velocidade;
};

struct Vertex{
    int idConecta; // TIRAR ESSE INT
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

