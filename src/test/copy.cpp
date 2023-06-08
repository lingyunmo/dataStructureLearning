#include<iostream>
#include<vector>
#include<stack>

using namespace std;

template<class T>
void abc(T &a, T b, T c) {
    a += b;
    a += c;
};

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    abc(x, y, z);
    cout << x;
}