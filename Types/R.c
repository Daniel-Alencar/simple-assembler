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
    int i;
    char *partsOfInstruction[4], temporary[17];

    removeTokens(instruction);
    separateTokens(instruction, partsOfInstruction);

    strcpy(result, "000000");

    for(i = 0; strcmp(partsOfInstruction[2], registers[i]); i++);
    strcpy(temporary, convertDecimalToBinary(i, 5));
    strcat(result, temporary);

    for(i = 0; strcmp(partsOfInstruction[3], registers[i]); i++);
    strcpy(temporary, convertDecimalToBinary(i, 5));
    strcat(result, temporary);

    for(i = 0; strcmp(partsOfInstruction[1], registers[i]); i++);
    strcpy(temporary, convertDecimalToBinary(i, 5));
    strcat(result, temporary);

    strcat(result, "00000");

    strcat(result, function);
    printf("%s\n", result);
}