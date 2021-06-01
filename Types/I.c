#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Libs/useful lib/useful.c"
#include "../Libs/useful lib/registers.h"

char **labels;
int *labelsPositions;

void instructionI(char *instruction, char *opcode);

int main(){
  /*
    int i;
    char instruction[] = "addi $s0 $s1 12";

    labels = (char **) malloc(sizeof(char *) * 2);
    for(i = 0; i < 2; i++) {
      labels[i] = (char *) malloc(sizeof(char) * 10);
    }
    labelsPositions = (int *) malloc(sizeof(int) * 10);

    strcpy(labels[0], "for");
    labelsPositions[0] = 5;
    
    instructionJ(instruction, "000010");
  */
    char instruction[] = "addi $s0, $s1, 12";
    char *aux = NULL;

    aux = strpbrk(instruction, "()");
    
    if(aux) {
      switchPosition(char *);
    }
}

void instructionI(char *instruction, char *opcode){

}