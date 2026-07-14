#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Quick Notes
*/

void subsequence_of_array_end_values_product_min(vector<vector<int>>&ans,vector<int>output,vector<int>&arr,int &n,int &m,int index){
    if(output.size()== m){
        ans.push_back(output);
        return;
    }
    for(int i = index; i < n; i++){
        output.push_back(arr[i]);
        subsequence_of_array_end_values_product_min(ans,output,arr,n,m,i+1);
        output.pop_back();
    }
}

int main(){
    vector<int> arr = {2,3,4,5};
    vector<vector<int>> ans;
    int n = arr.size();
    int m = 3;
    int index = 0;
    int minArr = INT_MAX;
    vector<int> output;
    subsequence_of_array_end_values_product_min(ans,output,arr,n,m,index);
    for(auto i : ans){
        int first = i[0];
        int last = i[m-1];
        minArr = min(minArr,first*last);
    }
    cout<<"Min is "<<minArr;
    return 0;
}