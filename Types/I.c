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
    char instruction[] = "bne $s0, $s1, for", result[33];
    instructionI(instruction, "000101", result, 10);
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
    sprintf(temporary, "%05d", atoi(convertDecimalToBinary(i)));
    strcat(result, temporary);

    for(i = 0; strcmp(partsOfInstruction[2], registers[i]); i++);
    sprintf(temporary, "%05d", atoi(convertDecimalToBinary(i)));
    strcat(result, temporary);

    for(i = 0, isLabel = 0; i < 32; i++){
      if(!strcmp(labels[i], partsOfInstruction[3])){
        isLabel = 1;
        break;
      }
    }

    if(isLabel) {
      sprintf(temporary, "%016s", convertDecimalToBinary(labelsPositions[i] - (lineNumber + 1)));
    } else {
      sprintf(temporary, "%016s", convertDecimalToBinary(atoi(partsOfInstruction[3])));
    }

    for(i = 0; i < strlen(temporary); i++) {
      if(temporary[i] == ' ') {
        temporary[i] = '0';
      }
    }

    strcat(result, temporary);
    printf("%s\n", result);
}