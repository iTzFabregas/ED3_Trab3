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
} Edge;

typedef struct {
    int idConecta;
    string nomePoPs;
    string nomePais;
    string siglaPais;

    list<Edge> lista_adj;
} Vertex; 

class Graph {
private:
    int num_vert;
    map<int, Vertex> graph_map;

public:

    Graph() {
        this->num_vert = 0;
    }

    void insert_edge(Vertex, Edge);

    /*bool exist_edge() {
        return true;
    }
    */

    void print_graph();

    int dijkstra(int orig, int dest);
};

#endif