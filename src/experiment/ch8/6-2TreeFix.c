#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

void insert_Node(Node **root, int n) {
    if (*root == NULL) {
        *root = (Node *) malloc(sizeof(Node));
        (*root)->data = n;
        (*root)->left = NULL;
        (*root)->right = NULL;
    } else {
        if (n <= (*root)->data) {
            insert_Node(&(*root)->left, n);
        } else {
            insert_Node(&(*root)->right, n);
        }
    }
}

void preOder(Node *root) {
    if (root == NULL) {
        return;
    } else {
        printf("%d ", root->data);
        preOder(root->left);
        preOder(root->right);
    }
}

int main() {
    Node *root = NULL;
    int n;
    scanf("%d", &n);
    while (n != 0) {
        insert_Node(&root, n);
        scanf("%d", &n);
    }
    preOder(root);
    return 0;
}
