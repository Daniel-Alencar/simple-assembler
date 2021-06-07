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

    for(int i = 0; i < 3; i++){
        printf("-%s-\n", labels[i]);
    }
}

void cleanLineOfFile(FILE *file, char *string){
    char *aux;
    int numberOfLabels = 0, labelPosition = 0;

    labels = (char **)malloc(sizeof(char *));
    labelsPositions = (int *)malloc(sizeof(int));

    do{
        fgets(string, 101, file);
        
        //remove comentario da linha
        while(aux = strchr(string, '#')){
            strcpy(aux, "\0");
        }
        
        //remove tab da linha
        while(aux = strchr(string, '\t')){
            aux[0] = ' ';
        }

        //se for linha válida
        if(strcmp(string, "\n") && strcmp(string, "\0") && strcmp(string, " ")){
            labelPosition++;
    
            aux = splitLabel(string);
            if(aux){

                numberOfLabels++;

                labels = (char **)realloc(labels, sizeof(char *) * numberOfLabels);
                labels[numberOfLabels - 1] = (char *)malloc(sizeof(char) * strlen(aux));
                strcpy(labels[numberOfLabels - 1], aux);

                labelsPositions = (int *)realloc(labelsPositions, sizeof(int) * numberOfLabels);
                labelsPositions[numberOfLabels - 1] = labelPosition;

                //remove espaços do label
                while(aux = strchr(labels[numberOfLabels - 1], ' ')){
                    strcpy(aux, aux + 1);
                }
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