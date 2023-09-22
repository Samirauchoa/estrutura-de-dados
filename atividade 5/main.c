#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <nome_arquivo_entrada>\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    
    int numLines = 0;
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), inputFile) != NULL) {
        numLines++;
    }
    rewind(inputFile);

    
    char **words = (char **)malloc(numLines * sizeof(char *));
    for (int i = 0; i < numLines; i++) {
        words[i] = (char *)malloc(100 * sizeof(char)); 
        fscanf(inputFile, "%s", words[i]);
    }

    
    bubbleSort(words, numLines);

    
    char outputFileName[100];
    sprintf(outputFileName, "%s_ordenado.txt", argv[1]);
    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        perror("Erro ao criar o arquivo de saída");
        return 1;
    }

   
    for (int i = 0; i < numLines; i++) {
        fprintf(outputFile, "%s\n", words[i]);
        free(words[i]);
    }

    
    free(words);


    fclose(inputFile);
    fclose(outputFile);

    printf("Arquivo de saída criado com sucesso: %s\n", outputFileName);

    return 0;
}
