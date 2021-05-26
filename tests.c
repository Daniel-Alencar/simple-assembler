#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char teste[] = "lw $s0, 5($s1)";
  char *first;
  int lenght;

  first = strchr(teste, '(');

  printf("%s\n", first);
  printf("# %s\n", teste + strlen(first));

  for(lenght = 0; strcmp(teste + strlen(teste) - strlen(first) - lenght, ","); lenght++){
    printf("$ %d\n", lenght);
  }
}