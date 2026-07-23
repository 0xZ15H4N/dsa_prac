#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Given alien dictionary we need to extract the arrange ment of the alphabets

Dictionary       , k = 4 , denotes the total of 4 alphabets are being used
            baa
            abcd
            abca
            cab
            cad
    now if we compare each and every character of the string from the other 
  1  baa and abcd , b comes before a so 
    order of b a   (b -> a)

  2 abcd abca , d comes before a so
    order b d a (d -> a)
  
  3 abca cab , a comes before c
    order b d a c (a -> c)
 
  4 cab cad , b comes before d
    final order : b d a c 

    graph 

                b -> a -> c
                |  /
                V /
                D

    1 if we some how create a adjacent list 
    2 apply topological sort we can get the order of the alphabets
*/

class Solution {
public:
    string findOrder(vector<string> &words) {
        
        vector<int>charArr(26,0);
        int count = 0;
        for(auto i : words){
            for(auto j : i){
                if(charArr[j - 'a'] == 0){
                    charArr[j-'a'] = 1;
                    count++;
                }
            }
        }

        vector<vector<int>>adjls(26);
        queue<int>q;
        string ans;
        vector<int>inDegree(26);
        
        for(int i =0 ; i < words.size()-1;i++){
            string s1 = words[i];
            string s2 = words[i+1];
            int len = min(s1.size(),s2.size());
            int ptr= 0;
            while(ptr < len){
                int u = s1[ptr] - 'a';
                int v = s2[ptr] - 'a';
                
                bool exists = false;
                // checks for duplicate entries
                for(int x : adjls[u]){
                    if(x == v){
                        exists = true;
                        break;
                    }
                }
                if(!exists)
                    adjls[u].push_back(v);
            }
            // check if bigger string is before smaller string
            if(ptr == len && s1.size() > s2.size()){
                    return "";
            }
        }
        
        for(int i = 0; i<26;i++){
            for(auto j : adjls[i]){
                inDegree[j]++;
            }
        }
        for(int i = 0; i < 26;i++){
            if(inDegree[i] == 0 && charArr[i] == 1){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int top = q.front();
            q.pop();
            ans += top + 'a';
            for(auto i : adjls[top]){
                inDegree[i]--;
                if(inDegree[i] == 0){
                    q.push(i);
                }
            }
        }
        
        // check if there are any loops in the array or not
        if(ans.size()!= count){return "";}
        return ans;
    }
};