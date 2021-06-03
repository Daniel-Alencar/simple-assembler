#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "./useful.h"

char *convertDecimalToBinary(int decimal) {
  int i, restoDaDivisaoInt, originalDecimal = decimal;
  char restoDaDivisaoChar;
  char *binaryNumber = (char *) malloc(sizeof(char) * 10);

  if(decimal < 0) {
    decimal = 0 - decimal;
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
  printf("%s\n", binaryNumber);

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

void complementOfTwo(char *binaryNumber) {  
  int n;  // variable declaration  
  printf("Enter the number of bits do you want to enter :");  
  scanf("%d",&n);  
  char onescomplement[n+1]; // onescomplement array declaration   
  char twoscomplement[n+1]; // twoscomplement array declaration  
  int carry=1; // variable initialization  
  printf("\nEnter the BinaryNumber number : ");  
  printf("%s", BinaryNumber);  
  printf("\nThe ones complement of the BinaryNumber number is :");  
    
  // Finding onescomplement in C  
  for(int i=0;i<n;i++) {  
    if(BinaryNumber[i]=='0')  
    onescomplement[i]='1';  
    else if(BinaryNumber[i]=='1')  
    onescomplement[i]='0';  
  }  
  onescomplement[n]='\0';  
  printf("%s",onescomplement);  
    
  
  printf("\nThe twos complement of a BinaryNumber number is : ");  
  
  // Finding twoscomplement in C  
  for(int i=n-1; i>=0; i--) {  
    if(onescomplement[i] == '1' && carry == 1) {  
      twoscomplement[i] = '0';  
    } else if(onescomplement[i] == '0' && carry == 1) {  
      twoscomplement[i] = '1';  
      carry = 0;  
    } else {  
      twoscomplement[i] = onescomplement[i];  
    }  
  }  
  twoscomplement[n]='\0';  
  printf("%s",twoscomplement);  
}  