void identifyInstruction(char **instructions, int amount){
    int line;
    char *aux, string[101], part[101], opcodeOrFunction[10], backup[101], result[101];
    FILE *funcoes;

    funcoes = fopen("../../Importante/funcoes.txt", "r");

    for(int i = 0; i < amount; i++){
        line = 0;

        strcpy(backup, instructions[i]);

        strcpy(part, strtok(instructions[i], " ,"));
        strcat(part, ":");

        while(!feof(funcoes)){
            if(!fgets(string, 101, funcoes)){
                break;
            }

            while((aux = strchr(string, '\n'))){
                aux[0] = '\0';
            }

            line++;
            if((aux = strstr(string, part))){
                strncpy(opcodeOrFunction, strchr(aux, ':') + 1, 6);

                switch(line){
                    case 1 :
                        instructionR(backup, opcodeOrFunction, result);
                        break;
                    case 2 :
                        instructionI(backup, opcodeOrFunction, result, i + 1);
                        break;
                    case 3 :
                        instructionJ(backup, opcodeOrFunction, result);
                        break;
                    default :
                        puts("default");
                        break;
                }
            }
        }
        rewind(funcoes);
        printf("%s\n", result);
    }
}