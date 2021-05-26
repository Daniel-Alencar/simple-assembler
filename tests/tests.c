#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char teste[] = "lw $s0, 5($s1)";
  char *first, *aux;
  int lenght;

  first = strchr(teste, '(');
  printf("%s\n", first);

  for(lenght = 0; !(aux = strpbrk(teste + strlen(teste) - strlen(first) - lenght, ", ")); lenght++);
  
  printf("!%s\n", aux);
}