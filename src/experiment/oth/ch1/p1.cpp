#include <iostream>
#include <cstdio>

using namespace std;

typedef struct Node {     //模拟链表结点
    int address;
    int data;
    int next_address;
} List;

void Print(List p[], int n);   //打印链表函数
int Creat_and_sort(List p[], int k, int first);  //创建链表并按顺序排好
void fun(List p1[], List p2[], int n);   //主功能函数，即去重函数
int main() {
    int first_address, k;   //记录第一行输入，即链表首地址与节点个数
    cin >> first_address >> k;
    List L1[100001];  //存放输入的链表
    int Count = 0;
    Count = Creat_and_sort(L1, k, first_address);  //创建并排序
    List L2[100001];  //存放删除的结点
    fun(L1, L2, Count); //去重并打印
    return 0;
}

int Creat_and_sort(List p[], int k, int first) {
    List tmp[k];   //tmp用来暂时存放按顺序排好的链表
    for (int i = 0; i < k; i++) {
        scanf("%d%d%d", &p[i].address, &p[i].data, &p[i].next_address);
        if (p[i].address == first) {
            tmp[0] = p[i];  //tmp[0]存放第一个节点
        }
    }
    int Count = 1; //记录链表结点个数（避免输入的有多余结点）
    while (Count < k) {  //两层循环来排序
        for (int i = 0; i < k; i++) {
            if (p[i].address == tmp[Count - 1].next_address) { //如果下一个结点的地址与p里面第i个的地址相同，将p[i]放到tmp
                tmp[Count] = p[i];
                Count++;
            }
        }
        if (tmp[Count - 1].next_address == -1)
            break;  //如果最后一个结点的next为-1就停止循环
    }
    for (int i = 0; i < Count; i++) {
        p[i] = tmp[i];  //将tmp的Count个结点赋给p
    }
    return Count;  //返回链表的结点数
}

void Print(List p[], int n) {
    int i;
    if (n == 0) return;
    for (i = 0; i < n; i++) {
        if (i < n - 1)
            printf("%05d %d %05d\n", p[i].address, p[i].data, p[i].next_address);
        else if (i == n - 1)
            printf("%05d %d %d\n", p[i].address, p[i].data, p[i].next_address);
    }
}

void fun(List p1[], List p2[], int n) { //去重函数
    int key[n];  //用来记录存在的结点的键值
    List tmp[n];  //存放没有被删除的结点
    int Count_p2 = 0, Count_tmp = 1;
    int k = 1;
    key[0] = p1[0].data; //第一个结点肯定不会删除
    tmp[0] = p1[0];
    for (int i = 1; i < n; i++) {  //遍历链表
        int flag = 0;  //记录是否有结点被删除
        for (int j = 0; j < k; j++) { //遍历key检查键值有无重复
            if (p1[i].data == key[j] || p1[i].data == -key[j]) {  //如果重复
                p2[Count_p2++] = p1[i];  //p1[i]被删除，存放到p2中
                if (Count_p2 > 1)
                    p2[Count_p2 - 2].next_address = p2[Count_p2 - 1].address; //更改被删除结点的地址连接
                flag = 1;
                break;
            }
        }
        if (!flag) {  //如果该结点没有被删除
            tmp[Count_tmp++] = p1[i]; //将该结点存放到tmp中
            tmp[Count_tmp - 2].next_address = tmp[Count_tmp - 1].address; //更改连接关系
            key[k++] = p1[i].data;  //将该键值存起来
        }
    }
    tmp[Count_tmp - 1].next_address = -1;  //更改最后一个结点的next
    p2[Count_p2 - 1].next_address = -1;
    Print(tmp, Count_tmp);  //打印两个链表
    Print(p2, Count_p2);
}