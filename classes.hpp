#ifndef __CLASSES_HPP__
#define __CLASSES_HPP__

#include <list>
#include <iostream>
#include <map>
#include <queue>

#define INFINITE INT32_MAX-1

using namespace std;

typedef struct {
    int idPoPsConectado;
    int velocidade;
} no_lista;

typedef struct {
    int idConecta; // TIRAR ESSE INT
    string nomePoPs;
    string nomePais;
    string siglaPais;

    list<no_lista> lista_adj;
} Vertex; 

class Graph {
private:
    int num_vert;

public:
    map<int, Vertex> graph;

    Graph() {
        this->num_vert = 0;
    }

    void insert_edge(Vertex, no_lista); //paramentro idConecta

    /*bool exist_edge() {
        return true;
    }
    */


    void print_graph();

    int dijkstra(int orig, int dest);
    
    /*
    ~Graph() {
        
    }*/
};

#endif