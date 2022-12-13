#include <iostream>
#include "commands.hpp"

using namespace std;

int main(void) {
    //variaveis p/ entrada do teclado
    int command;
    char file_name[30];

    //le do teclado qual o comando sera acionado
    cin >> command;

    //aciona a execucao do comando lido
    switch (command){
        case 11:
            cin >> file_name;
            command11(file_name).print_graph();

            break;

        case 12:
            cin >> file_name;
            command12(file_name);
            break;

        case 13:
            //cin >> file_name;
            //command13(file_name);
            break;
            
        case 14:
            cin >> file_name;
            command14(file_name);
            break;
    }
}
