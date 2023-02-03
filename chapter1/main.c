#include <stdio.h>

void PrintN1(int N) {
    int i;
    for (i = 1; i <= N; i++) {
        printf("%d ", i);
    }
}

void PrintN2(int N) {
    if (N > 0) {
        PrintN2(N - 1);
        printf("%d ", N);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    PrintN1(N);
    printf("\n");
    PrintN2(N);
    return 0;
}