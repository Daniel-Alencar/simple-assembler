void separateTokens(char *string, char *array[]){
    int i = 0;
    char *character = strtok(string, ",() ");

    while (character){
        array[i] = (char *)malloc(strlen(character));

        strcpy(array[i], character);
        character = strtok(NULL, ",() ");
        i++;
    }
}