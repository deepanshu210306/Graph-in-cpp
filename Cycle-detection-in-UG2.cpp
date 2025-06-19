#include <bits/stdc++.h>
using namespace std;

// DFS function to detect a cycle
bool iscyclicDFS(int node, int parent, unordered_map<int, list<int>>& graph, unordered_map<int, bool>& visited) {
    visited[node] = true;

    for (auto neigh : graph[node]) {
        if (!visited[neigh]) {
            if (iscyclicDFS(neigh, node, graph, visited)) return true;
        }
        else if (neigh != parent) {
            // Cycle detected
            return true;
        }
    }

    return false;
}

// Function to check cycle in an undirected graph
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

    // Check each unvisited node
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (iscyclicDFS(i, -1, graph, visited)) return "YES";
        }
    }

    return "NO";
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(2));

    // Input edges
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    cout << check_cycle(edges, n, m) << endl;

    return 0;
}
