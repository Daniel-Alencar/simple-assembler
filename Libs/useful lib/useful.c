#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "./useful.h"

char *convertDecimalToBinary(int decimal) {
  int i, restoDaDivisaoInt;
  char restoDaDivisaoChar;
  char *binaryNumber = (char *) malloc(sizeof(char) * 10);

  for(i = 0; decimal >= 1; i++) {
    restoDaDivisaoInt = decimal % 2;
    decimal = decimal / 2;

    restoDaDivisaoChar = convertIntegerToCaracter(restoDaDivisaoInt);
    binaryNumber[i] = restoDaDivisaoChar;
  }
  binaryNumber[i] = '\0';
  reverseString(binaryNumber);
  
  return binaryNumber;
}

char convertIntegerToCaracter(int number) {
  char aux = number + '0';
  return aux;
}

void reverseString(char *string) {
  int i, length;
  char aux;

  length = lengthOfString(string);
  
  for(i = 0; i < (length / 2); i++) {
    aux = string[i];
    string[i] = string[(length - i - 1)];
    string[(length - i - 1)] = aux;
  }
}

int lengthOfString(char *string) {
  int length;
  for(length = 0; string[length] != '\0' ; length++);

  return length;
}
