#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 15;
vector<int> adj[MAXN];
bool visited[MAXN];
int n, m, s, countNumber;

void bfs(int u) {
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        if (!visited[t]) {
            visited[t] = true;
            cout << t << ' ';
            countNumber++;
            for (auto x: adj[t]) {
                q.push(x);
            }
        }
    }
}

int main() {
    cin >> n >> m >> s;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].insert(adj[a].begin(), b);
        adj[b].insert(adj[b].begin(), a);
    }
    bfs(s);
    cout << (countNumber != n ? "\n0" : "");
    return 0;
}
