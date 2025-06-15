#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

class Graph{
    unordered_map<int,list<int>>x;
    public:
    void addEdge(int u,int v,bool direction){
        x[u].push_back(v);
        if(direction==0)x[v].push_back(u);
    }
    void print(){
        for(auto i:x){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};

int main(){
    int n;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;
    int m;
    cout<<"Enter the number of edges"<<endl;
    cin>>m;
    Graph g;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }
    g.print();
    return 0;
}