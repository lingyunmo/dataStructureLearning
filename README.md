# dataStructureLearning

learning data structure with C

![](https://img.shields.io/badge/DataStructure-C%2FC%2B%2B-yellowgreen?style=for-the-badge&logo=appveyor)

Hello～

Welcome to the space where I study data structure. Most of the code in this repository is based on C.

Have fun~

## learning for the basic code

### for example

```c
#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("Hello World!\n");//Here is the print code,just for a test.
    return 0;
}
```

### for the part of data structure

#### 1.QList

```c
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}Node;
int main(){
    Node *head,*p,*q,*t;
    int i,n,a;
    scanf("%d",&n);
    head=NULL;
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        p=(Node *)malloc(sizeof(Node));
        p->data=a;
        p->next=NULL;
        if(head==NULL){
            head=p;
        }else{
            q->next=p;
        }
        q=p;
    }
    scanf("%d",&a);
    t=head;
    while(t!=NULL){
        if(t->next==NULL){
            p=(Node *)malloc(sizeof(Node));
            p->data=a;
            p->next=NULL;
            t->next=p;
            break;
        }
        if(t->next->data>a){
            p=(Node *)malloc(sizeof(Node));
            p->data=a;
            p->next=t->next;
            t->next=p;
            break;
        }
        t=t->next;
    }
    t=head;
    while(t!=NULL){
        printf("%d ",t->data);
        t=t->next;
    }
    return 0;
}
```
## the rest of the code is still in the process of being updated

# have fun~