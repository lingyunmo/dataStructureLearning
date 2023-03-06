#include "stdio.h"
#include "stdlib.h"

#define ElementType int
typedef struct LNode *PtrToLNode;

struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

void InitList(List L) {
    L = (List) malloc(sizeof(struct LNode));
    L->Next = NULL;
}

int Length(List L) {
    Position p;
    int cnt = 0;
    p = L;
    while (p) {
        p = p->Next;
        cnt++;
    }
    return cnt;
}

void CreateFromHead(List L) {
    List S;
    int x;
    scanf("%d", &x);
    while (x != -1) {
        S = (List) malloc(sizeof(struct LNode));
        S->Data = x;
        S->Next = L->Next;
        L->Next = S;
        scanf("%d", &x);
    }
}

void CreateFromTail(List L) {
    List S, P;
    int x;
    P = L;
    scanf("%d", &x);
    while (x != -1) {
        S = (List) malloc(sizeof(struct LNode));
        S->Data = x;
        P->Next = S;
        P = S;
        scanf("%d", &x);
    }
    P->Next = NULL;
}

int main() {

}