#include <stdio.h>

int soma_array(int arr[], int size) {
    int soma = 0;
    for (int i = 0; i < size; i++) {
        soma += arr[i];
    }
    return soma;
}

int main() {
    int arr[] = {6, 7, 8, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    int resultado = soma_array(arr, size);
    printf("A soma dos elementos do array é: %d\n", resultado);

    return 0;
}
