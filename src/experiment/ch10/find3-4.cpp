#include <iostream>
#include <unordered_set>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n];
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
    }
    bool first = true;
    for (int i = 0; i < n; i++) {
        if (s.find(arr[i]) != s.end()) {
            if (first) {
                cout << arr[i];
                first = false;
            } else {
                cout << " " << arr[i];
            }
            s.erase(arr[i]);
        }
    }
    return 0;
}