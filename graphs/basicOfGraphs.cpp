#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class graph {
    public:
    // adjacent list
        unordered_map<int,list<int>>adj;

        void addNodes(int u, int v, bool dir){
            adj[u].push_back(v);
            if(!dir){
                adj[v].push_back(u);
            }
        }
        
        void printGraph(){  
            for(auto i : adj){
                cout<<i.first<<"-> ";
                for(auto j : i.second){
                    cout<<j<<" ";
                }
                cout<<endl;
            }
        }
};



int main(){
    graph g;
    int n; //no of nodes
    int m; // no of edges
    cout<< "Enter no of nodes and edges ";
    cin>>n>>m;

    for(int i =0; i < m; i++){
        int u, v;
        cin>>u>>v;
        g.addNodes(u,v,0);
    }
    g.printGraph();
    return 0;
}