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
        printf("-%s-%d-\n", labels[i], labelsPositions[i]);
    }
}

void cleanLineOfFile(FILE *file, char *string){
    char *aux;
    char aux1;
    int numberOfLabels = 0, linePosition = 0, labelsPositionsCounter = 0;
    int changeNumberOfLabels = 0;

    labels = (char **)malloc(sizeof(char *));
    labelsPositions = (int *)malloc(sizeof(int));

    do{
        if(fgets(string, 101, file) == NULL){
            break;
        }
        
        //remove comentario da linha
        while(aux = strchr(string, '#')){
            strcpy(aux, "\0");
        }
        
        //substitui tab por espaço
        int i = 0;
        while(aux1 = string[i], aux1 == '\t') {
            aux = strchr(string, '\t');
            strcpy(aux, aux + 1);
            i++;
        }
        
        while(aux = strchr(string, '\t')) {
            aux[0] = ' ';
        }

        //se for linha válida
        if(strcmp(string, "\n") && strcmp(string, "\0") && strcmp(string, " ")){
            // linePosition++;
            aux = splitLabel(string);
            if(aux){
                numberOfLabels++;
                changeNumberOfLabels = 1;

                labels = (char **)realloc(labels, sizeof(char *) * numberOfLabels);
                labels[numberOfLabels - 1] = (char *)malloc(sizeof(char) * strlen(aux));
                strcpy(labels[numberOfLabels - 1], aux);

                //remove espaços do label
                while(aux = strchr(labels[numberOfLabels - 1], ' ')){
                    strcpy(aux, aux + 1);
                }
            }

            //remove labels da string
            while(aux = strchr(string, ':')){
                strcpy(string, aux + 1);
            }
            //se após remover o label sobrou alguma instrução válida
            
            if(strcmp(string, "\n") && strcmp(string, "\0") && strcmp(string, " ")){
                linePosition++;
                // printf("||%s||\n", string);
                
                if(changeNumberOfLabels) {
                    labelsPositions = (int *)realloc(labelsPositions, sizeof(int) * numberOfLabels);
                    labelsPositions[numberOfLabels - 1] = linePosition;

                    changeNumberOfLabels = 0;
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