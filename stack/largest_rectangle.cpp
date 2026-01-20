#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*


Quick-Notes


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

int main(){

    vector<int>heights = {2,1,5,6,2,3};
    int max_area = LargestRectangleArea(heights,heights.size());


    cout<<"Max Area is "<<max_area;

    return 0;
}