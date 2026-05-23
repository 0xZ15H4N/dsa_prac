#include<iostream>
#include<bits/stdc++.h>
using namespace std;



// this is  the optimal solution if the arrays contains -ve +ve and zeros
// TC -> O(n)
// SC -> O(n)
int solve(vector<int> arr, int k ){
    int prefixSum = 0;
    int len = 0;
    unordered_map<int,int> mpp;
    for(int i = 0;i < arr.size();i++){
        prefixSum +=arr[i];
        if(prefixSum == k){
            len = i+1; // or max(len, i+1);
        }
        int diff = prefixSum - k;
        if(mpp.find(diff)!=mpp.end()){
            len = max(len,i - mpp[diff]);
        }
        if(mpp.find(prefixSum)== mpp.end()){ // zeros
            mpp[prefixSum] = i;
        }
    }
    return len;
}

// if the arrays only contains +ve the this solution is not optimal a two pointer solution would work
//TC -> O(2N)
// SC -> O(1)
int solve_opt(vector<int>arr,int k){
    int len =0;
    int left =0;
    int right = 0;
    int sum =0;
    while(right<arr.size()){
        while(left <=right && sum > k){
            sum -=arr[left];
            left --;
        }
        if(sum == k){
            len = max(len,right - left +1);
        }
        right++;
        if(right<arr.size()){
            sum +=arr[right];
        }
    }
}