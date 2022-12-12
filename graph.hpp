#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include <list>
#include <iostream>
#include <map>
#include <queue>

#define INFINITE INT32_MAX-1

using namespace std;

// STRUCT RELATIVA AS ARESTAS
typedef struct {
    int idPoPsConectado;
    int velocidade;
} Edge;

// STRUCT RELATIVA A CADA VÉRTICE
typedef struct {
    int idConecta;
    string nomePoPs;
    string nomePais;
    string siglaPais;

    list<Edge> lista_adj;
} Vertex; 


// CLASSE RELATIVA AO GRAFO COM O MAP DOS VERTICES E AS SUAS FUNÇÕES
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
     * @brief Função que insere uma vértice no map se necessário e atualiza a lista de
     * adjacencia dos mesmo para a nova aresta criada
     * 
     * @param vertex1 Informações do vértice obtidas na leitura do arquivo
     * @param aresta1 Informações da ligação obtida no arquivo
     */
    void insert_edge(Vertex, Edge);

    /**
     * @brief Printa todas as arestas do grafo em ordem crescente
     * 
     */
    void print_graph();

    /**
     * @brief Métode de percorrer o grafo que encontra o menor caminho que leva de um vertice
     * para outro
     * 
     * @param orig vertice de origem
     * @param dest vertice de destino
     * @return int distancia entre esses vertices
     */
    int dijkstra(int orig, int dest);
};

#endif