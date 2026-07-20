#include<iostream>
#include<bits/stdc++.h>
using namespace std;



class compare{
    public:
        bool operator()(pair<int,int>a, pair<int,int>b){
            if(a.first != b.first){
                return a.first > b.first;
            }
            return a.second > b.second;
        }
};

vector<int> print_shortest_path_inUDG(vector<vector<int>>adjLs[],int src, int des,int N){

    priority_queue<pair<int,int>,vector<pair<int,int>>,compare>pq;
    vector<int>parent(N);
    vector<int>dist(N,INT_MAX);
    vector<int>ans;
    dist[src] = 0;
    pq.push({0,src});
    for(int i =1; i < N;i++){
        parent[i-1] = i;
    }
    while(!pq.empty()){
        int dist_ = pq.top().first;
        int node = pq.top().second;
        pq.pop(); 
        if (dist_ > dist[node]){continue;} // optimisation
        for(auto i : adjLs[node]){
            int edgeWeight = i[1];
            int adjNode = i[0];
            if(dist_ + edgeWeight < dist[adjNode]){
                dist[adjNode] = dist_ + edgeWeight;
                parent[adjNode] = node;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    if(dist[des] == INT_MAX) {  // cannot reach des from src
        return vector<int>(N,0);
    }
    
    int node = des;
    while(node != src){
        ans.push_back(node);
        node = parent[node];
    }
    ans.push_back(src);
    reverse(ans.begin(),ans.end());
    return ans;

}

int main(){
// Your Driver Code
    return 0;
}