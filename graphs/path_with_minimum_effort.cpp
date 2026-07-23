#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, 
where heights[row][col] represents the height of cell (row, col). 
You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed).
 You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

need to find the min of all the path from 0 -> n-1 where diff between each cell height is maximum
need to use a pq to store the coordinates with effort 
in pq it will arenge all the points with minimum effort at the top ;
need to iterate through all the grid and update the grid effort only iff the newEffort is found to be smaller that current one

good question , can only be done if know why dijskra is used main this ithat we need ot find the mininum of the maximum effort so storethe 
maximum effort in the prioity_queue min_heap and pop only the smallest one this way we get the "mininum of the maximum effort"
*/


class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> vis(rows,vector<int>(cols,1e9));
        q.push({0,{0,0}});   
        int dir[] = {-1,0,1,0,-1};
        vis[0][0] = 0;
        while(!q.empty()){
            int effort = q.top().first;
            int r = q.top().second.first;
            int c = q.top().second.second;
            q.pop();
            if(r == rows-1 && c == cols-1){
                return effort;
            }
            for(int i = 0; i < 4;i++){
                int nrow = r + dir[i];
                int ncol = c + dir[i+1];
                if(nrow >=0 && nrow < rows && ncol >=0 && ncol < cols){
                    int nEffort = max(effort,abs(heights[r][c] - heights[nrow][ncol]));
                    if(nEffort < vis[nrow][ncol]){ // this is  important to think of this is the make game changer logical point
                        vis[nrow][ncol] = nEffort;
                        q.push({nEffort,{nrow,ncol}});
                    }    
                } 
            }
        }
        return 0;
    }
};