#include <bits/stdc++.h>

using namespace std;
const int N = 1e4 + 10;
int n, v;
vector<int> g[N], ans;
int in[N], pre[N];

void dfs(int x, int depth) {
    if (g[x].size() == 0 && depth > ans.size()) {
        ans.clear();
        int now = x;
        while (now != -1) {
            ans.push_back(now);
            now = pre[now];
        }
        return;
    }
    for (int i = 0; i < g[x].size(); i++) {
        v = g[x][i];
        pre[v] = x;
        dfs(v, depth + 1);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            cin >> v;
            in[v]++;
            g[i].push_back(v);
        }
        sort(g[i].begin(), g[i].end());
    }
    int root;
    for (int i = 0; i < n; i++) {
        if (!in[i]) {
            root = i;
            break;
        }
    }
    pre[root] = -1;
    dfs(root, 1);
    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    return 0;
}