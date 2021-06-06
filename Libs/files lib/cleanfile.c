#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cleanLineOfFile(FILE *, char *, int *);

int main(){
    int rows[10];
    FILE *input;
    char str[101];

    input = fopen("file 3.0.asm", "r");

    cleanLineOfFile(input, str, rows);

}

void cleanLineOfFile(FILE *file, char *string, int *lines){
    char *aux;

    do{
        fgets(string, 101, file);

        //remove comentario da linha
        while(aux = strchr(string, '#')){
            strcpy(aux, "\0");
        }

        //trocando tab por espaço
        while(aux = strchr(string, '\t')){
            aux[0] = '*';
        }

        //---------tab trocado por espaço
        if(string[0] != '\n' && string[0] != '\0'){
            // printf("%s\n", string);
            // int i = strcspn(string, ":");
            // if(i != strlen(string)){
            //     printf("%s\n", string);
            // }
            splitLabel(string, aux);
            printf("%s\n", aux);
        }
        printf("%s\n", string);
    } while(!feof(file));
}

void splitLabel(char *string, char *result){
    for(int i = 0; i < strlen(string); i++){
        if(string[i] != ':'){
            result = (char *)realloc(result, sizeof(char) * i);
            result[i] = string[i];
        } else {
            return;
        }
    }
    return;
}