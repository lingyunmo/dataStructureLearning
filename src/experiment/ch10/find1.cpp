#include <iostream>

using namespace std;

int main() {
    int a[12] = {1, 2, 5, 6, 7, 12, 15, 67, 88, 99, 100, 200};
    int x;
    cin >> x;
    int low = 0, high = 11, mid, count = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        count++;
        if (a[mid] == x) {
            cout << "found! " << mid << " " << count << endl;
            return 0;
        } else if (a[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    cout << "not found!" << endl;
    return 0;
}