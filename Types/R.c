void instructionR(char *instruction, char *function, char *result){
    int i, rs = 2, rd = 1;
    char *partsOfInstruction[4], temporary[17];
    
    partsOfInstruction[2] = (char *)malloc(sizeof(char) * 6);
    partsOfInstruction[3] = (char *)malloc(sizeof(char) * 6);

    strcpy(partsOfInstruction[2], "dipper");

    removeTokens(instruction);
    separateTokens(instruction, partsOfInstruction);

    strcpy(result, "000000");

    if(!strcmp(partsOfInstruction[2], "dipper")) {
      rs = 1;
      rd = 2;
      strcpy(partsOfInstruction[2], "$zero");
      strcpy(partsOfInstruction[3], "$zero");
    }

    for(i = 0; strcmp(partsOfInstruction[rs], registers[i]); i++);
    strcpy(temporary, convertDecimalToBinary(i, 5));
    strcat(result, temporary);

    for(i = 0; strcmp(partsOfInstruction[3], registers[i]); i++);
    strcpy(temporary, convertDecimalToBinary(i, 5));
    strcat(result, temporary);

    for(i = 0; strcmp(partsOfInstruction[rd], registers[i]); i++);
    strcpy(temporary, convertDecimalToBinary(i, 5));
    strcat(result, temporary);

    strcat(result, "00000");

    strcat(result, function);
}