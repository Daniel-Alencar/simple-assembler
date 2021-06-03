#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Libs/useful lib/useful.c"
#include "../Libs/useful lib/global.c"

void instructionJ(char *instruction, char *opcode, char *result);

int main() {
  char instruction[] = "j for";
  char result[33];

  instructionJ(instruction, "100100", result);
  printf("%s\n", result);
}

void instructionJ(char *instruction, char *opcode, char *result){
  int i;
  char targetAddress[27];
  char label[51];

  char *binaryString = (char *) malloc(sizeof(char) * 27);
  
  // Leitura e procura do 'for' no labels, identificar a posição e procurar valor correspondente em linhaDosLabels
  sscanf(instruction, "%*s %s", label);

  for(i = 0; i < 32; i++){
    if(!strcmp(labels[i], label)){
      break;
    }
  }

  // Manipular o valor da linhaDosLabels para formar o target address

  binaryString = convertDecimalToBinary(labelsPositions[i]);
  
  strcpy(result, opcode);
  sprintf(targetAddress, "%026d", atoi(binaryString));
  strcat(result, targetAddress);
}