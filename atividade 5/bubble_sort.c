#include <string.h>
#include "bubble_sort.h"

void bubbleSort(char **words, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (strcmp(words[j], words[j+1]) > 0) {
                char *temp = words[j];
                words[j] = words[j+1];
                words[j+1] = temp;
            }
        }
    }
}
