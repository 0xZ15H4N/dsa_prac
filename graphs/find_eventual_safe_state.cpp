#include<iostream>
#include<bits/stdc++.h>
using namespace std;


bool dfs(int n, vector<vector<int>> &graph,vector<int> & vis,vector<int>&pathVis,vector<int>&check){
    vis[n] = 1;
    pathVis[n] = 1;

    for(auto i : graph[n]){
        if(!vis[i]){
            if(dfs(i,graph,vis,pathVis,check) == true){
                return true;
            }
        }else if(pathVis[i]){
            return true;
        }
    }
    check[n] = 1;
    pathVis[n] = 0;
    return false;
}


vector<int> find_eventual_safe_state(vector<vector<int>>graph){
    int n = graph.size();
    vector<int>check(n,0);
    vector<int>vis(n,0);
    vector<int>pathVis(n,0);
    vector<int> ans;
    for(int i = 0 ; i < n; i++){
        if(!vis[i]){
            dfs(i,graph,vis,pathVis,check);
        }
    }
    for(int i = 0; i < n; i++){
        if(check[i] == 1){
            ans.push_back(i);
        }
    }
    return ans;

}   

