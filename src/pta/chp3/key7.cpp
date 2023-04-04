#include<iostream>
#include<cstdio>
#include<stack>
#include<string>

using namespace std;

stack<int> sta;
string str;

int main() {
    int i = 0;
    getline(cin, str);
    int str_count = (int) str.length();
    int pri_count = 0;
    int flag = 0;
    while (pri_count < str_count) {
        char x1 = str[pri_count++];
        int a;
        if (x1 >= '0' && x1 <= '9') {
            char x2 = str[pri_count++];
            int m = 10;
            a = x1 - '0';
            if (x2 >= '0' && x2 <= '9') {
                while (x2 >= '0' && x2 <= '9') {
                    a = a * 10 + (x2 - '0');
                    x2 = str[pri_count++];
                }
            }
            if (flag) a = a * (-1);
            flag = 0;
            sta.push(a);
        } else if (x1 == ' ') {
            continue;
        } else if (x1 == '-') {
            if (str[pri_count] >= '0' && str[pri_count] <= '9') {
                flag = 1;
                continue;
            } else {
                int n1 = sta.top();
                sta.pop();
                int n2 = sta.top();
                sta.pop();
                int n3 = n2 - n1;
                sta.push(n3);
            }
        } else {
            int n1 = sta.top();
            sta.pop();
            int n2 = sta.top();
            sta.pop();
            int n3;
            switch (x1) {
                case '+':
                    n3 = n1 + n2;
                    break;
                case '*':
                    n3 = n1 * n2;
                    break;
                case '/':
                    n3 = n2 / n1;
                    break;
                default:
                    break;
            }
            sta.push(n3);
        }
    }
    printf("%d\n", sta.top());
    return 0;
}
