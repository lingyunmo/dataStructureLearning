#include <iostream>
#include<stack>
#include "vector"

using namespace std;

template<class T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left, *right;

    BinaryTreeNode() {};

    ~BinaryTreeNode() {};

    BinaryTreeNode(T x) {
        data = x;
        left = NULL;
        right = nullptr;
    }

    void postOrder(BinaryTreeNode<T> *root);
};

template<class T>
void BinaryTreeNode<T>::postOrder(BinaryTreeNode<T> *root) {
    if (root == nullptr) {
        return;
    }
    if(root->left!= nullptr||root->right!= nullptr){
        cout << "(";
    }
    postOrder(root->left);
    cout << root->data;
    postOrder(root->right);
    if(root->left!= nullptr||root->right!= nullptr){
        cout << ")";
    }
}

int main() {
    vector<char> v;
    char *c = new char[1000];
    cin >> c;
    for (int i = 0; c[i] != '\0'; i++) {
        v.push_back(c[i]);
    }
    stack<BinaryTreeNode<char> *> s;
    for (vector<char>::iterator it = v.begin(); it != v.end(); it++) {
        if (*it == '+' || *it == '-' || *it == '*' || *it == '/') {
            BinaryTreeNode<char> *node = new BinaryTreeNode<char>(*it);
            node->right = s.top();
            s.pop();
            node->left = s.top();
            s.pop();
            s.push(node);
        } else {
            BinaryTreeNode<char> *node = new BinaryTreeNode<char>(*it);
            s.push(node);
        }
    }
    BinaryTreeNode<char> *root = s.top();
    root->postOrder(root);
}