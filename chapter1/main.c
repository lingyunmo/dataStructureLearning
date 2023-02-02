#include <stdio.h>

int main() {
    printf("The first program of data structure\n");
    int a[9];
    for (int i = 0; i < 9; i++) {
        a[i] = i;
    }
    for (int i = 0; i < 9; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
