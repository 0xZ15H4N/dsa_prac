#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Quick Notes
*/

class compare{
    public:  
        bool operator()(pair<int,int>a, pair<int,int>b){
            if(a.first != b.first){
                return a.first > b.first;
            }
            return a.second > b.second;
        }
};

vector<int> dijkstra_algorithm_shortest_path_UDG(vector<vector<int>>adjLs[],int N,int src){
    priority_queue<pair<int,int>, vector<pair<int,int>>,compare>pq;
    vector<int>dist(N,INT_MAX);
    dist[src] = 0;
    pq.push({src,0});
    while(!pq.empty()) {
        int dist_ = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto i : adjLs[node]){
            // here i is a vector<vector<int>>
            //                i
            //                |
            //                V
            // adjLs[node] = {{},{},{}}
            int edgeWeight = i[1];
            int adjNode = i[0];

            if(dist[adjNode] > dist_ + edgeWeight){
                dist[adjNode] = dist_ + edgeWeight;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    return dist; 

}

