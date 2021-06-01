#include <stdio.h>
#include <string.h>

void removeTokens(char *string){
    char *character;

    character = strpbrk(string, ",()");

    while(character){
        strncpy(character, " ", 1);
        character = strpbrk(character + 1, ",()");
    }
}