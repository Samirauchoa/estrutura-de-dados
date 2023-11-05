typedef struct No {
    float valor;
    struct No *proximo_no;
} No;

void lista_inserir_no_ordenado(No *H, No *no);
void inserir_valor_lista_ordenada(No *lista_ordenada, float valor);
void inserir_valor_lista_nao_ordenada(No *lista_nao_ordenada, float valor);