#include<iostream>

using namespace std;
#define ERROR 1
typedef int QElemType;
typedef struct QNode {
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

void InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = new QNode;
    Q.front->next = NULL;
}

void EnQueue(LinkQueue &Q, QElemType e) {
    QueuePtr p;
    p = new QNode;
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
}

int DeQueue(LinkQueue &Q, QElemType &e) {
    QueuePtr p;
    if (Q.front == Q.rear) {
        return ERROR;
    }
    p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) {
        Q.rear = Q.front;
    }
    delete p;
}

void print(int c[], int n) {
    cout << c[0];
    for (int i = 1; i < n; i++)
        cout << " " << c[i];
}

int main() {
    int a[1000], n;
    int j = 0;
    QElemType e;
    cin >> n;
    int c[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    LinkQueue A, B;
    InitQueue(A);
    InitQueue(B);

    int i = 0;
    while (i < n) {
        e = a[i];
        if (e % 2 != 0) {
            EnQueue(A, e);
        } else {
            EnQueue(B, e);
        }
        i++;
    }

    while (A.rear != A.front && B.rear != B.front) {
        DeQueue(A, e);
        c[j++] = e;
        DeQueue(A, e);
        c[j++] = e;
        DeQueue(B, e);
        c[j++] = e;
    }
    while (A.rear != A.front) {
        DeQueue(A, e);
        c[j++] = e;
    }
    while (B.rear != B.front) {
        DeQueue(B, e);
        c[j++] = e;
    }
    print(c, n);
    return 0;
}