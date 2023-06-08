#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct BSTNode {
    ElemType data;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

void insert(BSTree *T, ElemType x) {
    if (*T == NULL) {
        *T = (BSTNode *)malloc(sizeof(BSTNode));
        (*T)->data = x;
        (*T)->lchild = (*T)->rchild = NULL;
    } else if (x < (*T)->data)
        insert(&(*T)->lchild, x);
    else
        insert(&(*T)->rchild, x);
}

void search(BSTree T, ElemType x) {
    if (T == NULL)
        printf("NOT FOUND!");
    else if (T->data == x) {
        printf("have found! ");
        printf("lchild:");
        if (T->lchild != NULL)
            printf("%d ", T->lchild->data);
        else
            printf("NULL ");
        printf("rchild:");
        if (T->rchild != NULL)
            printf("%d", T->rchild->data);
        else
            printf("NULL");
    } else if (x < T->data)
        search(T->lchild, x);
    else
        search(T->rchild, x);
}

int main() {
    BSTree T = NULL;
    ElemType x;
    scanf("%d", &x);
    while (x != -1) {
        insert(&T, x);
        scanf("%d", &x);
    }
    scanf("%d", &x);
    search(T, x);
    return 0;
}