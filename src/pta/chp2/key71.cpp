#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int *a;
    a=new int [n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int m;
    scanf("%d",&m);
    int *b;
    b=new int [m];
    for(int i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
    int *c;
    c=new int [m+n];
    for(int i=0;i<n;i++){
        c[i]=a[i];
    }
    for(int i=n;i<n+m;i++){
        c[i]=b[i-n];
    }
    sort(c,c+m+n);
    for(int i=0;i<n+m;i++){
        printf("%d ",c[i]);
    }
    return 0;
}