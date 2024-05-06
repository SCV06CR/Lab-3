#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int findLargestSquare(int matrix[][SIZE], int n) {
    int maxSquareSize = 0;
    int i, j, k;
   
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            if (matrix[i][j] == 1) {
                int squareSize = 1;
                while (1) {
                    int flag = 1;
                    for (k = 0; k <= squareSize; ++k) {
                        if (i+k >= n || j+k >= n || matrix[i+k][j] == 0 || matrix[i][j+k] == 0) {
                            flag = 0;
                            break;
                        }
                    }
                    if (flag)
                        squareSize++;
                    else
                        break;
                }
                if (squareSize > maxSquareSize)
                    maxSquareSize = squareSize;
            }
        }
    }
    return maxSquareSize;
}

void printMatrix(int matrix[][SIZE], int n) {
    int i, j;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, i, j;
   
    printf("Ingrese el número de filas de la matriz nxn (1-10): ");
    scanf("%d", &n);
   
    if (n < 1 || n > 10)
        n = SIZE;
   
    srand(time(0));
   
    int matrix[SIZE][SIZE];
    printf("La matriz utilizada corresponde a:\n");
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            matrix[i][j] = rand() % 2; // Genera 0 o 1 aleatoriamente
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
   
    int largestSquareSize = findLargestSquare(matrix, n);
    printf("El tamaño del cuadrado más grande de unos es: %d x %d.\n", largestSquareSize, largestSquareSize);

    return 0;
}