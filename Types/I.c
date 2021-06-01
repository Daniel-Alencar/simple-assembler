#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Libs/useful lib/useful.c"
#include "../Libs/useful lib/registers.c"
#include "../Libs/clean lib/switchposition.c"
#include "../Libs/clean lib/removetokens.c"
#include "../Libs/clean lib/separatetokens.c"

char **labels;
int *labelsPositions;

void instructionI(char *instruction, char *opcode, char *result);

int main(){
    char instruction[] = "addi $s0, $s0, ", result[33];
    instructionI(instruction, "100100", result);
}

void instructionI(char *instruction, char *opcode, char *result){
    int i;
    char *partsOfInstruction[4];
    char *aux = strpbrk(instruction, "()");

    if(aux){
      switchPosition(instruction);
    }
    removeTokens(instruction);
    separateTokens(instruction, partsOfInstruction);

    strcpy(result, opcode);

    for(i = 0; strcmp(partsOfInstruction[2], registers[i]) ; i++);
    sprintf(aux, "%05s", convertDecimalToBinary(i));
    strcat(result, aux);

    for(i = 0; strcmp(partsOfInstruction[1], registers[i]) ; i++);
    sprintf(aux, "%05s", convertDecimalToBinary(i));
    strcat(result, aux);

    printf("%s\n", result);
}