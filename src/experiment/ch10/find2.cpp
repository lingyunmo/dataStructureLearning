#include <iostream>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            cout << i << endl;
            flag = true;
        }
    }
    if (!flag)
        cout << x << " Not Found" << endl;
    return 0;
}