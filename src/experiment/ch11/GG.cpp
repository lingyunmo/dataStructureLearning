#include <iostream>

template<class T>
class GNode {
public:
    int Nv;
    int Ne;
    T G[100][100];
    char Data[100];
};

template<class T>
GNode<T> *CreateGraph(int N) {
    GNode<T> *Graph = new GNode<T>;
    Graph->Nv = N;
    Graph->Ne = 0;
    for (int i = 0; i < Graph->Nv; i++) {
        for (int j = 0; j < Graph->Nv; j++) {
            Graph->G[i][j] = 0;
        }
    }
    return Graph;
}

int main() {
    GNode<int> *Graph = CreateGraph<int>(5);
    std::cout << Graph->Nv << std::endl;
    return 0;
}