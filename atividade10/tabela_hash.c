#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

#define TAMANHO_TABELA 100

Hash* table[TAMANHO_TABELA]; //criação da tabela

//inicializar tabela com valores nulos
void hash_table_init() {
    int i = 0;

    for (i = 0; i < TAMANHO_TABELA; i++) {
        table[i] = NULL;
    }
}

int hash(char* chave){
    int hash = 0;
    int i = 0;
    for (i = 0; chave[i] != '\0'; i++) {
        hash = (hash + chave[i]) % TAMANHO_TABELA;
    }

    return hash;    
}

char* hash_table_get(char* chave){
    int indice = hash(chave);
    Hash* hash = table[indice];

    while (hash != NULL) {
        if (strcmp(hash->chave, chave) == 0) {
            return hash->valor;
        }
        hash = hash->proximo;
    }

    return NULL;
}

void hash_table_put(char* chave, char* valor){
    int indice = hash(chave); //chave convertida pra inteiro
    Hash* novo_hash = (Hash*)malloc(sizeof(Hash));

    novo_hash->chave = chave;
    novo_hash->valor = valor;
    novo_hash->proximo = table[indice];
    table[indice] = novo_hash;
}

int hash_table_contains(char* chave){
    return hash_table_get(chave) != NULL;
}

void hash_table_remove(char* chave){
    int indice = hash(chave);
    Hash* hash = table[indice];
    Hash* anterior = NULL;

    while (hash != NULL) {
        if (strcmp(hash->chave, chave) == 0) {
            if (anterior != NULL) {
                anterior->proximo = hash->proximo;
            } else {
                table[indice] = hash->proximo;
            }
            free(hash);
            return;
        }
        anterior = hash;
        hash = hash->proximo;
    }
}