#include "stdio.h"
#include "stdlib.h"

struct LNode {
    int Data;
    struct LNode *Next;
};

void InitList(struct LNode *L) {
    L = (struct LNode *) malloc(sizeof(struct LNode));
    L->Next = NULL;
}

int Length(struct LNode *L) {
    struct LNode *p;
    int cnt = 0;
    p = L;
    while (p) {
        p = p->Next;
        cnt++;
    }
    return cnt;
}

int FindKth(int K, struct LNode *L) {
    struct LNode *p;
    int cnt;
    p = L;
    cnt = 1;
    while (p && cnt < K) {
        p = p->Next;
        cnt++;
    }
    if (cnt == K && p) {
        return p->Data;
    } else {
        return (-1);
    }
}

struct LNode *Find(int X, struct LNode *L) {
    struct LNode *p;
    p = L;
    while (p && p->Data != X) {
        p = p->Next;
    }
    return p;
}

void CreateFromHead(struct LNode *L) {
    struct LNode *S;
    int x;
    scanf("%d", &x);
    while (x != -1) {
        S = (struct LNode *) malloc(sizeof(struct LNode));
        S->Data = x;
        S->Next = L->Next;
        L->Next = S;
        scanf("%d", &x);
    }
}

void CreateFromTail(struct LNode *L) {
    struct LNode *S;
    struct LNode *P;
    int x;
    P = L;
    scanf("%d", &x);
    while (x != -1) {
        S = (struct LNode *) malloc(sizeof(struct LNode));
        S->Data = x;
        P->Next = S;
        P = S;
        scanf("%d", &x);
    }
    P->Next = NULL;
}

int main() {
    struct LNode *F;
    InitList(F);
    CreateFromHead(F);
    printf("%d", Length(F));
}