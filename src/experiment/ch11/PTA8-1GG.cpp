#include <iostream>
#include <vector>

using namespace std;

// 定义图的类型
const int DIRECTED = 1; // 有向图
const int UNDIRECTED = 2; // 无向图

int main() {
    int num_nodes, num_edges, graph_type;
    cin >> num_nodes >> num_edges >> graph_type;
    int adj_matrix[num_nodes][num_nodes]; // 邻接矩阵
    vector<int> adj_list[num_nodes]; // 邻接表
    // 初始化邻接矩阵为0
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            adj_matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < num_edges; i++) {
        int from, to;
        cin >> from >> to;
        from--; // 从0开始编号
        to--;
        if (graph_type == DIRECTED) { // 有向图
            adj_matrix[from][to] = 1;
            adj_list[from].push_back(to);
        } else { // 无向图
            adj_matrix[from][to] = adj_matrix[to][from] = 1;
            adj_list[from].push_back(to);
            adj_list[to].push_back(from);
        }
    }

    // 邻接矩阵
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }
    // 邻接表
    for (int i = 0; i < num_nodes; i++) {
        cout << i << ":";
        for (int j = adj_list[i].size() - 1; j >= 0; j--) {
            cout << adj_list[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
