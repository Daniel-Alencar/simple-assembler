#include <stdio.h>
#include <string.h>

void logicalFunctions(char *, char *, char *, char *);

int main (){
    char string1[] = "10101", string2[] = "11011", string[5], label[] = "xor";

    logicalFunctions(string1, string2, string, label);
    
    printf("%s", string);
}

void logicalFunctions(char *string1, char *string2, char *string, char *label){
    int i = 0;

    if(!strcmp(label, "and")){
        for(; i < strlen(string1); i++){
            string1[i] == '1' && string2[i] == '1' ? strcpy(string + i, "1") : strcat(string + i, "0");
        }
    } else if(!strcmp(label, "or")){
        for(; i < strlen(string1); i++){
            string1[i] == '1' || string2[i] == '1' ? strcpy(string + i, "1") : strcat(string + i, "0");
        }
    } else if(!strcmp(label, "xor")) {
        for(; i < strlen(string1); i++){
            string1[i] == '1' ^ string2[i] == '1' ? strcpy(string + i, "1") : strcat(string + i, "0");
        }
    } else {
        return;
    }
}