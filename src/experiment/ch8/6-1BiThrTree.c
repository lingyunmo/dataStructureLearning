#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct BiNode {
    ElementType data;
    struct BiNode *lChild, *rChild;
    int lTag, rTag;
} BiThrNode, *BiThrTree;
BiThrTree pre = NULL;

BiThrTree CreatTree() {
    BiThrTree root = NULL;
    ElementType data;
    scanf("%c", &data);
    if (data == '@')
        root = NULL;
    else {
        root = (BiThrTree) malloc(sizeof(BiThrNode));
        root->data = data;
        root->lTag = 1;
        root->rTag = 1;
        root->lChild = CreatTree();
        root->rChild = CreatTree();
    }
    return root;
}

void Inthread(BiThrTree root) {
    if (root) {
        Inthread(root->lChild);
        if (root->lChild == NULL) {
            root->lChild = pre;
        } else
            root->lTag = 0;
        if (pre != NULL && pre->rChild == NULL) {
            pre->rChild = root;
        } else if (pre != NULL && pre->rChild != NULL)
            pre->rTag = 0;
        pre = root;
        Inthread(root->rChild);
    }
}

BiThrTree IsFirst(BiThrTree root) {
    BiThrTree p = root;
    if (p) {
        while (p->lTag == 0)
            p = p->lChild;
        return p;
    } else
        return NULL;
}

BiThrTree IsNext(BiThrTree root) {
    BiThrTree p = root;
    if (p->rTag == 0) {
        for (p = root->rChild; p->lTag == 0; p = p->lChild);
        return p;
    } else
        return p->rChild;
}

void TInOrder(BiThrTree Bt) {
    BiThrTree p = Bt;
    if (p) {
        p = IsFirst(Bt);
        while (p) {
            printf("%c  %d  %d\n", p->data, p->lTag, p->rTag);
            p = IsNext(p);
        }
    }
}
int main() {
    BiThrTree root = CreatTree();
    Inthread(root);
    TInOrder(root);
    return 0;
}
