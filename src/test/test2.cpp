#include<iostream>
#include<vector>

using namespace std;

class www {
public:
    vector<int> v;

    void add(int x) {
        v.push_back(x);
        sort(v.begin(), v.end());
    };

    void listAll() {
        for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
            cout << *it<< " ";
        }
    };
};

int main() {
    www v;
    v.add(10);
    v.add(20);
    v.add(4);
    v.add(5);
    v.add(6);
    v.add(1);
    v.listAll();
}