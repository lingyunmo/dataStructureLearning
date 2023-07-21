#include <iostream>
#include <algorithm>
#include <vector>

class MyFunctor {
public:
    int operator()(int x) {
        return 10 * x;
    }
};

int main() {
    std::vector<int> numbers;
    for (int i = 1; i <= 5; i++) {
        numbers.push_back(i);
    }
    MyFunctor myFunctor;
    std::transform(numbers.begin(), numbers.end(),
                   numbers.begin(), myFunctor);
    for (auto &num: numbers) {
        std::cout << num << " ";
    }
    return 0;
}