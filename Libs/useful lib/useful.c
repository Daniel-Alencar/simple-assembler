#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "./useful.h"

// int main() {
//   int number = -42;
//   char *str = convertDecimalToBinary(number);
//   printf("%s\n", str);
// }

char *convertDecimalToBinary(int decimal) {
  int i, restoDaDivisaoInt, originalDecimal = decimal;
  char restoDaDivisaoChar;
  char *binaryNumber = (char *) malloc(sizeof(char) * 17);

  if(decimal < 0) {
    decimal *= -1;
  }

  for(i = 0; decimal >= 1; i++) {
    restoDaDivisaoInt = decimal % 2;
    decimal = decimal / 2;

    restoDaDivisaoChar = convertIntegerToCaracter(restoDaDivisaoInt);
    binaryNumber[i] = restoDaDivisaoChar;
  }
  binaryNumber[i] = '\0';
  reverseString(binaryNumber);



  if(originalDecimal < 0) {
    complementOfTwo(binaryNumber);
  }

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

void complementOfOne(char *binaryNumber) {
  int i;
  for(i = 0; i < strlen(binaryNumber); i++){
    binaryNumber[i] = convertIntegerToCaracter((binaryNumber[i] - '0') ^ 1);
  }
}

void complementOfTwo(char binaryNumber[]) {
  int i, length;
  sprintf(binaryNumber, "%016d", atoi(binaryNumber));

  printf("%s\n", binaryNumber);

  length = lengthOfString(binaryNumber);

  for(i = (length - 1); binaryNumber[i] == '0'; i--);
  
  for(i--; i >= 0; i--) {
    if(binaryNumber[i] == '0') {
      *(binaryNumber + i) = '1';
    } else {
      *(binaryNumber + i) = '0';
    }
  }
}

char *fillWithZeros(char *string, int length, int amount) {
  int total = (length + amount);
  char *stringWithZeros = (char *) malloc(sizeof(char) * (total + 1));
  int i;
  char aux;

  strcpy(stringWithZeros, string);
  for(i = length; i < total ; i++) {
    stringWithZeros[i] = '0';
    stringWithZeros[i + 1] = '\0';
  }
  return stringWithZeros;
}
