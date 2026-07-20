#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
its is applied to find the shortest distance between src to every other node that 
contains -ve weights on edges;
*/

vector<int> bellman_ford_algorithm_DG(int V, vector<vector<int>>edges,int src){
    vector<int>dist(V,1e8);
    dist[src] = 0;
    for(int i =0; i<V-1; i++){
        for(auto iter : edges){
            int u = iter[0];
            int v = iter[1];
            int wt = iter[2];
            if(dist[u]!= 1e8 && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }
    for(auto iter : edges){
        int u = iter[0];
        int v = iter[1];
        int wt = iter[2];
        if(dist[u]!= 1e8 && dist[u] + wt < dist[v]){
            return {-1};
        }
    }
    return dist;
}

