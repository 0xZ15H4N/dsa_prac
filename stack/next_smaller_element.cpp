#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*


we need to find the next smaller element for every elemtn in the array or stack 
for example [2,1,4,3]
for 2 next 1 is smaller in the right dir
for 1 no one is smaller that this in right dir so answer would be -1
for 4 , 3 is smaller 
and for 3 no one is smaller in the right dir so answer would be -1
so final answer would be [1,-1,3,-1]
if we go from left to right we will be solvin this in O(n^2)
but if we go from right to left we will be doing it in O(n)

*/

vector<int> nextSmallerElement(vector<int>&arr){
    stack<int>s;
    s.push(-1);
    vector<int>ans(arr.size());

    for(int i = arr.size()-1;i>=0;i--){
        int curr = arr[i];
        while(s.top()>=curr){
            s.pop();
        }
        ans[i] = s.top(); // position pe insert kiya hai
        s.push(curr);
    }
    return ans;
}   


int main(){

    vector<int>arr;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(3);

    for(auto i : arr){
        cout<<i<<" ";
    }

    vector<int> ans = nextSmallerElement(arr);

    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}