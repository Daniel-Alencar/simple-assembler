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
    char instruction[] = "sw $s0, 33($s1)", result[33];
    instructionI(instruction, "101011", result, 1);
}

void instructionI(char *instruction, char *opcode, char *result, int lineNumber){
    int i, j, k, isLabel;
    char *partsOfInstruction[4], temporary[16];
    char *aux = strpbrk(instruction, "()");

    if(aux){
      switchPosition(instruction);
    }

    removeTokens(instruction);
    separateTokens(instruction, partsOfInstruction);

    strcpy(result, opcode);

    for(i = 0; strcmp(partsOfInstruction[1], registers[i]); i++);
    for(j = 0; strcmp(partsOfInstruction[2], registers[j]); j++);

    for(k = 0, isLabel = 0; k < 32; k++){
      if(!strcmp(labels[k], partsOfInstruction[3])){
        isLabel = 1;
        break;
      }
    }

    if(isLabel){
      if(!aux){
        strcpy(temporary, convertDecimalToBinary(i, 5));
        strcat(result, temporary);

        strcpy(temporary, convertDecimalToBinary(j, 5));
        strcat(result, temporary);
      } else {
        strcpy(temporary, convertDecimalToBinary(j, 5));
        strcat(result, temporary);

        strcpy(temporary, convertDecimalToBinary(i, 5));
        strcat(result, temporary);

      }
      strcpy(temporary, convertDecimalToBinary(labelsPositions[k] - (lineNumber + 1), 16));
    } else {
      strcpy(temporary, convertDecimalToBinary(j, 5));
      strcat(result, temporary);

      strcpy(temporary, convertDecimalToBinary(i, 5));
      strcat(result, temporary);

      strcpy(temporary, convertDecimalToBinary(atoi(partsOfInstruction[3]), 16));
    }

    strcat(result, temporary);
    printf("%s\n", result);
}