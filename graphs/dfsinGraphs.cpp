#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Quick Notes
*/



void dfsinGraphs(vector<vector<int>>&adj,vector<int>&vis,vector<int>&ans,int node){

    ans.push_back(node);
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it])
            dfsinGraphs(adj,vis,ans,it);
    }
}

int main(){
// Your Driver Code
    return 0;
}