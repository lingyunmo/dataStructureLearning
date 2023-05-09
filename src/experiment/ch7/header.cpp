#include <iostream>
#include <vector>

using namespace std;

//pre前序遍历 post后序遍历 origin原始序列
vector<int> pre, post, origin;

//判断是否是镜像树
bool isMirror;

//获取后序遍历序列 参数root:根结点的索引 tail:尾节点的索引
void getPost(int root, int tail) {
    //根节点是否大于尾节点:是->返回
    if (root > tail)
        return;
    int i = root + 1, j = tail;
    //判断树是否为镜像树
    if (!isMirror) {
        //不是镜像树
        //从i->tail,根节点的值大于当前节点的值->i+1
        while (i <= tail && origin[root] > origin[i])
            i++;
        //从j->root,根节点的值小于等于当前节点的值->j-1
        while (j > root && origin[root] <= origin[j])
            j--;
    } else {
        //是镜像树
        //从i->tail,根节点的值小于等于当前节点的值->i+1
        while (i <= tail && origin[root] <= origin[i])
            i++;
        //从j->root,根节点的值大于当前节点的值->j-1
        while (j > root && origin[root] > origin[j])
            j--;
    }
    //i-j!=1是否成立，如果成立，则返回
    if (i - j != 1)
        return;
    getPost(root + 1, j);
    getPost(i, tail);
    //将根节点的值添加到后序遍历序列中
    post.push_back(origin[root]);
}

int main() {
    int n;
    scanf("%d", &n);
    //设置原始序列和前序遍历的长度
    origin.resize(n);
    pre.resize(n);
    //读入数据到origin中
    for (int i = 0; i < n; i++) {
        scanf("%d", &origin[i]);
        pre[i] = origin[i];
    }
    //获取后序遍历序列,参数为根节点和尾节点的索引
    getPost(0, n - 1);
    //检查后序遍历序列的大小
    if (post.size() != n) {
        //不等于:isMirror->true
        isMirror = true;
        //清空后序遍历序列
        post.clear();
        //并调用getPost获取后序遍历序列
        getPost(0, n - 1);
    }
    //检查后序遍历序列的大小是否等于n
    if (post.size() == n) {
        printf("YES\n%d", post[0]);
        for (int i = 1; i < n; i++)
            printf(" %d", post[i]);
    } else {
        printf("NO");
    }
    return 0;
}