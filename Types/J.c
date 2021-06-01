#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Libs/useful lib/useful.c"

int main() {
  char instruction[] = "j for";

  int i, j;
  int row = 3;

  char **partsOfIntruction[2];
  char **labels;
  int *labelsPositions;

  char *opcode = (char *) malloc(sizeof(char) * 6);
  char *instructionInBinary[33];

  int linhaDoLabelNoArquivo;
  char *binaryString = (char *) malloc(sizeof(char) * 27);

  // Preparativos

  labels = (char **) malloc(sizeof(char *) * 2);
  for(i = 0; i < 2; i++) {
    labels[i] = (char *) malloc(sizeof(char) * 10);
  }
  strcpy(labels[0], "for");

  labelsPositions = (int *) malloc(sizeof(int) * 10);
  labelsPositions[0] = 5;



  partsOfIntruction[0] = (char *) malloc(sizeof(char) * 7);
  partsOfIntruction[1] = (char *) malloc(sizeof(char) * 27);

  // Identificar o tipo da instrução e o opcode na leitura do arquivo.txt

  strcpy(opcode, "000010");

  strcpy(partsOfIntruction[0], opcode);

  // Leitura e procura do 'for' no labels, identificar a posição e procurar valor correspondente em linhaDosLabels

  for(i = 0; strcmp(labels[i], "for") != 0; i++);
  linhaDoLabelNoArquivo = labelsPositions[i];

  // Manipular o valor da linhaDosLabels para formar o target address

  binaryString = convertDecimalToBinary(linhaDoLabelNoArquivo);
  printf("%s\n", binaryString);
  // reverseString(binaryString);
  // int length = lengthOfString(binaryString);
  // int amount = 26 - length;
  // fillWithZeros(binaryString, length, amount);
  // reverseString(binaryString);
  // strcpy(partsOfIntruction[1], binaryString);

  // Concatenar valores
  
  // strcpy(instructionInBinary, partsOfIntruction[0]);
  // strcat(instructionInBinary, partsOfIntruction[1]);

  // printf("%s\n", instructionInBinary);
}
