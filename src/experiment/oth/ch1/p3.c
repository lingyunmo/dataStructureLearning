#include<stdio.h>

int a[100000];

int main() {
    int n, m;
    int x, y;
    char c;
    int count = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        getchar();

        scanf("%c", &c);
        if (c == 'I')//排在队尾
        {
            scanf("%d", &x);
            a[count] = x;
            count++;
        } else if (c == 'C') {
            scanf("%d %d", &x, &y);
            for (int k = 0; k < count; k++) {
                if (a[k] == y) {
                    for (int j = count; j > k; j--) {
                        a[j] = a[j - 1];
                    }
                    a[k] = x;
                    break;
                }

            }
            count++;
        } else if (c == 'L') {
            scanf("%d", &x);
            for (int k = 0; k < count; k++) {
                if (a[k] == x) {
                    for (int j = k; j < count - 1; j++) {
                        a[j] = a[j + 1];
                    }
                    break;
                }
            }
            count--;
        }
    }
    if (count == 0) {
        printf("Bai Ren Zhan\n");
    } else {
        for (int i = 0; i < count; i++) {
            printf("%d ", a[i]);
        }
    }
}