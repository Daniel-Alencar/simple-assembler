#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void identifyInstruction(char **instructions){
    for(int i = 0; i < 75; i++){
        printf(":%s:\n", instructions[i]);
    }
}