#include<stdio.h>
#include<stdlib.h>

#define ElementType int

struct LNode {
    ElementType data;
    struct LNode *next;
};

void insertWithSort(struct LNode *listIn, ElementType x);

int main() {
    ElementType a = 1, b = 3, c = 5, d = 7,e;
    scanf("%d", &e);
    struct LNode *listOut = (struct LNode *) malloc(sizeof(struct LNode));
    listOut->data = a;
    listOut->next = NULL;
    insertWithSort(listOut, a);
    insertWithSort(listOut, b);
    insertWithSort(listOut, c);
    insertWithSort(listOut, d);
    insertWithSort(listOut, e);

}

//升序排列
void insertWithSort(struct LNode *listIn, ElementType x) {
    struct LNode *p = listIn;
    struct LNode *s = (struct LNode *) malloc(sizeof(struct LNode));
    s->data = x;
    if (x < p->data) {
        s->next = p;
        listIn = s;
        return;
    }
    while (p->next != NULL) {
        if (x < p->next->data) {
            s->next = p->next;
            p->next = s;
            return;
        }
        p = p->next;
    }
}