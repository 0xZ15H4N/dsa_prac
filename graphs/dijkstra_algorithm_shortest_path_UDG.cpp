#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Quick Notes
*/
// using pq always preferred!
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
    pq.push({0,src});
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

// using set
class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int, int>> st;
        vector<int> dist(V, 1e9);

        dist[S] = 0;
        st.insert({0, S});

        while (!st.empty())
        {
            auto it = *(st.begin());

            int node = it.second;
            int dis = it.first;

            st.erase(it);

            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int edgeWeight = it[1];

                if (dis + edgeWeight < dist[adjNode])
                {
                    // Remove the old pair if it exists
                    if (dist[adjNode] != 1e9)
                    {
                        st.erase({dist[adjNode], adjNode});
                    }

                    dist[adjNode] = dis + edgeWeight;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};