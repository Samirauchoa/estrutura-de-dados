#include <stdio.h>

void menor_maior_array(int arr[], int size, int *menor, int *maior) {
    *menor = arr[0];
    *maior = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < *menor) {
            *menor = arr[i];
        }
        if (arr[i] > *maior) {
            *maior = arr[i];
        }
    }
}

int main() {
    int arr[] = {6, 8, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    int menor, maior;
    menor_maior_array(arr, size, &menor, &maior);

    printf("O menor elemento do array é: %d\n", menor);
    printf("O maior elemento do array é: %d\n", maior);

    return 0;
}
