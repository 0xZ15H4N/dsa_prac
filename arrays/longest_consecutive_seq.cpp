#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> Set(nums.begin(),nums.end());
        if(nums.size()==0){
            return 0;
        }
        int len = 0;
        int longest = 0;
        for(auto num:Set ){
            if(Set.find(num - 1)==Set.end()){ //if previous element donot exist
                // then the current element is the start!
                len = 1;
                while(Set.find(num+len) != Set.end()){//current ele +1 exist or not
                    len++;
                }
                longest = max(longest,len);
            }
        }
        return longest;       
    }
}; 