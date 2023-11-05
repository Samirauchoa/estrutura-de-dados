#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

int main(int argc, char* argv[]){
    hash_table_init();

    hash_table_put("DF", "Brasilia");
    hash_table_put("SP", "Sao Paulo");
    hash_table_put("AC", "[Unknown]");

    char* valor1 = hash_table_get("DF");
    char* valor2 = hash_table_get("SP");
    char* valor3 = hash_table_get("AC");

    printf("ALGUMAS CAPITAIS DO BRASIL\n\n");

    printf("Chave: DF --- Valor: %s\n", valor1);
    printf("Chave: SP --- Valor: %s\n", valor2);
    printf("Chave: AC --- Valor: %s\n\n", valor3);
    

    if (hash_table_contains("AC")) {
        printf("A chave \"AC\" esta na tabela.\n");
    } else {
        printf("A chave \"AC\" nao esta na tabela.\n");
    }

    hash_table_remove("AC");

    if (hash_table_contains("AC")) {
        printf("A chave AC esta na tabela.\n");
    } else {
        printf("A chave AC nao esta na tabela.\n");
    }

    return 0;
}