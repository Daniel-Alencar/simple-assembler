#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "../Libs/useful lib/useful.h"

int main() {
  char intruction[] = "j for";

  char *guardarResultado[2];
  char **arrayAuxiliarParaLabels;
  int *indexOfLabels;
  char opcode[6];
  int i, j;
  char *str = (char *) malloc(sizeof(char) * 10);
  char *instruction[40];

  // Preparativos
  arrayAuxiliarParaLabels = (char **) malloc(sizeof(char *) * 2);
  for(i = 0; i < 2; i++) {
    arrayAuxiliarParaLabels[i] = (char *) malloc(sizeof(char) * 10);
  }
  strcpy(arrayAuxiliarParaLabels[0], "for");

  indexOfLabels = (int *) malloc(sizeof(int) * 10);
  indexOfLabels[0] = 5;
  int linhaDoLabelNoArquivo = 0;

  // Identificar a o tipo da instrução e o opcode
  char aux;
  FILE *typesOfIntructions;
  int row = 1;
  typesOfIntructions = fopen("typesOfIntructions.txt", "r");
  for(aux = getc(typesOfIntructions); !feof(typesOfIntructions); ) {
    if(aux == '\n') {
      row++;
    }
  }

  row = 3;
  strcpy(opcode, "000010");
  guardarResultado[0] = (char *) malloc(sizeof(char) * 6);
  strcpy(guardarResultado[0], opcode);


  // Leitura e procura do 'for' no arrayAuxiliarParaLabels, identificar a posição e procurar valor correspondente em linhaDosLabels
  for(i = 0; strcmp(arrayAuxiliarParaLabels[i], "for"); i++);
  linhaDoLabelNoArquivo = indexOfLabels[i];

  // Manipular o valor da linhaDosLabels para formar o target address
  strcpy(str, convertDecimalToBinary(linhaDoLabelNoArquivo));
  reverseString(str);
  int length = lengthOfString(str);

  int amount = 26 - length;
  fillWithZeros(str, length, amount);
  reverseString(str);

  strcpy(guardarResultado[1], str);

  // Concatenar valores
  strcpy(instruction, guardarResultado[0]);
  strcat(instruction, guardarResultado[1]);

  printf("%s\n", instruction);
}
