#ifndef __REGISTER_H__
#define __REGISTER_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//macros sobre o arquivo de dados
#define LEN_DISC_PAG 960
#define LEN_REG 64
#define DELIMITER '|'
#define GARBAGE '$'
#define SORTER ','

//macros sobre os campos
#define REMOVIDO_TAM 1
#define ENCADEAMENTO_TAM 4
#define IDCONECTA_TAM 4
#define SIGLAPAIS_TAM 2
#define IDPOPSCONECTADO 4
#define UNIDADEMEDIDA_TAM 1
#define VELOCIDADE_TAM 4
#define NOMEPOPS_TAM 50
#define NOMEPAIS_TAM 50

//define a estrutura do cabecalho
typedef struct{
    char status;
    int topo;
    int proxRRN;
    int nroRegRem;
    int nroPagDisco;
    int qttCompacta;
} Header_reg;

//define a estrutura do reg de dados
typedef struct{
    //campos de controle
    char removido;
    int encadeamento;

    //campos de tamanho fixo
    int idConecta;
    char siglaPais[SIGLAPAIS_TAM+1];
    int idPoPsConectado;
    char unidadeMedida;
    int velocidade;

    //campos de tamanho variavel
    char nomePoPs[NOMEPAIS_TAM];
    char nomePais[NOMEPAIS_TAM];
} Data_reg;

//criação e liberação do header
Header_reg* create_header();
void release_header(Header_reg* header);

//criação e liberação do registro
Data_reg* create_reg();
void release_reg(Data_reg* reg);

//leitura e escrita do header
void read_header(Header_reg* header, FILE* file);
void write_header(FILE* file, Header_reg* header);

//leitura e escrita do registro
int read_register(FILE* file, Data_reg* reg);
void write_register(FILE* file_write, Data_reg* registro);
void printar_registros(Data_reg *registro);

//mensagem de erro para erro ao tentar abrir um arquivo
void error_file();

//mensagem de erro para erro p/ registro inexistente
void error_reg();

#endif