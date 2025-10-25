#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*

Given an array nums of distinct integers, 
return all the possible permutations. You can return the answer in any order.
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]



*/
void solver(vector<int> values,vector<vector<int>>&arr,int index){
    if(index >= values.size()){
        arr.push_back(values);
        return;
    }
    for(int  j = index; j<values.size();j++){
        swap(values[index],values[j]);
        solver(values,arr,index+1);
        swap(values[index],values[j]);
    }
}


int main(){

    vector<int>values= {1,2,3};
    vector<vector<int>> arr;
    solver(values,arr,0);
    for(auto i:arr){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }




    return 0;
}