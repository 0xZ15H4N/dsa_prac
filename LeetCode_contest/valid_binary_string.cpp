
#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

/*
Quick Notes
*/



class Solution {


private:
    void solve(vector<string> &ans, string &str, int index,int cost){
        if(index >= str.size()){
            if(validCost(str,cost)){
                ans.push_back(str);
            }
            return;
        }
        // Keep current bit as 0
            str[index] = '0';
            solve(ans, str, index + 1, cost);

            // Set current bit as 1
            str[index] = '1';
            solve(ans, str, index + 1, cost);
    }
    bool validCost(string str, int cost){
        int start = 0; 
        int end = str.size();
        int OneOccur = -1; // this will store the previous 1 
        int sum = 0;
        while(start < end){
            if(str[start] == '1'){
                if( OneOccur != -1 && OneOccur +1 == start){
                    return false;
                }
                OneOccur = start; // updating the OneOccur with new index;
                sum += start;     // adding the cost 
                if(sum > cost){
                    return false;
                }
            }
            start ++;
        }
        return true;
    }

public:
    vector<string> generateValidStrings(int n, int k) {
        string str = "";
        vector<string> ans;
        for(int i = 0; i < n; i++){
            str += '0';
        } // we will get this type of starting expression "000000..."
        int index = 0;
        solve(ans,str,index,k);
        return ans;
    }
};
 

int main(){
    Solution a;
    int n = 3;
    int k = 1;
    vector<string> ans = a.generateValidStrings(n,k);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}