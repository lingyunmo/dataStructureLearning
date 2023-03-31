#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

#define Maxsize 20000
typedef int Position;
typedef int ElementType;
typedef struct QNode *PTrToQNode;
struct QNode {
    ElementType *Data;
    Position front, rear;
    int maxsize;
};
typedef PTrToQNode Queue;

Queue CreateQueue(int maxsize) {
    Queue Q = (Queue) malloc(sizeof(struct QNode));
    Q->Data = (ElementType *) malloc(maxsize * sizeof(ElementType));
    Q->maxsize = maxsize;
    Q->front = Q->rear = 0;
    return Q;
}

bool Add(Queue Q, ElementType X) {
    if ((Q->rear + 1) % Q->maxsize == Q->front) {
        printf("队满");
        return false;
    } else {
        Q->rear = (Q->rear + 1) % Q->maxsize;
        Q->Data[Q->rear] = X;
        return true;
    }
}

void DeleteQ(Queue Q) {
    if (Q->front == Q->rear) {
        printf("invalid\n");
    } else {
        Q->front = (Q->front + 1) % Q->maxsize;
        printf("%d\n", Q->Data[Q->front]);
    }
}

int main() {
    int a, b, c;
    Queue Q = CreateQueue(Maxsize);
    scanf("%d", &a);
    for (; a > 0 && a < Maxsize; a--) {
        scanf("%d", &b);
        if (b == 1) {
            scanf("%d", &c);
            Add(Q, c);
        }
        if (b == 0) {
            DeleteQ(Q);
        }
    }
    return 0;
}