#include<stdio.h>
#include<stdlib.h>

#define Maxsize 100

typedef int Elemtype;
typedef struct ListNode {
    Elemtype node[Maxsize];
    int last;
} ListNode, *List;

List input_node(int n);

int Found_order(List L, int x);

int Found_order_J(List L, int x);

int main() {
    List L;
    int n, x;
    printf("please input n:");
    scanf("%d", &n);
    L = input_node(n);
    printf("please input x:");
    scanf("%d", &x);
    n = Found_order_J(L, x);
    if (n == 0) printf("NOT Found!\n");
    else printf("This node is lies NO.%d\n", n);
    return 0;
}

List input_node(int n) {
    int i;
    List L;
    L = (List) malloc(sizeof(struct ListNode));
    for (i = 1; i <= n; i++) {
        printf("please input NO.%d:", i);
        scanf("%d", &L->node[i]);
    }
    L->last = i - 1;

    return L;
}

int Found_order(List L, int x) {
    int i;
    for (i = L->last; i >= 1; i--) {
        if (L->node[i] == x)
            return i;
    }
    if (i <= 0) return 0;
}

int Found_order_J(List L, int x) {
    int i;
    L->node[0] = x;

    for (i = L->last; i >= 0; i--) {
        if (L->node[i] == x)
            return i;
    }

}