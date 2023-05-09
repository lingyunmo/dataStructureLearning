#include <iostream>

using namespace std;

struct Node {
public:
    int val;
    Node *left, *right;

    Node(int v) : val(v), left(NULL), right(NULL) {}
};

void insert(Node *&root, int val) {
    if (root == NULL) {
        root = new Node(val);
        return;
    }
    if (val < root->val)
        insert(root->left, val);
    else
        insert(root->right, val);
}

void preorder(Node *root) {
    if (root == NULL)
        return;
    cout << root->val << ' ';
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int val;
    Node *root = NULL;
    while (cin >> val && val != 0) {
        insert(root, val);
    }
    preorder(root);
    return 0;
}
