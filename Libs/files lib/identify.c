void identifyInstruction(char **instructions, int amount){
    int line;
    char *aux, string[101], part[101], opcodeOrFunction[10];
    FILE *funcoes;

    funcoes = fopen("../../Importante/funcoes.txt", "r");

    for(int i = 0; i < amount; i++){
        line = 0;

        strcpy(part, strtok(instructions[i], " ,"));
        strcat(part, ":");

        while(!feof(funcoes)){
            fgets(string, 101, funcoes);

            while(aux = strchr(string, '\n')){
                aux[0] = '\0';
            }

            line++;
            if(aux = strstr(string, part)){
                strncpy(opcodeOrFunction, strchr(string, ':') + 1, 6);
                break;
            }

            switch(line){
                case 1 :
                    printf("%s\n", string);
                    //instructionR(char *instruction, char *function, char *result, int lineNumber)
                    break;
                case 2 :
                    break;
                case 3 :
                    break;
                default :
                    puts("default");
                    break;
            }
        }
        rewind(funcoes);
    }
}