#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<string> input[256], output[256];
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            int port, addr;
            string value;
            cin >> port >> addr >> value;
            input[port].push(value);
        }
        for (int i = 0; i < 256; i++) {
            if (!input[i].empty()) {
                output[i].push(input[i].front());
                input[i].pop();
            }
        }
    }
    for (int i = 0; i < 256; i++) {
        if (!output[i].empty()) {
            cout << i << " ";
            while (!output[i].empty()) {
                cout << output[i].front() << " ";
                output[i].pop();
            }
            cout << endl;
        }
    }
    return 0;
}