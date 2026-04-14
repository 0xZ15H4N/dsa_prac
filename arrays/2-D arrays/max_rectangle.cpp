#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> nextSmallerElement(vector<int>&heights,int size){

        vector<int>indexs(size);
        stack<int>s;
        s.push(-1); 
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
                next[i] = size; 
            }
            int b = next[i] - prev[i] - 1; 
            int NewArea = l * b;
            area = max(area, NewArea);
        }
        return area;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int>histogram(col,0);
        int area = INT_MIN;
        for(int i = 0; i<row;i++){
            for (int j = 0; j<col;j++){
                if(matrix[i][j] == '1'){
                    histogram[j]+=1;
                }else{
                    histogram[j]= 0;
                }
            }
            area = max(area, LargestRectangleArea(histogram,col)) ;
        }

        return area;
    }
};