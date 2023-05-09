#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

void insert(Node** root, int val) {
    if (*root == NULL) {
        *root = (Node*)malloc(sizeof(Node));
        (*root)->val = val;
        (*root)->left = (*root)->right = NULL;
        return;
    }
    if (val < (*root)->val) insert(&(*root)->left, val);
    else insert(&(*root)->right, val);
}

void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int val;
    Node* root = NULL;
    while (scanf("%d", &val) != EOF && val != 0) {
        insert(&root, val);
    }
    preorder(root);
    printf("\n");
    return 0;
}
