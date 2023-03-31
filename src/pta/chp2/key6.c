#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList Create();

void Traverse(LinkList L);

int main() {
    LinkList L = Create();
    Traverse(L);
    return 0;
}

void Traverse(LinkList L) {
    if (L == NULL) {
        return;
    }
    LNode *q = L->next;
    while (q) {
        printf("%d ", q->data);
        q = q->next;
    }
}

LinkList Create() {
    LinkList L = (LinkList) malloc(sizeof(LNode));
    L->next = NULL;
    LNode *tail = L;
    ElemType x;
    while (scanf("%d", &x) != EOF) {
        LNode *p = (LNode *) malloc(sizeof(LNode));
        p->data = x;
        p->next = NULL;
        tail->next = p;
        tail = p;
    }
    return L;
}