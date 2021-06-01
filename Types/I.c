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
    char instruction[] = "addi $v0, 12($at)", result[33];
    instructionI(instruction, "100100", result);
}

void instructionI(char *instruction, char *opcode, char *result){
    int i;
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
  
    sprintf(temporary, "%016s", convertDecimalToBinary(atoi(partsOfInstruction[3])));
    strcat(result, temporary);

    printf("%s\n", result);
}