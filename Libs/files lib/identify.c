void identifyInstruction(char **instructions, int amount){
    int line;
    char *aux, string[101], part[101], opcodeOrFunction[10], backup[101], end[101];
    FILE *funcoes;

    funcoes = fopen("../../Importante/funcoes.txt", "r");

    for(int i = 0; i < amount; i++){
        line = 0;

        strcpy(backup, instructions[i]);

        strcpy(part, strtok(instructions[i], " ,"));
        strcat(part, ":");

        while(!feof(funcoes)){
            fgets(string, 101, funcoes);

            while((aux = strchr(string, '\n'))){
                aux[0] = '\0';
            }

            line++;
            if((aux = strstr(string, part))){
                strncpy(opcodeOrFunction, strchr(string, ':') + 1, 6);
                switch(line){
                    case 1 :
                        printf("-%s = ", backup);
                        instructionR(backup, opcodeOrFunction, end, amount);
                        break;
                    case 2 :
                        printf("--%s = \t", backup);
                        instructionI(backup, opcodeOrFunction, end, amount);
                        break;
                    case 3 :
                        printf("---%s = \t", backup);
                        instructionJ(backup, opcodeOrFunction, end);
                        break;
                    default :
                        puts("default");
                        break;
                }
            }
        }
        rewind(funcoes);
        //printf("%s\n", end);
    }
}