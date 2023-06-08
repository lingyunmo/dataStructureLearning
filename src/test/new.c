#include<stdio.h>
#include<stdlib.h>

#define N 12
typedef struct LNode *PtrToLNode;
struct LNode {
    int array[N];
    int Last;
};
typedef PtrToLNode List;

int BinarySearch(List Tbl, int a) {
    int low, high, mid;
    low = 0;
    high = Tbl->Last - 1;
    int i = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        i++;
        if (a == Tbl->array[mid]) {
            printf("found! %d %d\n", mid, i);
            return 0;
        } else if (a < Tbl->array[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    printf("not found!\n");
    return 0;
}

int main() {

    int a;
    List Tbl;

    scanf("%d", &a);
    Tbl = (List) malloc(sizeof(struct LNode));

    Tbl->array[0] = 1;
    Tbl->array[1] = 2;
    Tbl->array[2] = 5;
    Tbl->array[3] = 6;
    Tbl->array[4] = 7;
    Tbl->array[5] = 12;
    Tbl->array[6] = 15;
    Tbl->array[7] = 67;
    Tbl->array[8] = 88;
    Tbl->array[9] = 99;
    Tbl->array[10] = 100;
    Tbl->array[11] = 200;

    Tbl->Last = 12;
    BinarySearch(Tbl, a);
    return 0;
}