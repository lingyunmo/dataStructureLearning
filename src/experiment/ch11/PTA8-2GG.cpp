#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 15;
vector<int> graph[MAXN];
bool visited[MAXN];
int n, m, start, countNumber;

void dfs(int u) {
    cout << u << ' ';
    visited[u] = true;
    countNumber++;
    for (auto j: graph[u]) {
        if (!visited[j]) {
            dfs(j);
        }
    }
}

int main() {
    cin >> n >> m >> start;
    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[a].insert(graph[a].begin(), b);
        graph[b].insert(graph[b].begin(), a);
    }
    dfs(start);
    cout << (countNumber != n ? "\n0" : "");
    return 0;
}
