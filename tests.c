#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char teste[] = "lw $s0, 5($s1)";
  char *first;

  first = strchr(teste, '(');

  printf("%s\n", first);
}