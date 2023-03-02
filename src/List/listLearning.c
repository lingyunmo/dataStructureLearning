//顺序表的实现
#include "stdio.h"
#include "stdlib.h"

#define ElementType int
#define MAXSIZE 10
typedef int Position;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last;
};
typedef PtrToLNode List;

int main() {

}