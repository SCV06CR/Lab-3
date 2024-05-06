#include <stdio.h>

int main() {
    int i, triangularNumber = 0;

    printf("Los primeros 100 números triangulares son:\n");

    for (i = 1; i <= 100; ++i) {
        triangularNumber += i;
        printf("%d ", triangularNumber);
    }

    return 0;
}