#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *create_node(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void insert_node(Node *head, int data) {
    Node *node = create_node(data);
    node->next = head->next;
    head->next = node;
}

void print_list(Node *head) {
    for (Node *p = head->next; p; p = p->next) {
        if(p->next==NULL){
            printf("%d",p->data);
        }
        else{
            printf("%d ", p->data);
        }
    }
    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        Node *head = create_node(0);
        int data;
        while (scanf("%d", &data), data != -1) {
            insert_node(head, data);
        }
        print_list(head);
    }
    return 0;
}