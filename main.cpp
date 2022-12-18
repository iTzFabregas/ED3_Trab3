/*
Fabricio Sampaio [runcodes] - 12547423 - participacao: 100%
Pedro Lucas Castro de Andrade - 11212289 - participacao: 100%
*/

#include <iostream>
#include "commands.hpp"

using namespace std;

int main(void) {
    //variaveis p/ entrada do teclado
    int command;
    char file_name[30];

    //le do teclado qual o comando sera acionado
    cin >> command;
    cin >> file_name;

    //aciona a execucao do comando lido
    switch (command){
        case 11:
            command11(file_name).print_graph();
            break;

        case 12:
            command12(file_name);
            break;

        case 13:
            command13(file_name);
            break;
            
        case 14:
            command14(file_name);
            break;
    }
}
