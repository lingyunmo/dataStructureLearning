//设待排序的排序码为(12，2，16，30，28，10，16，20，6，18),写出采用归并排序法进行排序的每趟的排序结果。
#include<stdio.h>
int main(){
    int a[10] = {12,2,16,30,28,10,16,20,6,18};
    int b[10] = {0};
    int i,j,k;
    int m = 1;
    while(m < 10){
        i = 0;
        j = i + m;
        k = i;
        while(i < 10){
            while(i < m && j < 10){
                if(a[i] < a[j]){
                    b[k] = a[i];
                    i++;
                }else{
                    b[k] = a[j];
                    j++;
                }
                k++;
            }
            while(i < m){
                b[k] = a[i];
                i++;
                k++;
            }
            while(j < 10){
                b[k] = a[j];
                j++;
                k++;
            }
            i = j;
            j = i + m;
        }
        for(i = 0;i < 10;i++){
            a[i] = b[i];
        }
        m *= 2;
    }
    for(i = 0;i < 10;i++){
        printf("%d ",a[i]);
    }
    return 0;
}