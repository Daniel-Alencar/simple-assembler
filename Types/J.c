#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Libs/useful lib/useful.c"

char **labels;
int *labelsPositions;

void instructionJ(char *instruction, char *opcode, char *result);

int main() {
  int i;
  char instruction[] = "j for";
  char result[33];

  labels = (char **) malloc(sizeof(char *) * 2);
  for(i = 0; i < 2; i++) {
    labels[i] = (char *) malloc(sizeof(char) * 10);
  }
  labelsPositions = (int *) malloc(sizeof(int) * 10);

  strcpy(labels[0], "for");
  labelsPositions[0] = 5;

  instructionJ(instruction, "100100", result);
  printf("%s\n", result);
}

void instructionJ(char *instruction, char *opcode, char *result){
  int i;
  char targetAddress[27];
  char label[10];

  char *binaryString = (char *) malloc(sizeof(char) * 27);
  
  // Leitura e procura do 'for' no labels, identificar a posição e procurar valor correspondente em linhaDosLabels
  sscanf(instruction, "%*s %s", label);

  for(i = 0; strcmp(labels[i], label); i++);

  // Manipular o valor da linhaDosLabels para formar o target address

  binaryString = convertDecimalToBinary(labelsPositions[i]);
  
  strcpy(result, opcode);
  sprintf(targetAddress, "%026s", binaryString);
  strcat(result, targetAddress);
}