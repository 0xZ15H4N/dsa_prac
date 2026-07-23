
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {

  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<pair<int,int>>adjls[V];
        queue<int>q;
        vector<int>vis(V,0);
        vector<int>dis(V,-1);
        vector<int>indegree(V,0);
        vector<int>topolist;
        stack<int>stk;
        for(auto j : edges){
            int u = j[0];
            int v = j[1];
            int wt = j[2];
            adjls[u].push_back({v,wt});
        }

        for(int i = 0; i< V; i++){
            for(auto node : adjls[i]){
                int v = node.first;
                indegree[v]++;
            }
        }
        for(int i =0; i < V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int top = q.front();
            q.pop();
            topolist.push_back(top);
            for(auto i : adjls[top]){
                int v = i.first;
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        // topo list will be created using the kahn's algorithm;
        while(topolist.size() >  0){
            int back = topolist.back();
            topolist.pop_back();
            stk.push(back);
        }
        dis[0] = 0;
    
        while(!stk.empty()){
            int node = stk.top();
            stk.pop();
            if(dis[node] == -1)
                continue;
            for(auto i : adjls[node]){
                int v = i.first;
                int wt = i.second;
                if(dis[v] == -1)
                    dis[v] = dis[node] + wt;
                else
                    dis[v] = min(dis[v], dis[node] + wt);
            }
        }
        return dis;
        
    }
};
