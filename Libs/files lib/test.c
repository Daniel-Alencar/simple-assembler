#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str[] ="*add $s0, $s1, $zero";
    char * pch;

    pch = strtok (str,":");
    printf ("%s\n",pch);
    while (pch != NULL)
    {
        printf ("%s\n",pch);
        pch = strtok (NULL, ":");
    }
}