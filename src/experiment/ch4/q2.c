#include <stdio.h>

int queue[20000];
int front;
int rear;

void initQueue();

void enterQueue(int x);

int deleteQueue();

int main() {
    int n, t;
    int i, k = 0;
    int a[20000][2];
    char ch;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        k = 0;
        do {
            scanf("%d", &a[i][k]);
            k++;
        } while ((ch = getchar()) != '\n');
    }
    for (i = 0; i < n; i++) {
        if (a[i][0] == 1)
        {
            enterQueue(a[i][1]);
        }
        if (a[i][0] == 0) {
            t = deleteQueue();
            if (t == 0)
                printf("invalid\n");
            else
                printf("%d\n", queue[front - 1]);
        }
    }
    return 0;
}

void initQueue() {
    front = 0;
    rear = 0;
}

void enterQueue(int x) {
    queue[rear] = x;
    rear++;
}

int deleteQueue() {
    if (front == rear)
        return 0;
    else {
        front++;
        return 1;
    }
}
