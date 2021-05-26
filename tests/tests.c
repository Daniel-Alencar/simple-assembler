#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char teste[] = "lw $s0, 555($s1)";
  char *first, *aux;
  int lenght;

  first = strchr(teste, '(');

  for(lenght = 0; !(aux = strpbrk(teste + strlen(teste) - strlen(first) - lenght, ", ")); lenght++);
  
  //memset(teste + strlen(teste) - strlen(aux), ' ', lenght);
  printf("%s\n", aux);
  strncat(teste, aux + 1, lenght - 1);

  //memset(aux, '-', lenght);

  printf("%s\n", teste);
  printf("%d\n", lenght);
}