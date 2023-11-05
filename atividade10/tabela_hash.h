typedef struct Hash {
    char* chave;
    char* valor;
    struct Hash* proximo;
} Hash;

void hash_table_init();
char* hash_table_get(char* chave);
void hash_table_put(char* chave, char* valor);
int hash_table_contains(char* chave);
void hash_table_remove(char* chave);