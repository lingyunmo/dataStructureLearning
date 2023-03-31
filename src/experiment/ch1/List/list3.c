#include <stdio.h>
#include <stdlib.h>

struct link {
    int data;
    struct link *next;
};

struct link *AppendNode(struct link *head, int data);

void DisplyNode(struct link *head);

void DeleteMemory(struct link *head);

struct link *DeleteNode(struct link *head, int data);

struct link *InsertNode(struct link *head, int nodeData);

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
    scanf("%d", &data);
    head = InsertNode(head, data);
    DisplyNode(head);        /* 显示当前链表中的各节点信息 */
    DeleteMemory(head);           /* 释放所有动态分配的内存 */
    return 0;
}

struct link *AppendNode(struct link *head, int data) {
    struct link *p = NULL, *q = head;
    p = (struct link *) malloc(sizeof(struct link));
    if (p == NULL) {
        exit(0);
    }
    if (head == NULL) {
        head = p;
    } else {
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }
    p->data = data;
    p->next = NULL;
    return head;
}

void DisplyNode(struct link *head) {
    //遍历显示链表函数
    //输出单向链表中的每一项，每个数之间以->连接
    struct link *p;
    p = head;
    while (p != NULL) {
        if (p->next == NULL)
            printf("%d", p->data);
        else
            printf("%d->", p->data);
        p = p->next;
    }
}

void DeleteMemory(struct link *head) {
    //删除链表内存函数
    struct link *p, *q;
    p = head;
    while (p != NULL) {
        q = p;
        p = p->next;
        free(q);
    }
}

struct link *DeleteNode(struct link *head, int data) {
    //head 是链表头节点的指针
    //data是要删除的节点的数值。
    //函数返回删除相应节点后，头节点的指针。
    printf("\n");
    struct link *pr = head;
    if (head == NULL) {
        return (head);
    }
    int i = 2;
    while (i) {
        struct link *p = head;
        while (p->data != data && p->next != NULL) {
            pr = p;
            p = p->next;
        }
        if (p->data == data) {
            if (p == head) {
                head = p->next;
            } else {
                pr->next = p->next;
            }
            free(p);
        }
        i--;
    }
    return head;
}

struct link *InsertNode(struct link *head, int data) {
    //head 是链表头节点的指针
    //data是要插入的节点的数值。
    //函数返回插入相应节点后，头节点的指针。
    printf("\n");
    struct link *p = head, *pr = head, *temp = NULL;
    p = (struct link *) malloc(sizeof(struct link));

    p->next = NULL;
    p->data = data;
    if (head == NULL) {
        head = p;
    } else {
        while (pr->data < data && pr->next != NULL) {
            temp = pr;
            pr = pr->next;
        }
        if (pr->data >= data) {
            if (pr == head) {
                p->next = head;
                head = p;
            } else {
                pr = temp;
                p->next = pr->next;
                pr->next = p;
            }
        } else {
            pr->next = p;
        }
    }
    return head;
}
