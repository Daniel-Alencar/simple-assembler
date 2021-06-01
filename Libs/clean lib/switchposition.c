#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void switchPosition(char *instruction){
  char *first, *aux;
  int lenght;

  first = strchr(instruction, '(');
  for(int i = 0; !(aux = strpbrk(instruction + strlen(instruction) - i, ", ")); i++);
  lenght = strlen(aux) - strlen(first);
  strncat(instruction, aux + 1, lenght - 1);
  memset(aux, ' ', lenght);
}
