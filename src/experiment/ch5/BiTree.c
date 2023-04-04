#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct BiTNode {
    ElementType data;
    struct BiTNode *leftChild;
    struct BiTNode *rightChild;
} BiTNode, *BiTree;

BiTree creatBiTree() {
    int c;
    BiTree T;
    scanf("%d", &c);
    if (c == 0) {
        return NULL;
    } else {
        T = (BiTNode *) malloc(sizeof(BiTNode));
        T->data = c;
        T->leftChild = creatBiTree();
        T->rightChild = creatBiTree();
    }
    return T;
}

void dataLeftRight(BiTree T) {
    if (T) {
        printf("%d ", T->data);
        dataLeftRight(T->leftChild);
        dataLeftRight(T->rightChild);
    }
}

void leftDataRight(BiTree T) {
    if (T) {
        leftDataRight(T->leftChild);
        printf("%d ", T->data);
        leftDataRight(T->rightChild);
    }
}

void leftRightData(BiTree T) {
    if (T) {
        leftRightData(T->leftChild);
        leftRightData(T->rightChild);
        printf("%d ", T->data);
    }
}

int main() {
    BiTree T = creatBiTree();
    dataLeftRight(T);
    printf("\n");
    leftDataRight(T);
    printf("\n");
    leftRightData(T);
    printf("\n");
    return 0;
}