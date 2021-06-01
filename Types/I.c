#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Libs/useful lib/useful.c"
#include "../Libs/useful lib/registers.h"
#include "../Libs/clean lib/switchposition.c"
#include "../Libs/clean lib/removetokens.c"
#include "../Libs/clean lib/separatetokens.c"

char **labels;
int *labelsPositions;

void instructionI(char *instruction, char *opcode);

int main(){
    //char instruction[] = "addi $s0, $s1, 12";
    char instruction[] = "addi $s0, -100($s1)";
    char *partsOfInstruction[4];
    char *aux = strpbrk(instruction, "()");

    if(aux){
      switchPosition(instruction);
    }
    removeTokens(instruction);
    separateTokens(instruction, partsOfInstruction);

    printf("[");
    for(int i = 0; i < 4; i++){
      printf("%s, ", partsOfInstruction[i]);
    }
    printf("\b\b]");
}

void instructionI(char *instruction, char *opcode){

}