#include <stdio.h>
#include <string.h>

void logicalAnd(char *, char *, char *);

int main (){
    char string1[] = "10101", string2[] = "11011";
    char string[5];

    logicalAnd(string1, string2, string);
    
    printf("%s\n", string);
}

void logicalAnd(char *string1, char *string2, char *string){
    for(int i = 0; i < strlen(string1); i++){
        string1[i] == '1' && string2[i] == '1' ? strcat(string + i, "1") : strcat(string + i, "0");
    }
}