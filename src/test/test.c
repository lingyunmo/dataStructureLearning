#include <stdio.h>
#include <stdlib.h>

struct link {
    int data;
    struct link *next;
};
typedef struct link *PtrToLNode;
typedef struct link *Position;
typedef PtrToLNode Position;
typedef PtrToLNode List;

struct link *AppendNode(struct link *head, int data);

void DisplyNode(struct link *head);

void DeleteMemory(struct link *head);

int main() {
    int data = 0;
    struct link *head = NULL;      /* 链表头指针 */
    while (1) {
        scanf("%d", &data);
        if (data == -1)
            break;

        head = AppendNode(head, data);/* 向head为头指针的链表末尾添加节点 */
    }
    DisplyNode(head);        /* 显示当前链表中的各节点信息 */
    DeleteMemory(head);           /* 释放所有动态分配的内存 */
    return 0;
}

struct link *AppendNode(struct link *head, int data) {
    if (head == NULL) {
        struct link *s = (struct link *) malloc(sizeof(struct link));
        s->next = NULL;
        head = s;
    }
    List p;
    p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    struct link *c = (struct link *) malloc(sizeof(struct link));
    c->data = data;
    c->next = p->next;
    p->next = c;
    return head;

}

void DisplyNode(struct link *head) {
    struct link *q;
    q = head->next;
    while (q != NULL) {
        if (q->next == NULL)
            printf("%d", q->data);
        else {
            printf("%d->", q->data);
        }
        q = q->next;
    }
}

void DeleteMemory(struct link *head) {
    Position tmp, pre;

    tmp = head;
    while (tmp != NULL) {
        pre = tmp;
        tmp = pre->next;
        free(pre);
    }
}
