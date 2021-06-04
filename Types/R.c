#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Libs/useful lib/useful.c"
#include "../Libs/useful lib/global.c"
#include "../Libs/clean lib/switchposition.c"
#include "../Libs/clean lib/removetokens.c"
#include "../Libs/clean lib/separatetokens.c"

void instructionR(char *instruction, char *function, char *result, int lineNumber);

int main(){
    int rowOnFile = 1;
    char instruction[] = "add $s0, $s1, $s2", result[33];
    instructionR(instruction, "100000", result, rowOnFile);
}

void instructionR(char *instruction, char *function, char *result, int lineNumber){
    int i, isLabel;
    char *partsOfInstruction[4], temporary[16];
    char *aux = strpbrk(instruction, "()");

    if(aux){
      switchPosition(instruction);
    }

    removeTokens(instruction);
    separateTokens(instruction, partsOfInstruction);

    strcpy(result, function);

    for(i = 0; strcmp(partsOfInstruction[1], registers[i]); i++);
    strcpy(temporary, convertDecimalToBinary(i, 5));
    strcat(result, temporary);

    for(i = 0; strcmp(partsOfInstruction[2], registers[i]); i++);
    strcpy(temporary, convertDecimalToBinary(i, 5));
    strcat(result, temporary);

    for(i = 0, isLabel = 0; i < 32; i++){
      if(!strcmp(labels[i], partsOfInstruction[3])){
        isLabel = 1;
        break;
      }
    }

    if(isLabel) {
      strcpy(temporary, convertDecimalToBinary(labelsPositions[i] - (lineNumber + 1), 16));
    } else {
      strcpy(temporary, convertDecimalToBinary(atoi(partsOfInstruction[3]), 16));
    }

    strcat(result, temporary);
    printf("%s\n", result);
}