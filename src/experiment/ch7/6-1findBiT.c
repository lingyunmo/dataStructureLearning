#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct BSTNode {
    ElemType data;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

BSTree CreateBST();/* 二叉排序树创建，由裁判实现，细节不表 */
BSTree SearchBST(BSTree T, ElemType e);

void Inorder(BSTree T);/* 中序遍历，由裁判实现，细节不表 */

int main() {
    BSTree T, result;
    ElemType n, e;
    T = CreateBST();
    printf("Inorder:");
    Inorder(T);
    printf("\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &e);
        result = SearchBST(T, e);
        if (result) printf("%d is found\n", result->data);
        else printf("%d is not found\n", e);
    }
    return 0;
}

/* 你的代码将被嵌在这里 */

//根节点T和要查找的元素e
BSTree SearchBST(BSTree T, ElemType e) {
    //如果根节点为空或者根节点的数据域等于要查找的元素，那么返回根节点
    if (T == NULL || T->data == e) {
        return T;
    }
    //如果根节点的数据域小于要查找的元素，那么在右子树中继续查找
    if (T->data < e) {
        return SearchBST(T->rchild, e);
    }
    //否则，在左子树中继续查找
    return SearchBST(T->lchild, e);
}