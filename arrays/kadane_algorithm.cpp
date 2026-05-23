#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Approch:
    1) Iterate through all the elements of the array
    2) sum+=nums[i]
    3) update the maxi if sum>maxi
    4) if sum<0 means we cant sum to next element ,sum reset to zero

    Extra question
        5) We can print the longest sequence 
        6) for that start = 0,ansStart = 0;ansEnd =0;
        7) if Start == 0 , we have new start of sequnece then start = i
        8) if start > max, then ansStart = Start , ansEnd = i;
*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;
        int ansStart = 0;
        int ansEnd = 0;
        int Start = 0;

        for(int i = 0; i<nums.size();i++){
            if(sum == 0){Start=i;}
            sum +=nums[i];
            if(sum>maxi){
                maxi = sum;
                ansStart=Start;
                ansEnd=i;
            }
            if(sum<0){
                sum = 0;
            }
        }
        return maxi;
    }
};