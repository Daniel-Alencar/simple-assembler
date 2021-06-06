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

  for(int i = 0; i < 10 ; i++) {
    printf("|| %s => %d ||\n", labels[i], labelsPositions[i]);
  }
}

void readOnCodeFile(FILE *file) {

}

void getLabels(FILE *file) {
  char string[30];
  char aux;
  int i, j;

  int validRow = 0;

  int labelsCounter = 0;
  int labelsPositionsCounter = 0;
  int rowsCounter = 0;

  int boolean = 1;

  for(j = 0; feof(file) == 0; j++) {

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
          // printf("%c", aux);
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
          // printf("%c", aux);
        }
        // printf("\n\n");
      }
    }
    validRow = 0;
    boolean = 1;
  }
  printf("ACABOU");
}