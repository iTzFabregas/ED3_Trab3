#ifndef __CLASSES_HPP__
#define __CLASSES_HPP__

#include <list>
#include <iostream>
#include <map>
#include <queue>

#define INFINITE INT32_MAX-1

using namespace std;

/**
 * @brief Stryct da aresta, dada pelo destinatpario da ligação e o seu peso (velociade)
 * 
 */
typedef struct {
    int idPoPsConectado;
    int velocidade;
} Edge;


/**
 * @brief Struct do vertice que tem as informações de cada ponto e a sua lista de adjacencia
 * 
 */
typedef struct {
    int idConecta;
    string nomePoPs;
    string nomePais;
    string siglaPais;

    list<Edge> lista_adj;
} Vertex; 


/**
 * @brief Classe do grafo, com as funções necessárias do grafo e o map dos vértices
 * 
 */
class Graph {
private:
    int num_vert;
    map<int, Vertex> graph_map;

public:

    /**
     * @brief Construtor do grafo que apenas seta o numero de vértices para 0
     * 
     */
    Graph() {
        this->num_vert = 0;
    }

    /**
     * @brief 
     * 
     * @param vertex1 
     * @param aresta1 
     */
    void insert_edge(Vertex, Edge);

    /**
     * @brief 
     * 
     */
    void print_graph();

    /**
     * @brief 
     * 
     * @param orig 
     * @param dest 
     * @return int 
     */
    int dijkstra(int orig, int dest);
};

#endif