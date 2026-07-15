#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class SolutionByBFS{
    private:
        bool bfs(int node,vector<vector<int>>& adjls,vector<int>&vis){
            vis[node] = 1;
            queue<pair<int,int>> q;
            q.push(make_pair(node,-1));
            while(!q.empty()){
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();
                for(auto adjNode : adjls[node]){
                    if(!vis[adjNode]){
                        vis[adjNode] =1;
                        q.push(make_pair(adjNode,node));
                    }
                    else if(parent != adjNode){
                        return true;
                    }
                }
            }
            return false;
        }

    public:
        bool isCycle(int n ,vector<vector<int>>adjls){
            vector<int> vis(n,0);
            for(int i = 0; i < n; i++){
                if(!vis[i] && (bfs(i,adjls,vis))){
                    return true;
                }
            } 
            return false;
        }
};




class SolutionByDFS{
    private:
        bool dfs(int node, int parent,vector<vector<int>>& adjls,vector<int>&vis){
           vis[node] =1;
           for(auto adjNode : adjls[node]){
                if(!vis[adjNode] ){
                    if(dfs(adjNode,node,adjls,vis))
                        return true;
                }else if(parent!= adjNode){
                    return true;
                }
           }
           return false;
        }

    public:
        bool isCycle(int n ,vector<vector<int>>adjls){
            vector<int> vis(n,0);
            for(int i = 0; i < n; i++){
                if(!vis[i] && (dfs(i,-1,adjls,vis))){
                    return true;
                }
            } 
            return false;
        }
};
