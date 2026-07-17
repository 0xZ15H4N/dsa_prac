#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
    Kahn's algorithm
*/

vector<int> topological_sort_bfs(vector<vector<int>>& graph){
    int nodes = graph.size();
    vector<int>indegree(nodes,0);
    queue<int>q;
    vector<int>ans;
    for(int i = 0; i < nodes ; i++){
       for(int it :graph[i]){
            indegree[it] ++;
       } 
    }  
    for(int i = 0; i < nodes; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int top = q.front();
        q.pop();
        ans.push_back(top);
        for(auto i : graph[top]){
            indegree[i]--;
            if(indegree[i] == 0){
                q.push(i);
            }
        }
    }
    return ans;
}

