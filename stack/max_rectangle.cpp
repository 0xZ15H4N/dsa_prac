#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*

we need to find the max rectangle in a binary matrix
we will use the know ledge of largest area of histogram
            _0   1   2_
        0  | 1   1   1 |
        1  | 1   1   1 |
        2  |_1   1   0_|

*/

vector<int> nextSmallerElement(vector<int>&heights,int size){

    vector<int>indexs(size);
    stack<int>s;
    s.push(-1); // have pushed -1 in the stack so the while could run else in the first com
    for(int i = size-1;i>=0;i--){
        int curr = heights[i];
        while(s.top()!= -1 && heights[s.top()]>=curr){
            s.pop();
        }
        indexs[i] = s.top();
        s.push(i);
    }

    return indexs;
}
vector<int> prevSmallerElement(vector<int>&heights,int size){

    vector<int>indexs(size);
    stack<int>s;
    s.push(-1);
    for(int i = 0;i<size;i++){
        int curr = heights[i];
        while(s.top()!= -1 && heights[s.top()]>=curr){
            s.pop();
        }
        indexs[i] = s.top();
        s.push(i);
    }

    return indexs;
}


int LargestRectangleArea(vector<int>&heights,int size){
    vector<int>next(size);
    vector<int>prev(size);

    next = nextSmallerElement(heights,size);
    prev = prevSmallerElement(heights,size);

    int area = INT_MIN;
    for(int i = 0 ; i<size;i++){
        int l = heights[i];
        if(next[i] == -1){
            next[i] = size; // if all the heights are of the same then largest rectangle would have the breadth equal to size of the vector
        }
        int b = next[i] - prev[i] - 1; // this is the formula that wil give us the width of the largest rectangle
        int NewArea = l * b;
        area = max(area, NewArea);
    }
    return area;
}


int MaxRectangle(vector<vector<int>>&matrix , int size){
    int area = LargestRectangleArea(matrix[0],size);
    for(int i = 1;i<size; i++){
        for(int j = 0; j<size;j++){
            if(matrix[i][j]){
                matrix[i][j] = matrix[i][j] + matrix[i-1][j]; // we are doing changes in the matrix itself 
            }
            else{
                matrix[i][j] = matrix[i][j];
            }
        }
        area = max(area,LargestRectangleArea(matrix[i],size));
    }
    return area;
}


int main(){


    vector<vector<int>> matrix = {
        {0,1,1,0},
        {1,1,1,1},
        {1,1,1,1},
        {1,1,0,0}
    };


    cout<<"Maximum area here is " << MaxRectangle(matrix,4);

    return 0;
}