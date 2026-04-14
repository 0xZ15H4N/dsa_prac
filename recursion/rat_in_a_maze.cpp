#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void solve(vector<vector<int>>&maze,vector<vector<int>>&visited,vector<string>&ans,string output,int x, int y){
    
    if((x==maze.size()-1) && (y==maze.size()-1)){
        ans.push_back(output);
        return;
    }
    visited[x][y] = 1;
    // up
    if(  x-1 >= 0 && maze[x-1][y] == 1 && (visited[x-1][y] == 0)){ 
        output.push_back('U');
        solve(maze,visited,ans,output,x-1,y);   
        output.pop_back();
    }
    // down
    if((x+1 <= maze.size()-1) && (maze[x+1][y] == 1) && (visited[x+1][y] == 0)){
        output.push_back('D');
        solve(maze,visited,ans,output,x+1,y);
        output.pop_back();
    }

    // right
    if((y+1 <= maze.size()-1) && (maze[x][y+1] == 1) && (visited[x][y+1] == 0)){
        output.push_back('R');
        solve(maze,visited,ans,output,x,y+1);
        output.pop_back();
    }

    // left
    if((y-1 >= 0 && y-1 <= maze.size()-1) && (maze[x][y-1] == 1) && (visited[x][y-1] == 0)){ 
        output.push_back('L');
        solve(maze,visited,ans,output,x,y-1);
        output.pop_back();
    }
    visited[x][y] = 0;

}
  

int main(){
    vector<string>output;
    vector<vector<int>> maze = {{1,0,0,0},
                                {1,1,0,1},
                                {1,1,0,0},
                                {0,1,1,1}};
    
    vector<vector<int>>visited ={{0,0,0,0},
                                {0,0,0,0},
                                {0,0,0,0},
                                {0,0,0,0}};

    if(maze[0][0] == 0){ // if the rat cannot start from source
        return 0;
    }
    
    solve(maze,visited,output,"",0,0);
    for(auto i : output){
        for(auto j : i){
            cout<<j;
        }
        cout<<endl;
    }                     
    return 0;
}