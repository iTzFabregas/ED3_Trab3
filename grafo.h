
typedef struct No{
    int idPoPsConectado;
    int velocidade;
    struct No* prox;
    struct No* ant;
} No_Lista;

typedef No_Lista* Lista;

typedef struct{
    int idConecta;
    char nomePoPs[42];
    char nomePais[42];
    char siglaPais[3]; 

    Lista* lista_adj;
} Grafo;

Lista* criar_lista();
void liberar_lista(Lista* lista);
void inserir_ordenado(Lista* lista, int );

Grafo* criar_grafo();
