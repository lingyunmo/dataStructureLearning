#include <stdbool.h>
#include "stdio.h"
#include "stdlib.h"

#define ElementType int
#define MAXSIZE 10
#define ERROR (-1)
typedef int Position;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last;
};
typedef PtrToLNode List;

List MakeEmpty() {
    List L;
    L = (List) malloc(sizeof(struct LNode));
    L->Last = -1;
    return L;
}

Position Find(List L, ElementType X) {
    Position i = 0;
    while (i <= L->Last && L->Data[i] != X) {
        i++;
    }
    if (i > L->Last) {
        return ERROR;
    } else {
        return i;
    }
}

bool Insert(List L, ElementType X, int i) {
    Position j;
    if (L->Last == MAXSIZE - 1) {
        printf("表满");
        return false;
    }
    if (i < 0 || i > L->Last + 2) {
        printf("位置不合法");
        return false;
    }
    for (j = L->Last; j >= i - 1; j--) {
        L->Data[j + 1] = L->Data[j];
    }
    L->Data[i - 1] = X;
    L->Last++;
    return true;
}

bool Delete(List L, int i) {
    Position j;
    if (i < 1 || i > L->Last + 1) {
        printf("位置不合法");
        return false;
    }
    for (j = i; j <= L->Last; j++) {
        L->Data[j - 1] = L->Data[j];
    }
    L->Last--;
    return true;
}

//顺序表的实现
int main() {
    List L;
    L = MakeEmpty();
    Insert(L, 1, 1);
    Insert(L, 2, 2);
    Insert(L, 3, 3);
    Insert(L, 4, 4);
    Insert(L, 5, 5);
    Insert(L, 6, 6);
    Insert(L, 7, 7);
    Insert(L, 8, 8);
    Insert(L, 9, 9);
    printf("%d", L->Data[0]);
    printf("%d", L->Data[1]);
    printf("%d", L->Data[2]);
}