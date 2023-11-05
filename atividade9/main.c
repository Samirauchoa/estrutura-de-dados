#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lista.h"

int main(int argc, char* argv[]) { //inserir nome do arquivo como ARGUMENTO!
    FILE *arquivo = fopen(argv[1], "r");

    No lista_nao_ordenada;
    No lista_ordenada;
    lista_nao_ordenada.proximo_no = NULL;
    lista_ordenada.proximo_no = NULL;

    char linha[20];
    float valor;
    clock_t t_inicial, t_final;
    double tempo_nao_ordenada = 0.0;
    double tempo_ordenada = 0.0;
    int num_elementos = 0;

    while (fgets(linha, sizeof(linha), arquivo)) {
        valor = strtof(linha, NULL);

        //Inserir na lista NÃO ordenada
        t_inicial = clock();
        inserir_valor_lista_nao_ordenada(&lista_nao_ordenada, valor);
        t_final = clock();
        tempo_nao_ordenada += (double)(t_final - t_inicial) / CLOCKS_PER_SEC;

        //Inserir na lista ordenada
        t_inicial = clock();
        inserir_valor_lista_ordenada(&lista_ordenada, valor);
        t_final = clock();
        tempo_ordenada += (double)(t_final - t_inicial) / CLOCKS_PER_SEC;

        num_elementos++;
    }

    printf("TEMPO MEDIO DE INSERCAO\n\n");
    printf("\tLista NAO ordenada: %lf s\n", tempo_nao_ordenada / num_elementos);
    printf("\tLista     ordenada: %lf s\n", tempo_ordenada / num_elementos);

    //liberar memória (apagar listas)
    No *atual = lista_nao_ordenada.proximo_no;
    while (atual != NULL) {
        No *proximo = atual->proximo_no;
        free(atual);
        atual = proximo;
    }

    atual = lista_ordenada.proximo_no;
    while (atual != NULL) {
        No *proximo = atual->proximo_no;
        free(atual);
        atual = proximo;
    }

    fclose(arquivo);
    return 0;
}