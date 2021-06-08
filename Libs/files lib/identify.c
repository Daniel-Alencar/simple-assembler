#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void identifyInstruction(char **instructions, int amount){
    int line;
    char *aux, string[101], part[101], opcodeOrFunction[10];
    FILE *funcoes;

    funcoes = fopen("../../Importante/funcoes.txt", "r+");

    for(int i = 0; i < amount; i++){
        line = 0;

        strcpy(part, strtok(instructions[i], " ,"));
        strcat(part, ":");

        while(!feof(funcoes)){
            fgets(string, 101, funcoes);

            while(aux = strchr(string, '\n')){
                aux[0] = '\0';
            }

            line++;
            if(aux = strstr(string, part)){
                strncpy(opcodeOrFunction, strchr(string, ':') + 1, 6);
                printf("%s\t%d\t%s\n", part, line, opcodeOrFunction);
                break;
            }
        }
        rewind(funcoes);
    }
}