#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <algorithm> // for sort (optional)

using namespace std;

void dfs(int node, unordered_map<int, bool>& visited, unordered_map<int, list<int>>& graph, vector<int>& component) {
    visited[node] = true;
    component.push_back(node);

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, graph, component);
        }
    }
}

vector<vector<int>> DFS(int V, vector<vector<int>>& edges) {
    unordered_map<int, list<int>> graph;

    // Build adjacency list
    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        graph[u].push_back(v);
        graph[v].push_back(u); // Undirected graph
    }

    unordered_map<int, bool> visited;
    vector<vector<int>> components;

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, visited, graph, component);
            sort(component.begin(), component.end()); // optional
            components.push_back(component);
        }
    }

    return components;
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> edges(E, vector<int>(2));

    for (int i = 0; i < E; ++i) {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<vector<int>> components = DFS(V, edges);

    cout << "Connected Components:\n";
    int idx = 1;
    for (const auto& comp : components) {
        cout << "Component " << idx++ << ": ";
        for (int node : comp) {
            cout << node << " ";
        }
        cout << "\n";
    }

    return 0;
}
