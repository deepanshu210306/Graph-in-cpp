#include <bits/stdc++.h>
using namespace std;

// DFS function to detect a cycle in directed graph
bool isCyclicDFS(int node, unordered_map<int, list<int>>& graph,
                 unordered_map<int, bool>& visited,
                 unordered_map<int, bool>& dfsVisited) {
    visited[node] = true;
    dfsVisited[node] = true;

    for (auto neigh : graph[node]) {
        if (!visited[neigh]) {
            if (isCyclicDFS(neigh, graph, visited, dfsVisited)) return true;
        }
        else if (dfsVisited[neigh]) {
            // Cycle found
            return true;
        }
    }

    dfsVisited[node] = false; // backtrack
    return false;
}

string check_cycle(vector<vector<int>>& edges, int n, int m) {
    unordered_map<int, list<int>> graph;

    // Build directed graph
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        graph[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    // Check each unvisited node
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (isCyclicDFS(i, graph, visited, dfsVisited)) return "YES";
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
