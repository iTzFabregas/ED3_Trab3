class Lista_adj {
private:
    int idPoPsConectado;
    int velocidade;
    
    Lista_adj prox;
    Lista_adj ant;

public:

    Lista_adj(/* args */) {

    }
    Lista_adj() {

    }
};


class Vertice {
 private:
    int idConecta;
    char nomePoPs[42];
    char nomePais[42];
    char siglaPais[3];

    Lista_adj lista;

 public:
    Vertice(/* args */) {

    }

    ~Vertice() {

    }
};
 