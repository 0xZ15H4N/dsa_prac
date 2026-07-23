#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Quick Notes
*/

void bfsinGraphs(vector<vector<int>>adj,vector<int>&ans,vector<int>vis,int src){
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int front = q.front();
        q.pop();
        vis[front] = 1;
        ans.push_back(front);
        for(auto it: adj[front]){
            if(!vis[it])
                q.push(it);
        }
    }
}

int main(){
    // if multiple components are there
    vector<int>vis(10,0);
    for(int i =0; i < 10;i++){
        if(!vis[i]){
            bfsinGraph()
        }
    }
    return 0;
}