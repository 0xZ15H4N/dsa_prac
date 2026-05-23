#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*


Given array we need to find the leader condition for leader is 
all the elements to right should be smaller to it

[22,12,2,0,3,6]

ans = [6,12,22] 
no one is in the right of 6 automatically a leader
12 is also a leader cause no one greater then 12 from right
22 goes for the same

*/

vector<int> solve(vector<int>nums){
    vector<int> ans;

    int maxi = INT_MIN;
    for(int i = nums.size()-1;i>=0;i--){
        if(maxi<nums[i]){
            ans.push_back(nums[i]);
            maxi = nums[i];
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){

    vector<int> nums = {4, 7, 1, 0};
    vector<int> ans = solve(nums);
    for(auto i : ans){
        cout<<i;
    }
    return 0;
}