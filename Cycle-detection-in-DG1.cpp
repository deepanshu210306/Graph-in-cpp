#include <bits/stdc++.h>
using namespace std;

bool kahn_cycle_detection(vector<vector<int>>& edges, int v) {
    unordered_map<int, list<int>> graph;
    vector<int> indegree(v, 0);

    // Build the graph and calculate indegrees
    for (int i = 0; i < edges.size(); i++) {
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

    // vector<int> ans;
    int count=0;

    // BFS
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        // inc count
        count++;

        for (auto neighbor : graph[front]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

if(count==v)return false;
else return true;
}

int main() {
    int v,e;
    cin >> v >>e;
    vector<vector<int>> edges(e, vector<int>(2));


    for (int i = 0; i < e; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    bool ans = kahn_cycle_detection(edges, v);

    if (ans) {
        cout << "Cyle present !!! ";
    }

    return 0;
}
