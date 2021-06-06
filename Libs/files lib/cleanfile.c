#include <stdio.h>
#include <stdio.h>
#include <string.h>

cleanLineOfFile(FILE *, char *, int *);

int main(){
    int *rows;
    FILE *input;
    char str[101];

    input = fopen("file 3.0.asm", "r");

    cleanLineOfFile(input, str, rows);

}

cleanLineOfFile(FILE *file, char *string, int *lines){
    size_t i = 0;
    char backup[strlen(string)], label[101], *aux;

    do{
        fgets(string, 101, file);

        strcpy(backup, string);

        //remove comentario da linha
        while(aux = strchr(string, '#')){
            strcpy(aux, "\0");
        }

        //trocando tab por espaço
        while(aux = strchr(string, '\t')){
            aux[0] = '*';
        }

        //---------tab trocado por espaço
        if(strcmp(string, "\n") && strcmp(string, "\0")){
            i = strcspn(string, ":");
            if(i){
                printf("%s\t%d\n", string, i);
            }
        }
    } while(!feof(file));
}