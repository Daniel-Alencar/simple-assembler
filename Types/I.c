#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Libs/useful lib/useful.c"
#include "../Libs/useful lib/global.c"
#include "../Libs/clean lib/switchposition.c"
#include "../Libs/clean lib/removetokens.c"
#include "../Libs/clean lib/separatetokens.c"

void instructionI(char *instruction, char *opcode, char *result);

int main(){
    char instruction[] = "bne, $v0, $at, end", result[33];
    instructionI(instruction, "100100", result);
}

void instructionI(char *instruction, char *opcode, char *result){
    int i, isLabel;
    char *partsOfInstruction[4], temporary[5];
    char *aux = strpbrk(instruction, "()");

    if(aux){
      switchPosition(instruction);
    }

    removeTokens(instruction);
    separateTokens(instruction, partsOfInstruction);

    strcpy(result, opcode);

    for(i = 0; strcmp(partsOfInstruction[2], registers[i]); i++);
    sprintf(temporary, "%05s", convertDecimalToBinary(i));
    strcat(result, temporary);

    for(i = 0; strcmp(partsOfInstruction[1], registers[i]); i++);
    sprintf(temporary, "%05s", convertDecimalToBinary(i));
    strcat(result, temporary);

    for(i = 0, isLabel = 0; i < 32; i++){
      if(!strcmp(labels[i], partsOfInstruction[3])){
        isLabel = 1;
        break;
      }
    }
    isLabel ? sprintf(temporary, "%016s", convertDecimalToBinary(labelsPositions[i])) : sprintf(temporary, "%016s", convertDecimalToBinary(atoi(partsOfInstruction[3])));

    strcat(result, temporary);
    printf("%s\n", result);
}