#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// sliding window problem


class Solution {
private:
    bool checkequal(vector<int>arr1,vector<int>arr2){
        for(int i =0;i<26;i++){
            if(arr1[i]!=arr2[i]){
                return 0;
            }
        }
        return 1;
    }
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> arr1(26,0);
        vector<int> arr2(26,0);
        for(int i = 0;i< s1.length();i++){  
            int idx = s1[i] - 'a';
            arr1[idx]++;
        } 
        int i = 0;
        int windowSize = s1.length();
        while(i<windowSize && i< s2.length()){
            int idx = s2[i] - 'a';
            arr2[idx]++;
            i++;
        }
        if(checkequal(arr1,arr2)){
            return 1;
        }
        while(i<s2.length()){
            int idx = s2[i] - 'a';
            arr2[idx]++; // add the new character to the window
            idx = s2[i-windowSize] - 'a';
            arr2[idx]--;// remove the first character of previous window
            i++;
            if(checkequal(arr1,arr2)){
                return 1;
            }
        }
        return 0;
            
    }
};