#include <stdio.h>
#include <string.h>

void logicalFunctions(char *, char *, char *, char *);

int main (){
    char string1[] = "10101", string2[] = "11011", string[5];
    char label[] = "xor";

    logicalFunctions(string1, string2, string, label);
    
    printf("%s\n", string);
}

void logicalFunctions(char *string1, char *string2, char *string, char *label){
    for(int i = 0; i < strlen(string1); i++){
        if(!strcmp(label, "and")){
            string1[i] == '1' && string2[i] == '1' ? strcat(string + i, "1") : strcat(string + i, "0");
        } else if(!strcmp(label, "or")){
            string1[i] == '1' || string2[i] == '1' ? strcat(string + i, "1") : strcat(string + i, "0");
        } else if(!strcmp(label, "xor")) {
            string1[i] == '1' ^ string2[i] == '1' ? strcat(string + i, "1") : strcat(string + i, "0");
        }
    }
}