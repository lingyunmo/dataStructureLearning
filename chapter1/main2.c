#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // 定义要排序的数组大小

void bubbleSort(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[SIZE];
    int i;
    srand((unsigned)time(NULL)); // 设置随机数种子

    // 随机生成数组元素
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100; // 生成0~99之间的随机数
    }

    // 输出排序前的数组
    printf("排序前的数组：\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 冒泡排序
    bubbleSort(arr, SIZE);

    // 输出排序后的数组
    printf("排序后的数组：\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
