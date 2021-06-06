#include <stdio.h>
#include <stdlib.h>
#include "../useful lib/global.c"

void findOnTypesOfInstructions(char *functionOfInstruction, int *row, char *corresponding);
void readOnCodeFile(FILE *file);
void getLabels(FILE *file);


int main() {
  FILE *file;
  file = fopen("file 3.0.asm", "r");
  getLabels(file);

  printf("ACABOU\n");
}

void readOnCodeFile(FILE *file) {

}

void getLabels(FILE *file) {
  char string[30];
  char aux;
  int i, j, chegouNoFinalDoArquivo = 0;

  int validRow = 0;

  int labelsCounter = 0;
  int labelsPositionsCounter = 0;
  int rowsCounter = 0;

  int boolean = 1;

  for(j = 0; !chegouNoFinalDoArquivo; j++) {

    // Pegar o Label (considerando que sempre exista)
    for(i = 0; boolean; i++) {
      // Considerando inicialmente que não pode começar com 'espaço'

      string[i] = getc(file);

      if(string[i] == ':') {
        string[i] = '\0';
        strcpy(labels[labelsCounter], string); 

        printf("|| %s => ", labels[labelsCounter]);
        labelsCounter++;

        boolean = 0;
      }
    }

    // Setar a linha REAL que aquele Label se encontra
    for(i = 0; validRow == 0; i++) {
      string[i] = getc(file);

      if(string[i] == '#') {
        // Jogar o ponteiro para o '\n' da linha
        // printf("(cerquilha) ");
        while(aux = getc(file), aux != '\n') {
          // printf("2");
        }
        // printf("\n\n");

      } else if ((string[i] != ' ') && (string[i] != '\n') && (string[i] != 9)) {

        validRow = 1;
        rowsCounter++;

        labelsPositions[labelsPositionsCounter] = rowsCounter;

        printf("%d ||\n", labelsPositions[labelsPositionsCounter]);
        labelsPositionsCounter++;

        // Jogar o ponteiro para o '\n' da linha
        // printf("(espaço) ");
        while(aux = getc(file), aux != '\n') {
          // printf("1");
        }
        // printf("\n\n");


        // ===============================================================================
        // Verificando se tem mais algum caractere útil ou se chegamos no fim do arquivo
        FILE *auxFile = file;
        while(aux = getc(file), 1) {
          if((aux != ' ') && (aux != '\n') && (aux != 9)) {
            // Caractere válido encontrado
            printf("%c\n", aux);

            fseek(file, -1, SEEK_CUR);
            break;
          } else if(feof(file) == 0) {
            // Chegamos no final do arquivo
            printf("FEOF\n");
            chegouNoFinalDoArquivo = 1;

            break;
          }
        }
        // ===============================================================================

      }
    }
    validRow = 0;
    boolean = 1;
  }
  // while(aux = getc(file), feof(file) == 0) {
  //   printf("%c", aux);
  // }
  // printf("\n");
}