// int main() {
//   char instruction[] = "j for";
//   char result[33];

//   instructionJ(instruction, "000010", result);
//   printf("%s\n", result);
// }

void instructionJ(char *instruction, char *opcode, char *result){
  int i;
  char targetAddress[27];
  char label[33];
  
  // Leitura e procura do 'for' no labels, identificar a posição e procurar valor correspondente em linhaDosLabels
  sscanf(instruction, "%*s %s", label);

  for(i = 0; i < 32; i++){
    if(!strcmp(labels[i], label)){
      break;
    }
  }

  // Manipular o valor da linhaDosLabels para formar o target address
  strcpy(targetAddress, convertDecimalToBinary(labelsPositions[i] - 1, 26));
  
  strcpy(result, opcode);
  strcat(result, targetAddress);
}