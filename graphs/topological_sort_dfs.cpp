#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Quick Notes
*/


bool dfs(int n , stack<int>&stk,vector<int>&vis,vector<vector<int>>&graph){
    vis[n] =1;

    for(auto i : graph[n]){
        if(!vis[i]){
            dfs(i,stk,vis,graph);
        }
    }
    stk.push(n);

}

vector<int> topological_sort_dfs(vector<vector<int>> graph){
    int n = graph.size();
    stack<int>stk;
    vector<int>ans;
    vector<int>vis;
    for(int i = 0; i <n;i++){
        if(!vis[i]){
            dfs(i,stk,vis,graph);
        }
    }

    while(!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
    }

    return ans;

}

