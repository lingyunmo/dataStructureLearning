#include <iostream>
#include <vector>

using namespace std;

class num {
public:
    int xi;
    int zhi;

    num(int xi, int zhi) {
        this->xi = xi;
        this->zhi = zhi;
    }
};

int main() {
    vector<num> a1, a2, a3;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int b, c;
        cin >> b >> c;
        a1.push_back(num(b, c));
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        int b, c;
        cin >> b >> c;
        a2.push_back(num(b, c));
    }
    int i = 0, j = 0;
    while (i < a1.size() && j < a2.size()) {
        if (a1[i].zhi == a2[j].zhi) {
            if (a1[i].xi + a2[j].xi != 0) {
                a3.push_back(num(a1[i].xi + a2[j].xi, a1[i].zhi));
            }
            i++;
            j++;
        } else if (a1[i].zhi > a2[j].zhi) {
            a3.push_back(a1[i]);
            i++;
        } else {
            a3.push_back(a2[j]);
            j++;
        }
    }
    while (i < a1.size()) {
        a3.push_back(a1[i]);
        i++;
    }
    while (j < a2.size()) {
        a3.push_back(a2[j]);
        j++;
    }
    if (a3.size() == 0) {
        cout << "0 0" << endl;
        return 0;
    }
    for (i = 0; i < a3.size(); i++) {
        cout << a3[i].xi << " " << a3[i].zhi;
        if (i < a3.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}