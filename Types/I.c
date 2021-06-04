#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Libs/useful lib/useful.c"
#include "../Libs/useful lib/global.c"
#include "../Libs/clean lib/switchposition.c"
#include "../Libs/clean lib/removetokens.c"
#include "../Libs/clean lib/separatetokens.c"

void instructionI(char *instruction, char *opcode, char *result, int lineNumber);

int main(){
    char instruction[] = "addi $s0, $s1, 42", result[33];
    instructionI(instruction, "001000", result, 1);
}

void instructionI(char *instruction, char *opcode, char *result, int lineNumber){
    int i, isLabel;
    char *partsOfInstruction[4], temporary[16];
    char *aux = strpbrk(instruction, "()");

    if(aux){
      switchPosition(instruction);
    }

    removeTokens(instruction);
    separateTokens(instruction, partsOfInstruction);

    strcpy(result, opcode);

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