#include <stdio.h>
#include <stdlib.h>
#include "../useful lib/global.c"

void findOnTypesOfInstructions(char *functionOfInstruction, int *row, char *corresponding);
void readOnCodeFile(FILE *file);
void getLabels(FILE *file);


int main() {
  FILE *file;
  file = fopen("file 3.asm", "r");
  getLabels(file);
}

void readOnCodeFile(FILE *file) {

}

void getLabels(FILE *file) {
  char string[30];
  int i;

  int validRow = 0;
  int labelsCounter = 0;
  int labelsPositionsCounter = 0;
  int rowsCounter = 0;

  int boolean = 1;

  // Pegar o Label (caso exista)
  for(i = 0; boolean; i++) {
    // Considerando inicialmente que não pode começar com 'espaço'

    string[i] = getc(file);

    if(string[i] == ':') {
      string[i] = '\0';
      strcpy(labels[labelsCounter], string); 

      printf("%s\n", labels[labelsCounter]);
      labelsCounter++;

      boolean = 0;
    }
  }

  // Setar a linha REAL que aquele Label se encontra
  for(i = 0; validRow == 0; i++) {
    string[i] = getc(file);

    if(string[i] != ' ' && string[i] != '\n' && string[i] != '#') {
      validRow = 1;
      rowsCounter++;

      labelsPositions[labelsPositionsCounter] = rowsCounter;

      printf("%d\n", labelsPositions[labelsPositionsCounter]);
      labelsPositionsCounter++;
    }
  }
}