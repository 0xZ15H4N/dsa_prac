#include<iostream>
#include<bits/stdc++.h>
using namespace std;



class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<pair<int,int>>adjLs[V];
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>vis(V,0);

        for(auto i : edges){
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            adjLs[u].push_back({v,wt});
            adjLs[v].push_back({u,wt});
        }
        pq.push({0,0});
        int sum = 0;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int node = top.second;
            int wt = top.first;
            if(vis[node] == 1){
                continue;
            }
            vis[node] = 1;
            sum += wt;
            for(auto adjNode : adjLs[node]){
                int v = adjNode.first;
                int edW = adjNode.second;
                if(!vis[v]){
                    pq.push({edW,v});
                }
            }
        }
        return sum;
    }
};