#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char teste[50] = "sw $s0, -100($t1)";
  char *first, *aux;
  int lenght;

  first = strchr(teste, '(');

  for(int i = 0; !(aux = strpbrk(teste + strlen(teste) - i, ", ")); i++);
  
  lenght = strlen(aux) - strlen(first);
  
  strncat(teste, aux + 1, lenght - 1);
  memset(aux, ' ', lenght);

  printf("%s\n", teste);
}