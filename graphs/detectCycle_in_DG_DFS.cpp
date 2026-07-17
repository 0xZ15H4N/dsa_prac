#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// apply dfs in DG
bool check(int Node,vector<vector<int>>& adjLs,vector<int> &vis,vector<int> &pathVis){
    vis[Node] = 1;
    pathVis[Node] = 1;

    for(auto i :adjLs[Node]){
        if(!vis[i]){
            if(check(i,adjLs,vis,pathVis) == true){
                return true;
            }
        }else if(pathVis[i]){
            return true;
        }
    }

    pathVis[Node] = 0; 
    return false;
}



bool detectCycle_in_DG(vector<vector<int>>adjLs){
    int Nodes  = adjLs.size();   
    vector<int> vis(Nodes,0);
    vector<int> pathVis(Nodes,0);
    for(auto i = 0 ;i <Nodes; i++){
        if(!vis[Nodes]){
            if(check(i,adjLs,vis,pathVis) == true){
                return true;
            }
        }
    }
    return false;

}

