#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void identifyInstruction(char **instructions){
    char *aux;

    for(int i = 0; i < 10; i++){
        aux = strtok(instructions[i], " ,");

        // while(aux = strchr(aux, '\n')){
        //     strcpy(aux, "\0");
        // }
        strcat(aux, ":");

        printf("%s\n", aux);
    }
}