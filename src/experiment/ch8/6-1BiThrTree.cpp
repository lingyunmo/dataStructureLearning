#include <iostream>

using namespace std;

typedef char ElementType;

class BiThrNode {
public:
    ElementType data;
    BiThrNode *lChild, *rChild;
    int lTag, rTag;

    BiThrNode(ElementType data) : data(data), lChild(NULL), rChild(NULL), lTag(1), rTag(1) {}
};

BiThrNode *pre = NULL;

BiThrNode *CreatTree() {
    BiThrNode *root = NULL;
    ElementType data;
    cin >> data;
    if (data == '@')
        root = NULL;
    else {
        root = new BiThrNode(data);
        root->lChild = CreatTree();
        root->rChild = CreatTree();
    }
    return root;
}

void Inthread(BiThrNode *root) {
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

BiThrNode *IsFirst(BiThrNode *root) {
    BiThrNode *p = root;
    if (p) {
        while (p->lTag == 0)
            p = p->lChild;
        return p;
    } else
        return NULL;
}

BiThrNode *IsNext(BiThrNode *root) {
    BiThrNode *p = root;
    if (p->rTag == 0) {
        for (p = root->rChild; p->lTag == 0; p = p->lChild);
        return p;
    } else
        return p->rChild;
}

void TInOrder(BiThrNode *Bt) {
    BiThrNode *p = Bt;
    if (p) {
        p = IsFirst(Bt);
        while (p) {
            cout << p->data << "  " << p->lTag << "  " << p->rTag << endl;
            p = IsNext(p);
        }
    }
}

int main() {
    BiThrNode *root = CreatTree();
    Inthread(root);
    TInOrder(root);
    return 0;
}
