#include "iostream"
#include "vector"
#include "array"

using namespace std;

template<class T>
class stack {
public:
    vector<T> v;

    void push(T x) {
        v.push_back(x);
    }

    void pop1() {
        v.pop_back();
    }

    void pop2() {
        v.erase(v.end() - 1);
    }
};

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

    void preOrder(BinaryTreeNode<T> *root);

    void inOrder(BinaryTreeNode<T> *root);

    void postOrder(BinaryTreeNode<T> *root);
};

//前序遍历
template<class T>
void BinaryTreeNode<T>::preOrder(BinaryTreeNode<T> *root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << endl;
    preOrder(root->left);
    preOrder(root->right);
}

//中序遍历
template<class T>
void BinaryTreeNode<T>::inOrder(BinaryTreeNode<T> *root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left);
    cout << root->data << endl;
    inOrder(root->right);
}

//后序遍历
template<class T>
void BinaryTreeNode<T>::postOrder(BinaryTreeNode<T> *root) {
    if (root == nullptr) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << endl;
}

int main() {
    //自建stack演示
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop1();
    s.pop2();
    for (vector<int>::iterator it = s.v.begin(); it != s.v.end(); it++) {
        cout << *it << endl;
    }

    for (int &it: s.v) {
        cout << it << endl;
    }

    //二叉树演示
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);
    root->left->left = new BinaryTreeNode<int>(4);
    root->left->right = new BinaryTreeNode<int>(5);

    //二叉树栈演示
    stack<BinaryTreeNode<int> *> s1;
    s1.push(root);
    while (!s1.v.empty()) {
        BinaryTreeNode<int> *node = s1.v.back();
        s1.pop1();
        cout << node->data << endl;
        if (node->right != NULL) {
            s1.push(node->right);
        }
        if (node->left != NULL) {
            s1.push(node->left);
        }
    }

    //array演示

}