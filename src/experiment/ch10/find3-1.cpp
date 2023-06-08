#include<iostream>
#include<cmath>

using namespace std;

// 定义一个函数，用于计算数组的高度
int height(int n) {
    // 初始化高度为0
    int h = 0;
    // 当n不为0时，将n除以2，并将高度加一
    while (n) {
        n = n / 2;
        h++;
    }
    // 返回高度
    return h;
}

// 定义主函数
int main() {
    // 声明一个整数变量，用于存储数组的长度
    int length;
    // 从用户读取输入，并存储在length中
    cin >> length;
    // 声明一个整数变量，用于存储数组的高度
    int h = height(length);
    // 声明一个整数变量，用于循环控制和计算
    int i;
    // 声明一个整数变量，用于存储查找成功的总查找长度
    int success = 0;
    // 使用一个for循环，计算除了最后一层之外的每一层的查找长度
    for (i = 1; i < h; i++) {
        // 将该层的层数和该层的节点数的乘积加到success中
        success += (i * pow(2, i - 1));
    }
    // 声明一个整数变量，用于存储最后一层的节点数
    int last = 0;
    // 使用一个for循环，计算最后一层的节点数
    for (i = pow(2, h - 1); i <= length; i++) {
        // 将last加一
        last++;
    }
    // 将last和h（最后一层的层数）的乘积加到success中
    success += (last * h);
    // 将success除以length，并以分数形式输出
    cout << success << "/" << length << endl;
    // 声明一个整数变量，用于存储查找失败的总查找长度
    int failure = last * 2 * (h + 1);
    // 声明一个整数变量，用于存储最后一层被占用的节点数
    int occupied = pow(2, h - 1) - last;
    // 将occupied和h的乘积加到failure中
    failure += (occupied * h);
    // 将failure除以length + 1，并以分数形式输出
    cout << failure << "/" << length + 1 << endl;
    // 返回0，表示正常结束 return
    return 0;
}
