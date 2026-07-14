#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Quick Notes
*/

void bfsinGraphs(vector<vector<int>>adj,vector<int>&ans,vector<int>vis){
    queue<int>q;
    q.push(1);
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
// Your Driver Code
    return 0;
}