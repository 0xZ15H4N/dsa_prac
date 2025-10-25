#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*


This question is same as finding subset of an Array 
in this we just need to find the subsequence and append it in the vector<string>ans
if included we need to concatinate not append it into the output
and if excluded we just need to move the index +1



*/
// this was a recursion approach 
void solve(string input,string output,vector<string>&ans,int index){
    if(index>=input.size()){
        if(output !="")
            ans.push_back(output);
        return;
    }
    // exclude
    solve(input,output,ans,index+1);
    //include
    output+=input[index];
    solve(input,output,ans,index+1);
}

// this is  bit manipulation approach

vector<string> generateSubsequences(string s) {
    int n = s.length();
    vector<string> result;

    // Total number of subsequences = 2^n
    int total = 1 << n; // same as pow(2, n)

    for (int mask = 0; mask < total; mask++) {
        string temp = "";
        for (int i = 0; i < n; i++) {
            // if the i-th bit is set, include s[i]
            if (mask & (1 << i)) {
                temp += s[i];
            }
        }
        result.push_back(temp);
    }

    return result;
}

int main(){

    string input = "zis";
    vector<string>ans;
    string output = "";
    int index = 0;
    solve(input,output,ans,index);
    for(auto i : ans){
        cout<<i<<endl;
    }


    return 0;
}