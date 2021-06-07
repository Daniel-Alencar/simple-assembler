#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../useful lib/global.c"

void cleanLineOfFile(FILE *, char *);
char *splitLabel(char *string);

int main(){
    int rows[10];
    FILE *input;
    char str[101];

    input = fopen("file 3.0.asm", "r");

    cleanLineOfFile(input, str);

    for(int i = 0; i < 10; i++){
        printf("%d\n", rows[i]);
    }

}

void cleanLineOfFile(FILE *file, char *string){
    char *aux;
    int i = 0, j = 0;

    labels = (char **)malloc(sizeof(char *));
    labelsPositions = (int *)malloc(sizeof(int));

    do{
        fgets(string, 101, file);

        //remove comentario da linha
        while(aux = strchr(string, '#')){
            strcpy(aux, "\0");
        }

        //trocando tab por espaço
        while(aux = strchr(string, '\t')){
            aux[0] = '\b';
        }

        //---------tab trocado por espaço
        if(string[0] != '\n' && string[0] != '\0'){
            j++;

            aux = splitLabel(string);
            if(aux){
                i++;

                labels = (char **)realloc(labels, sizeof(char *) * i);
                labels[i - 1] = (char *)malloc(sizeof(char) * strlen(aux));
                strcpy(labels[i - 1], aux);

                // labelsPositions = (int *)realloc(labelsPositions, sizeof(int) * i);
                // labelsPositions[i - 1] = j;
            }
        }
    } while(!feof(file));
}

char *splitLabel(char *string){
    char *result;
    result = (char *)malloc(sizeof(char));

    for(int i = 0; i < strlen(string); i++){
        if(string[i] != ':'){
            result = (char *)realloc(result, sizeof(char) * (i + 1));
            result[i] = string[i];
        } else {
            result[i] = '\0';
            return result;
        }
    }
    return NULL;
}