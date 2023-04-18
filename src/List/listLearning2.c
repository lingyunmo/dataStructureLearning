#include <stdbool.h>
#include "stdio.h"
#include "stdlib.h"

#define ElementType int
#define ERROR (-1)
typedef struct LNode *PtrToLNode;

struct LNode {
    int Data;
    struct LNode *Next;
};
typedef struct LNode *Position;
typedef struct LNode *List;

void InitList(struct LNode *L) {
    L = (List) malloc(sizeof(struct LNode));
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

/*
int Find(ElementType X, List L) {
    Position p;
    int cnt;
    p = L;
    cnt = 1;
    while (p && p->Data != X) {
        p = p->Next;
        cnt++;
    }
    if (p) {
        return cnt;
    } else {
        return ERROR;
    }
}
*/

struct LNode * Find(int X, struct LNode *L) {
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
        S = (List) malloc(sizeof(struct LNode));
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
        S = (List) malloc(sizeof(struct LNode));
        S->Data = x;
        P->Next = S;
        P = S;
        scanf("%d", &x);
    }
    P->Next = NULL;
}

/*
void Insert(ElementType X, int i, List L) {
    Position p, s;
    int cnt;
    p = L;
    cnt = 1;
    while (p && cnt < i) {
        p = p->Next;
        cnt++;
    }
    if (cnt == i && p) {
        s = (List) malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = p->Next;
        p->Next = s;
    } else {
        printf("插入位置不合法");
    }
}
*/

/*没有头节点的插入
List Insert(List L, ElementType X, int i) {
    Position tmp, pre;
    tmp = (Position) malloc(sizeof(struct LNode));
    tmp->Data = X;
    if (i == 1) {
        tmp->Next = L;
        return tmp;
    } else {
        int cnt = 1;
        pre = L;
        while (pre && cnt < i - 1) {
            pre = pre->Next;
            cnt++;
        }
        if (pre == NULL || cnt != i - 1) {
            printf("插入位置参数错误\n");
            free(tmp);
            return (List) ERROR;
        } else {
            tmp->Next = pre->Next;
            pre->Next = tmp;
            return L;
        }
    }
}
*/

/*
void deleted(int i, List L) {
    Position p, s;
    int cnt;
    p = L;
    cnt = 1;
    while (p && cnt < i) {
        p = p->Next;
        cnt++;
    }
    if (cnt == i && p) {
        s = p->Next;
        p->Next = s->Next;
        free(s);
    } else {
        printf("删除位置不合法");
    }
}
*/

bool Delete(struct LNode *L, int i){
    struct LNode *tmp;
    struct LNode *pre;
    int cnt =0;
}

int main() {

}