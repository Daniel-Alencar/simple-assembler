#include <stdio.h>
#include <string.h>

void separateTokens(char *);

int main(){
    char string[] = "sw $s0,     ($t1)-100";

    separateTokens(string);
}

void separateTokens(char *string){
    char *character;
    
    character = strtok(string, ",() ");
    while (character){
        printf ("%s\n", character);
        character = strtok(NULL, ",() ");
    }
}