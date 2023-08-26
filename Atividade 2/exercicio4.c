#include <stdio.h>

int conta_int_array(int arr[], int size, int busca) {
    int contador = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] == busca) {
            contador++;
        }
    }

    return contador;
}

int main() {
    int arr[] = {6, 2, 3, 8, 15, 11, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int busca = 7;

    int quantidade = conta_int_array(arr, size, busca);

    printf("O número %d aparece %d vezes no array.\n", busca, quantidade);

    return 0;
}
