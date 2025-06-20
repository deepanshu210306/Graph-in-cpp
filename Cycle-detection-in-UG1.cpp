#include <bits/stdc++.h>
using namespace std;

bool iscyclic(int src, unordered_map<int, list<int>>& graph, unordered_map<int, bool>& visited) {
    unordered_map<int, int> parent;
    visited[src] = true;
    parent[src] = -1;

    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (auto neigh : graph[front]) {
            if (visited[neigh] && neigh != parent[front]) {
                return true;
            } else if (!visited[neigh]) {
                visited[neigh] = true;
                parent[neigh] = front;
                q.push(neigh);
            }
        }
    }

    return false;
}

string check_cycle(vector<vector<int>>& edges, int n, int m) {
    unordered_map<int, list<int>> graph;

    // Build graph
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (iscyclic(i, graph, visited)) return "YES";
        }
    }

    return "NO";
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(2));

    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    cout << check_cycle(edges, n, m) << endl;

    return 0;
}
