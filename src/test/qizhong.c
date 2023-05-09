#include<stdio.h>
#include <malloc/_malloc.h>

#define MAXSIZE 5
struct SC {
    int Data[10];
    int data;
    int Last;
    struct SC *next;
};

struct AA {
    struct AA *rear;
    struct AA *front;
    struct AA *next;
};
typedef struct AA List;

int main() {
    int i, j;
    struct SC a;
    struct SC *PtrL = &a, *p, *q;
    for (j = PtrL->Last; j >= i - 1; j--)
        PtrL->Data[j - 1] = PtrL->Data[j];

    q = p->next;
    p->data = q->data;
    free(q);
    struct AA *Q;
    if ((Q->rear - 1) % MAXSIZE == Q->front) {
        int a = (Q->rear - Q->front + 1 + MAXSIZE) % MAXSIZE;
        int b = a;
    }
    struct AA *s;
    s->next = Q->next;
    Q->next = s;
}

int Length(List *PtrL) {
    List *p = PtrL;
    int j = 0;
    while (p) {
        p = p->next;
        j++;
    }
    return j;
}