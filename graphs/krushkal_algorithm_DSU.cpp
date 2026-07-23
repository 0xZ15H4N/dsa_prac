#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 
class DisjointSet{
    vector<int>rank,parent;
    public:
        DisjointSet(int V){
            rank.resize(V+1,0);
            parent.resize(V+1);
            for(int i = 0; i <= V ; i++){
                parent[i] = i;
            }
        }
        
        int findUpar(int node){
            if(parent[node] == node){
                return node;
            }
            return parent[node] = findUpar(parent[node]);
        }
        
        void unionByRank(int u, int v){
            int ulp_u = findUpar(u);
            int ulp_v = findUpar(v);
            
            if(ulp_u == ulp_v){
                return;
            }
            else if(rank[ulp_u] > rank[ulp_v]){
                parent[ulp_v] = ulp_u;
            }else if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
};

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<pair<int,pair<int,int>>>adjls;
            for(auto iter : edges){
                int u = iter[0];
                int v = iter[1];
                int wt = iter[2];
                adjls.push_back({wt,{u,v}});
            }
        DisjointSet ds(V);
        sort(adjls.begin(),adjls.end());
        int mstwt = 0;
        for(auto it : adjls){
            int w = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if(ds.findUpar(u) != ds.findUpar(v)){ // both donot belongs to a single component
                mstwt+=w;
                ds.unionByRank(u,v);
            }
        }
        return mstwt;
    }
};



















