#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct BSTNode {
    ElemType data;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

void insert(BSTree &T, ElemType x) {
    if (T == NULL) {
        T = new BSTNode;
        T->data = x;
        T->lchild = T->rchild = NULL;
    } else if (x < T->data)
        insert(T->lchild, x);
    else
        insert(T->rchild, x);
}

void search(BSTree T, ElemType x) {
    if (T == NULL)
        cout << "NOT FOUND!";
    else if (T->data == x) {
        cout << "have found! ";
        cout << "lchild:";
        if (T->lchild != NULL)
            cout << T->lchild->data << " ";
        else
            cout << "NULL ";
        cout << "rchild:";
        if (T->rchild != NULL)
            cout << T->rchild->data;
        else
            cout << "NULL";
    } else if (x < T->data)
        search(T->lchild, x);
    else
        search(T->rchild, x);
}

int main() {
    BSTree T = NULL;
    ElemType x;
    cin >> x;
    while (x != -1) {
        insert(T, x);
        cin >> x;
    }
    cin >> x;
    search(T, x);
    return 0;
}