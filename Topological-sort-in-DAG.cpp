#include <bits/stdc++.h>
using namespace std;

// DFS function for topological sort
void toposort(int node, unordered_map<int, bool>& visited,
              stack<int>& s, unordered_map<int, list<int>>& graph) {
    visited[node] = true;

    for (auto neighbor : graph[node]) {
        if (!visited[neighbor]) {
            toposort(neighbor, visited, s, graph);
        }
    }

    s.push(node); // Push after visiting all descendants
}

// Topological Sort Function
vector<int> topological(vector<vector<int>>& edges, int v, int e) {
    unordered_map<int, list<int>> graph;

    // Build graph
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        graph[u].push_back(v); // Directed edge
    }

    unordered_map<int, bool> visited;
    stack<int> s;
    vector<int> ans;

    // Call DFS on all unvisited nodes
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            toposort(i, visited, s, graph);
        }
    }

    // Get the result from the stack
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<int>> edges(e, vector<int>(2));

    // Input edges
    for (int i = 0; i < e; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<int> topo = topological(edges, v, e);

    // Print topological sort
    cout << "Topological Order:\n";
    for (int node : topo) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
