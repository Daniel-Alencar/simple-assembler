#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void identifyInstruction(char **instructions, int amount){
    int line = 0;
    char *part, *aux, *locale;
    FILE *funcoes;

    funcoes = fopen("../../Importante/funcoes.txt", "r");

    printf("--%s--\n", fgets(aux, 101, funcoes));
    // if(!fgets(aux, 101, funcoes)){
    //     printf("%s-%d\n", aux, line);
    // }
    // for(int i = 0; i < amount; i++){
    //     part = strtok(instructions[i], " ,");

    //     do{
    //         if(!fgets(aux, 101, funcoes)){
    //             printf("%s-%d\n", aux, line);
    //             break;
    //         }

    //         // fgets(aux, 101, funcoes);
    //         // while(aux){
    //         //     line++;
                
    //         // }
    //     } while(!feof(funcoes));
    // }
}