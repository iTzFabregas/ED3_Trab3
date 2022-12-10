#ifndef __CLASSES_HPP__
#define __CLASSES_HPP__

#include <list>
#include <iostream>
#include <list>
#include <map>

using namespace std;

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
    map<int, Vertex>::iterator it;

public:

    map<int, Vertex> graph;

    Graph() {
        // O MAP JA ESTA VAZIO
    }

    void insert_edge(Vertex, no_lista); //paramentro idConecta

    /*bool exist_edge() {
        return true;
    }

    void print_graph() {
    }

    ~Graph() {
        
    }*/
};

#endif