#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main() {
  char str[80];
  sprintf(str, "Value of Pi = %016d", 1001101);
  puts(str);
}