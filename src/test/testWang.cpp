#include<stdio.h>

void matrixshow(int array[2][2]) {
    int i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d ", array[i][j]);
        }
        printf("%d ", array[i][j]);
    }
}

void multiplmatrix(int **array1, int **array2, int result[2][2]) {
    int i, j, k;
    for (i = 0; i < 2; i++) {
        for (k = 0; k < 2; k++) {
            result[k][i] = 0;
            for (j = 0; j < 2; j++) {
                result[k][i] = array1[i][j] * array2[j][k];
            }
        }
    }
}

int main() {
    int i;
    int *p[2];
    int *q[2];
    int result[2][2];
    int array1[2][2] = {{1, 2},
                        {3, 4}};
    int array2[2][2] = {{5, 6},
                        {7, 8}};
    for (i = 0; i < 2; i++) {
        p[i] = array1[i];
        q[i] = array2[i];
    }
    multiplmatrix(p, q, result);
    matrixshow(result);
}