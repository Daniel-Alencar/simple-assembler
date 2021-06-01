#include <stdio.h>
#include <string.h>

void removeTokens(char *);

int main (){
    char string[] = "sw $s0, -100($t1)";
    
    removeTokens(string);
    
    printf("%s\n", string);
}

void removeTokens(char *string){
    char *character;

    character = strpbrk(string, ",()");

    while(character){
        strncpy(character, " ", 1);
        character = strpbrk(character + 1, ",()");
    }
}