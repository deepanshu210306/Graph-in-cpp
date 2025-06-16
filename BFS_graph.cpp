#include <iostream>
#include <list>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

// BFS traversal starting from a given node
void bfs(unordered_map<int, list<int>>& graph, unordered_map<int, bool>& visit, vector<int>& ans, int node) {
    queue<int> q;
    q.push(node);
    visit[node] = true; // Mark the node as visited
    while (!q.empty()) {
        int front_node = q.front();
        q.pop();
        ans.push_back(front_node); // Store the node in the result

        // Visit all unvisited neighbors
        for (auto i : graph[front_node]) {
            if (!visit[i]) {
                q.push(i);
                visit[i] = true;
            }
        }
    }
}

// Prepare adjacency list from edge list
void prep_list(unordered_map<int, list<int>>& graph, vector<pair<int, int>>& edges) {
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        graph[u].push_back(v);
        graph[v].push_back(u); // For undirected graph
    }
}

// BFS for the entire graph (handles disconnected components)
vector<int> BFS(int vertex, vector<pair<int, int>>& edges) {
    unordered_map<int, list<int>> graph;
    vector<int> ans;
    unordered_map<int, bool> visit;

    // Prepare adjacency list
    prep_list(graph, edges);

    // Handle disconnected components
    // Iterate over all possible vertices (0 to vertex-1) or nodes in graph
    for (int i = 0; i < vertex; i++) {
        if (graph.find(i) != graph.end() && !visit[i]) { // Check if node exists and is unvisited
            bfs(graph, visit, ans, i);
        }
    }

    // Handle isolated vertices (no edges)
    for (int i = 0; i < vertex; i++) {
        if (!visit[i]) {
            ans.push_back(i);
            visit[i] = true;
        }
    }

    return ans;
}

int main() {
    int vertex, edge_count;
    cout << "Enter number of vertices: ";
    cin >> vertex;
    cout << "Enter number of edges: ";
    cin >> edge_count;

    vector<pair<int, int>> edges;
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edge_count; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    vector<int> result = BFS(vertex, edges);
    cout << "BFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}