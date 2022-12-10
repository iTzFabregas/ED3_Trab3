#include "classes.hpp"

using namespace std;

void Graph::insert_edge(Vertex vertex1, no_lista vertex2) { //paramentro idConecta

    it = this->graph.find(vertex1.idConecta);
    vertex1.lista_adj.push_front(vertex2);
    if (it == this->graph.end()) {
        // TO-DO adicionar um vertice no map
        //graph[vertex1.idConecta] = vertex1;
        graph.insert(make_pair(vertex1.idConecta, vertex1));
        // TO-DO colocar o vertice na lista de adjacencia
        //vertex1.lista_adj.push_front(vertex2); // PROBLEMA SE ATUALZIA O VERTICE DEPOS
    } else { 
        // TO-DO colocar o vertice na lista de adjacencia
        //vertex1.lista_adj.push_front(vertex2);
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

