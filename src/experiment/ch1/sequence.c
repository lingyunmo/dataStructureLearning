#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define MAXSIZE 10
#define ERROR (-1)
typedef int Position;

struct LNode {
    ElementType Data[MAXSIZE];
    Position Last;
};
typedef struct LNode *List;

//顺序表的创建函数（初始化）
List MakeEmpty() {
    List L;
    L = (List) malloc(sizeof(struct LNode));
    L->Last = -1;
    return L;
}

//顺序表的查找按照序号查找
int GetElem(List L, int i) {
    if (i < 1 || i > L->Last + 1) {
        return ERROR;
    }
    return L->Data[i - 1];
}

//顺序表的查找按照内容查找
Position Find(List L, ElementType X) {
    Position i = 0;
    while (i <= L->Last && L->Data[i] != X) {
        i++;
    }
    if (i > L->Last) {
        return ERROR;
    } else {
        return i;
    }
}

//顺序表的插入
bool Insert(List L, ElementType X, int i) {
    Position j;
    if (L->Last == MAXSIZE - 1) {
        printf("表满");
        return false;
    }
    if (i < 1 || i > L->Last + 2) {
        printf("位置不合法");
        return false;
    }
    for (j = L->Last; j >= i - 1; j--) {
        L->Data[j + 1] = L->Data[j];
    }
    L->Data[i - 1] = X;
    L->Last++;
    return true;
}

bool Delete(List L, int i) {
    Position j;
    if (i < 1 || i > L->Last + 1) {
        printf("位置不合法");
        return false;
    }
    for (j = i; j <= L->Last; j++) {
        L->Data[j - 1] = L->Data[j];
    }
    L->Last--;
    return true;
}

//删除所有值大于min并且小于max的元素
//删除后表中元素保持顺序存储
//并且相对位置不能改变。
bool DeleteRange(List L, ElementType min, ElementType max) {
    Position i, j;
    for (i = 0; i <= L->Last; i++) {
        if (L->Data[i] > min && L->Data[i] < max) {
            for (j = i; j <= L->Last; j++) {
                L->Data[j] = L->Data[j + 1];
            }
            L->Last--;
            i--;
        }
    }
    return true;
}

//顺序表的实现
int main() {
    List L;
    L = MakeEmpty();
    for (int i = 1; i < MAXSIZE; ++i) {
        Insert(L, i, i);
        printf("%d \n", L->Data[i - 1]);
    }
    DeleteRange(L, 4, 7);
    for (int i = 0; i < L->Last; ++i) {
        printf("%d ", L->Data[i]);
    }
}