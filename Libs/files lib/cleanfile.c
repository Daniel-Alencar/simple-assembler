#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../global.h"
#include "../clean lib/clean.h"
#include "../clean lib/clean.c"
#include "../useful lib/useful.h"
#include "../useful lib/useful.c"
#include "../../Types/types.h"
#include "../../Types/types.c"
#include "identify.c"

void cleanLineOfFile(FILE *, char *);
char *splitLabel(char *string);

void cleanLineOfFile(FILE *file, char *string){
    char *aux;
    char aux1;
    int numberOfLabels = 0, linePosition = 0;
    int changeNumberOfLabels = 0;
    char **instructions;

    instructions = (char **)malloc(sizeof(char *));
    labels = (char **)malloc(sizeof(char *));
    labelsPositions = (int *)malloc(sizeof(int));

    do{
        if(!fgets(string, 101, file)){
            break;
        }
        
        //remove comentario da linha
        while((aux = strchr(string, '#'))){
            strcpy(aux, "\0");
        }

        //remove \n
        while((aux = strchr(string, '\n'))){
            strcpy(aux, "\0");
        }
        
        //substitui tab por espaço
        int i = 0;
        while((aux1 = string[i], aux1 == '\t')) {
            aux = strchr(string, '\t');
            strcpy(aux, aux + 1);
            i++;
        }
        
        while((aux = strchr(string, '\t'))) {
            aux[0] = ' ';
        }

        //se for linha válida
        if(strcmp(string, "\0") && strcmp(string, " ")){
            aux = splitLabel(string);
            if(aux){
                numberOfLabels++;
                changeNumberOfLabels = 1;

                labels = (char **)realloc(labels, sizeof(char *) * numberOfLabels);
                labels[numberOfLabels - 1] = (char *)malloc(sizeof(char) * strlen(aux));
                strcpy(labels[numberOfLabels - 1], aux);

                //remove espaços do label
                while((aux = strchr(labels[numberOfLabels - 1], ' '))){
                    strcpy(aux, aux + 1);
                }
            }

            //remove labels da string
            while((aux = strchr(string, ':'))){
                strcpy(string, aux + 1);
            }
            //se após remover o label sobrou alguma instrução válida
            
            if(strcmp(string, "\0") && strcmp(string, " ")){
                linePosition++;
                
                if(changeNumberOfLabels) {
                    labelsPositions = (int *)realloc(labelsPositions, sizeof(int) * numberOfLabels);
                    labelsPositions[numberOfLabels - 1] = linePosition;

                    changeNumberOfLabels = 0;
                }
                
                instructions = (char **)realloc(instructions, sizeof(char *) * linePosition);
                instructions[linePosition - 1] = (char *)malloc(sizeof(char) * (strlen(string) + 1));
                strcpy(instructions[linePosition - 1], string);
            }
        }
    } while(!feof(file));

    numbOfLabels = numberOfLabels;
    identifyInstruction(instructions, linePosition);
}

char *splitLabel(char *string){
    char *result;
    result = (char *)malloc(sizeof(char));

    for(unsigned int i = 0; i < 
    
    strlen(string); i++){
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