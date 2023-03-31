#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20000

int *stack;
int top = -1;

void createStack() {
    stack = (int *)malloc(sizeof(int) * MAX_SIZE);
}

void push(int data) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = data;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

int is_empty() {
    return top == -1;
}

int main() {
    createStack();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int op;
        scanf("%d", &op);
        if (op) {
            int data;
            scanf("%d", &data);
            push(data);
        } else {
            if (!is_empty()) {
                printf("%d\n", pop());
            } else {
                printf("invalid\n");
            }
        }
    }
}