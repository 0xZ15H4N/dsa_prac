#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Quick Notes
*/

 


class Solution {

    public:
    Solution(){

    }
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>leftSum(n,0);
        vector<int>rightSum(n,0);
        vector<int>ans;
        int prev = 0;
        for(int i = 0; i < n ; i++){
            leftSum[i] = prev;
            prev += nums[i];
        }
        int forward = 0;
        for(int i = n-1; i >=0; i--){
            rightSum[i] = forward;
            forward += nums[i];
        }
        
        cout<<"left diff"<<endl;
        for(auto i : leftSum){
            cout<<i<<" ";
        }
        cout<<endl;
        
        for(auto i : rightSum){
            cout<<i<<" ";
        }
        cout<<endl;
        
        for(int i = 0; i < n ; i++){
            int diff = abs(leftSum[i] - rightSum[i]);
            ans.push_back(diff);
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {10,4,8,3};
    Solution a;
    vector<int> solve = a.leftRightDifference(nums);
    cout<<endl;
    for(auto i : solve){
        cout<<i;
        cout<<" ";
    }
    return 0;
}