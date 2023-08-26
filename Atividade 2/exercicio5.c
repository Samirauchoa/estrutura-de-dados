#include <stdio.h>

void multiplica_array(const int arr1[], const int arr2[], int result[], int size) {
    for (int i = 0; i < size; i++) {
        result[i] = arr1[i] * arr2[i];
    }
}

int main() {
    int arr1[] = {3, 7, 10, 2};
    int arr2[] = {3, 7, 10, 2};
    int size = sizeof(arr1) / sizeof(arr1[0]);

    int resultado[size];
    multiplica_array(arr1, arr2, resultado, size);

    printf("Resultado da multiplicação: [");
    for (int i = 0; i < size; i++) {
        printf("%d", resultado[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}
