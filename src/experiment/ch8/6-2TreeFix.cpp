#include<iostream>

using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;
};

void insert_Node(Node *&root, int n) {
    if (root == NULL) {
        root = new Node();
        root->data = n;
        root->left = NULL;
        root->right = NULL;
    } else {
        if (n <= root->data) {
            insert_Node(root->left, n);
        } else {
            insert_Node(root->right, n);
        }
    }
}

void preOder(Node *root) {
    if (root == NULL) {
        return;
    } else {
        cout << root->data << " ";
        preOder(root->left);
        preOder(root->right);
    }
}

int main() {
    Node *root = NULL;
    int n;
    cin >> n;
    while (n != 0) {
        insert_Node(root, n);
        cin >> n;
    }
    preOder(root);
    return 0;
}
