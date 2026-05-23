#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;
        string ans = "";
        string temp = "";
        for(auto i : s){
            if(mpp.find(i) == mpp.end()){
                mpp[i] = 1;
                temp+=i;
            }else{
            temp = "";
            mpp.clear();
            }
            ans = ans.size() > temp.size() ? ans : temp;
        }
        return ans.size();
    }
};


int main(){

    vector<pair<string, int>> testCases = {
    {"abcabcbb", 3},
    {"bbbbb", 1},
    {"pwwkew", 3},

    {"", 0},
    {"a", 1},
    {"aa", 1},
    {"ab", 2},

    {"dvdf", 3},
    {"abba", 2},
    {"tmmzuxt", 5},
    {"anviaj", 5},
    {"abcadef", 6},

    {"abcdef", 6},
    {"qwerty", 6},
    {"abcdefghijklmnopqrstuvwxyz", 26},

    {"abababab", 2},
    {"abcabcabc", 3},
    {"aab", 2},
    {"baa", 2},

    {" ", 1},
    {"au", 2},
    {"cdd", 2},
    {"ohomm", 3},
    {"ckilbkd", 5},

    {"aaaaaaaaaa", 1},
    {"aaaabbbbcccc", 2},
    {"abcdedcba", 5},

    {"!@#$%^&*()", 10},
    {"a!b@c#d$", 8},
    {"a a b", 3},

    {"123451234", 5},
    {"1122334455", 2},
    {"1234567890", 10}
};
    Solution sol;
    // calcuating the numbers of solution correct 
    int correctCount = 0;
    for(const auto& test : testCases){
        if(sol.lengthOfLongestSubstring(test.first) == test.second){
            correctCount++;
        }
    }    cout << "Correct Solutions: " << correctCount << " out of " << testCases.size() << endl;
    return 0;
}