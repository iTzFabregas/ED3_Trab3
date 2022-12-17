#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include <iostream>
#include <map>
#include <queue>
#include <list>
#include <stack>

#define INFINITE INT32_MAX-1

// MACROS QUE DEFINEM AS CORES USADAS NA BUSCA EM PROFUNDIDADE
#define WHITE 0
#define GRAY 1
#define BLACK 2

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
     * @brief Método que verifica se o grafo está vazio
     * 
     * @return true caso esteja vazio
     * @return false caso contrário
     */
    bool is_empty();

    /**
     * @brief Printa todas as arestas do grafo em ordem crescente
     * 
     */
    void print_graph();

    /**
     * @brief Método de percorrer o grafo que encontra o menor caminho que leva de um vertice
     * para outro
     * 
     * @param orig vertice de origem
     * @param dest vertice de destino
     * @return int distancia entre esses vertices
     */
    int dijkstra(int orig, int dest);

    /**
     * @brief Chamada recursiva do método de busca em profundidade, percorre a lista adjacente 
     * de um vértice passado
     * 
     * @param vertex     idConecta do vértice que se queira fazer a busca
     * @param parent     valor do vértice pai do vertex
     * @param colors     array que guarda a cor de determinado vértice
     * @param parents    array que guarda os valores dos vértices pais
     * @param num_cycles número de ciclos do grafo
     */
    void dfs_cycle(int vertex, int parent, int colors[], int parents[], int& num_cycles);
    
    /**
     * @brief Método que, a partir de uma busca em profundidade, calcula o
     * numero de ciclos do grafo
     * 
     * @return int numero de ciclos do grafo. Caso o grafo seja acíclico, retorna 0
     */
    int dfs();

    /**
     * @brief Método recursivo de DFS adaptado para calcular o fluxo máximo
     * entre dois vértices
     * 
     * @param orig      vertice de inicio do fluxo
     * @param parent    pai do vertice de origem
     * @param dest      vertice do final do fluxo
     * @param colors    array que guarda a cor de determinado vertice
     * @param parents   array que guarda os valores dos vertices pais
     * @param found     indicar se encontrou o destino ou nao
     * @param max_flow  valor do fluxo maximo
     * @return true     valor de retorno p/ processo recursivo
     */
    int dfs_flow(int orig, int parent, int dest, int colors[], int parents[], int& found, int& max_flow);

    /**
     * @brief Método que calcula o fluxo máximo entre dois vértices
     * considerando todos os caminhos possíveis
     * 
     * @param orig vertice de origem do fluxo
     * @param dest vertice do fim do fluxo
     * @return int retorna o valor do fluxo maximo 
     * considerando todos os caminhos possiveis 
     */
    int total_flow(int orig, int dest);

};

#endif