#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void switchPosition(char *);

int main(){
  char string[50] = "sw $s0, -100($t1)";

  switchPosition(string);
  
  printf("%s\n", string);
}

void switchPosition(char *string){
  char *first, *aux;
  int lenght;

  first = strchr(string, '(');

  for(int i = 0; !(aux = strpbrk(string + strlen(string) - i, ", ")); i++);
  
  lenght = strlen(aux) - strlen(first);
  
  strncat(string, aux + 1, lenght - 1);
  memset(aux, ' ', lenght);
}