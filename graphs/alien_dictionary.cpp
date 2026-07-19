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



vector<int> topoSort(vector<vector<int>>adjLs){
    int Nodes = adjLs.size();
    vector<int> inDegree(Nodes,0);
    queue<int>q;
    vector<int> ans;
    for(int i = 0 ; i < Nodes; i++){
        for(auto it : adjLs[i]){
            inDegree[it]++;
        }
    }

    for(auto i = 0; i < Nodes; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int top = q.front();
        q.pop();
        ans.push_back(top);
        for(auto i : adjLs[top]){
            inDegree[i]--;
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

    }
    return ans;
}


void alien_dictionary(vector<string>dictionary,int k){
    int words = dictionary.size();
    vector<vector<int>>adjLs(k);

    // adjacent list is created
    for(int i = 0; i < words - 1; i++){
        string s1 = dictionary[i];
        string s2 = dictionary[i+1];
        int minLen = min(s1.size(),s2.size());
        for(int i  = 0; i < minLen; i++){
            if(s1[i] != s2[i]){
                adjLs[s1[i] - 'a'].push_back(s2[i]-'a');
                break;
            }
        }
    }

    vector<int> topoList = topoSort(adjLs);
    for(auto i : topoList){
        cout << char(i + 'a') << " ";
    }
}


int main(){
    vector<string> dictionary = {"baa","abcd","abca","cab","cad"};
    cout<<"printing the dictionary ";
    alien_dictionary(dictionary,4);
    return 0;
}