#include <bits/stdc++.h>
using namespace std;

vector<int> kahnTopologicalSort(vector<vector<int>>& edges, int v, int e) {
    unordered_map<int, list<int>> graph;
    vector<int> indegree(v, 0);

    // Build the graph and calculate indegrees
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int w = edges[i][1];
        graph[u].push_back(w);
        indegree[w]++;
    }

    // Push all nodes with indegree 0 into queue
    queue<int> q;
    for (int i = 0; i < v; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;

    // BFS
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for (auto neighbor : graph[front]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return ans;
}

int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<int>> edges(e, vector<int>(2));

    for (int i = 0; i < e; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<int> topo = kahnTopologicalSort(edges, v, e);

    if (!topo.empty()) {
        cout << "Topological Order (Kahn's Algorithm):\n";
        for (int node : topo) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
