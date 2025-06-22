#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addedge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
    }

    void print() {
        for (auto i : adj) {
            cout << i.first << " -> ";
            for (auto j : i.second) {
                cout << "(" << j.first << "," << j.second << "), ";
            }
            cout << endl;
        }
    }

    void dfs(int node, unordered_map<int, bool>& visited, stack<int>& s) {
        visited[node] = true;
        for (auto neigh : adj[node]) {
            if (!visited[neigh.first]) {
                dfs(neigh.first, visited, s);
            }
        }
        s.push(node);
    }
    void getpath(int src,vector<int>&dist,stack<int>&s){
    dist[src]=0;
    while(!s.empty()){
        int top=s.top();
        s.pop();
        if(dist[top]!=INT_MAX){
            for(auto i:adj[top]){
                if(dist[top]+i.second<dist[i.first]){
                    dist[i.first]=dist[top]+i.second;
                }
            }
        }
    }
    }
};

int main() {
    Graph g;
    g.addedge(0, 1, 5);
    g.addedge(0, 2, 3);
    g.addedge(1, 2, 2);
    g.addedge(1, 3, 6);
    g.addedge(2, 3, 7);
    g.addedge(2, 4, 4);
    g.addedge(2, 5, 2);
    g.addedge(3, 4, -1);
    g.addedge(4, 5, -2);

    unordered_map<int, bool> visited;
    stack<int> s;

    int n = 6;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            g.dfs(i, visited, s);
        }
    }

            int src=1;
    vector<int>dist(n,INT_MAX);
    
    g.getpath(src,dist,s);
    cout<<"ans is :"<<endl;
    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }cout<<endl;
    return 0;
}
