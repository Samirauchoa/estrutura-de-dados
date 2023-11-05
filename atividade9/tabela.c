#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void lista_inserir_no_ordenado(No *H, No *no) {
    No *anterior = H;
    No *atual = H->proximo_no;

    while (atual != NULL && atual->valor < no->valor) {
        anterior = atual;
        atual = atual->proximo_no;
    }

    anterior->proximo_no = no;
    no->proximo_no = atual;
}

void inserir_valor_lista_ordenada(No *lista_ordenada, float valor) {
    No *novo_no = (No *)malloc(sizeof(No));

    novo_no->valor = valor;
    novo_no->proximo_no = NULL;
    lista_inserir_no_ordenado(lista_ordenada, novo_no);
}

void inserir_valor_lista_nao_ordenada(No *lista_nao_ordenada, float valor) {
    No *novo_no = (No *)malloc(sizeof(No));

    novo_no->valor = valor;
    novo_no->proximo_no = lista_nao_ordenada->proximo_no;
    lista_nao_ordenada->proximo_no = novo_no;
}