#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    if(argc > 3 || argc < 2){
        puts("Sintaxe de parametros invalida!");
        puts("Digite: [executavel.exe] [arquivo_de_entrada.asm] [arquivo_de_saida](opicional)");
        puts("Erro 0!");
        exit(0);
    } else {
        FILE *inputFile, *outputFile;
        int typePosition = strlen(argv[1]) - strlen(".asm");
        char *defaultName = "output.dat";

        if(strcmp(argv[1] + typePosition, ".asm")){
            puts("Arquivo de entrada precisa ter a extensao '.asm'");
            puts("Erro 1!");
            exit(1);
        } else {
            inputFile = fopen(argv[1], "r");
            if(!inputFile){
                puts("Falha ao abrir o arquivo de entrada!");
                puts("Erro 2!");
                exit(2);
            }

            if(argc == 2){
                outputFile = fopen(defaultName, "w");
            } else {
                strcat(argv[2], ".dat");
                outputFile = fopen(argv[2], "w");
            }
            if(!outputFile){
                puts("Falha ao criar o arquivo de saida!");
                puts("Erro 3!");
                exit(3);
            }
        }
    }
}