#include  "stdio.h"
#include  "stdlib.h"
/**********************************/
/*顺序表的头文件，文件名sequlist.h*/
/**********************************/
#define MAXSIZE 100
typedef int datatype;
typedef struct{
    datatype a[MAXSIZE];
    int size;
}sequence_list;

/**********************************/
/*函数名称：initseqlist()         */
/*函数功能：初始化顺序表          */
/**********************************/
void initseqlist(sequence_list *L)
{    L->size=0;
}
/**********************************/
/*函数名称：input()               */
/*函数功能：输入顺序表            */
/**********************************/
void input(sequence_list *L)
{  datatype x;
    initseqlist(L);
    printf("请输入一组数据，以0做为结束符：\n");
    scanf("%d",&x);
    while (x)
    {    L->a[L->size++]=x;
        scanf("%d",&x);
    }
}
/**********************************/
/*函数名称：print()               */
/*函数功能：输出顺序表            */
/**********************************/
void print(sequence_list L)
{   int i;
    for (i=0;i<L.size;i++)
    {    printf("%5d",L.a[i]);
        if ((i+1)%10==0) printf("\n");
    }
    printf("\n");
}

/*请将本函数补充完整，并进行测试*/
int countx(sequence_list L, datatype x) {
    int count = 0;
    for (int i = 0; i < L.size; i++) {
        if (L.a[i] == x) {
            count++;
        }
    }
    return count;
}

void main()
{
    sequence_list L;
    datatype x;            /*定义顺序表*/
    input(&L);            /*输入测试用例*/
    print(L);          /*输出原表*/
    printf("请输入待统计的元素值：");
    scanf("%d",&x);
    printf("该顺序表中值为%d的元素个数为：",x);
    printf("%d",countx(L,x));
}