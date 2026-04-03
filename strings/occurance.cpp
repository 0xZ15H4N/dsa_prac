#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
space complexity O(1)
time complexity  O(n)
*/

int main(){

    string s;
    vector<int>arr(26,0);
    cin>>s;
    for(int i = 0;i<s.size();i++){
        int num = 0;
        if(s[i]>='a' && s[i]<='z'){
            num = s[i] - 'a';
        }else{
            num = s[i] - 'A';
        }
        arr[num]++;
    }

    int maxi = INT_MIN, ch = 0;
    for(int i = 0 ; i< 26;i++){
        if(maxi < arr[i]){
            maxi = arr[i];
            ch = i;
        }
    }
    char ans = 'a'+ch;
    cout<<"frequency "<<maxi<<" char "<<ans;


    return 0;
}