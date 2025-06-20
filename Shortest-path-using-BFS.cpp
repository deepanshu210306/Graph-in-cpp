#include <bits/stdc++.h>
using namespace std;

vector<int> shortestpath(vector<pair<int, int>> edges, int n, int m, int s, int t) {
    unordered_map<int, list<int>> adj;

    // Build the adjacency list
    for (int i = 0; i < m; i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u); // Because it's undirected
    }

    // BFS setup
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;

    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (auto neighbor : adj[front]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = front;
                q.push(neighbor);
            }
        }
    }

    // Build shortest path from parent map
    vector<int> ans;
    int current_node = t;

    // If target node was never reached
    if (!visited[t]) {
        return {}; // Return empty vector, no path exists
    }

    while (current_node != -1) {
        ans.push_back(current_node);
        current_node = parent[current_node];
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    int start, target;
    cin >> start >> target;

    vector<int> path = shortestpath(edges, n, m, start, target);

    if (path.empty()) {
        cout << "No path found from " << start << " to " << target << "\n";
    } else {
        cout << "Shortest path from " << start << " to " << target << ":\n";
        for (int node : path) {
            cout << node << " ";
        }
        cout << "\n";
    }

    return 0;
}
