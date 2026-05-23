#include<iostream>
#include<bits/stdc++.h>
using namespace std;



class Solution {
private:
    void solve(vector<vector<char>>& grid, vector<vector<int>>& grid_cpy, int posX, int posY, int prevX, int prevY, int& cnt, char prevC) {
        // base case
        if (((posX != prevX) || (posY != prevY)) && (grid_cpy[posX][posY]==1)) {
            cnt++;
            return;
        }
        grid_cpy[posX][posY] = 1;
        // right
        int n_posX = posX ;
        int n_posY = posY + 1 ;
        if (n_posX < grid.size() && grid[n_posX][n_posY] == prevC &&  grid_cpy[n_posX][n_posY] == 0) {
            solve(grid, grid_cpy, n_posX, n_posY, posX, posY, cnt, prevC);
        }
        // down
        n_posX = posX + 1; 
        n_posY = posY; 
        if (n_posY < grid[0].size() && grid[n_posX][n_posY] == prevC &&  grid_cpy[n_posX][n_posY] == 0) {
            solve(grid, grid_cpy, n_posX, n_posY, posX, posY, cnt, prevC);
        }
        // left
        n_posX = posX ;
        n_posY = posY - 1 ;
        if (n_posY >= 0 && grid[n_posX][n_posY] == prevC &&  grid_cpy[n_posX][n_posY] == 0) {
            solve(grid, grid_cpy, n_posX, n_posY, posX, posY, cnt, prevC);
        }
        // up
        n_posX = posX - 1;
        n_posY = posY;
        if (n_posX >= 0 && grid[n_posX][n_posY] == prevC &&  grid_cpy[n_posX][n_posY] == 0) {
            solve(grid, grid_cpy, n_posX, n_posY, posX, posY, cnt, prevC);
        }
        grid_cpy[posX][posY] = 0;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int size = grid.size();
        int col = grid[0].size();
        int row = size;
        int cycle_cnt = 0;
        vector<vector<int>> grid_cpy(size, vector<int>(col, 0)); // creating a shallow copy
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < col ; j++){
                solve(grid, grid_cpy, i,-j, -1, -1, cycle_cnt, grid[i][j]);
            }
        }
        return (cycle_cnt > 0) ? true : false ;
    }
};

int main(){

    vector<vector<char>> grid = {
    {'a', 'a', 'a', 'a'},
    {'a', 'b', 'b', 'a'},
    {'a', 'b', 'b', 'a'},
    {'a', 'a', 'a', 'a'}
    };

    Solution sln;
    bool cnt = sln.containsCycle(grid);
    if(cnt){
        cout<<"contains cycle";
    }else{
        cout<<"donot contain cycle";
    }
    return 0;
}