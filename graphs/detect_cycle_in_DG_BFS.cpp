#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Quick Notes
*/

bool detect_cycle_in_DG_BFS(vector<vector<int>>graph){
    int nodes = graph.size();
    vector<int>inDegree(nodes,0);
    vector<int>ans;
    queue<int> q;
    for(int i  = 0 ; i< nodes; i++){
        for(auto it : graph[i]){
            inDegree[it]++;
        }
    }
    for(int i =0; i< nodes;i++){
        if(inDegree[i] == 0){
            q.push(i);
        } 
    }

    while(!q.empty()){
        int top = q.front();
        q.pop();
        ans.push_back(top);
        for(auto i : graph[top]){
            inDegree[i]--;
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
    }
    if(ans.size() == nodes){
        return false; // no cycle
    }
    return true; // cycle detected
}

