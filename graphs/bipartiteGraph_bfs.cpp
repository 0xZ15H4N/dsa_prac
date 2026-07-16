#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int check(int Node , vector<vector<int>>& adjLs, vector<int>&vis){
    vis[Node] = 1;
    queue<int>q;
    q.push(Node);
    while(!q.empty()){
        int currNode = q.front();
        q.pop();
        for(auto it : adjLs[Node]){
            if(vis[it]  == -1){  // why taking -1 as unfilled cause 0 / 1 are already reserve as filled
                vis[it] = !vis[currNode];
                q.push(it);
            }else if(vis[it] == vis[currNode]){
                return false;
            }
        }
    }
    return true;
}


bool bipartiteGraph_bfs(vector<vector<int>> adjLs){
    int Nodes = adjLs.size();
    vector<int> vis(Nodes,-1);
    for(auto i = 0; i < Nodes; i++){
        if(vis[i] == -1){
            if(check(i,adjLs,vis) == false){
                return false;
            }
        }
    }
    return true;
}

