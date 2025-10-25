#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*

in this we have a keypad in which we type the number let say 34 the total combination of two letter subset can be
since at 3 ->def
         4 ->ghi

         well we could only be typeing a single digit like 2 and the possible outcome would be {"a" "b" "c"}
so the number to two letter words are dg dh di eg eh ei fg fh fi
                                           i
first we will do                           23
                        value ->           abc for loop karenge
                                     /      |           \                     
                                  a         b            c -> output
                        value -> def       def          def      for loop 
                                / | \    /  |  \      /  | \             
                              ad ae af   bd be bf    cd ce cf -> output   
                              
                                    ans.push_back(output)   
                              return      return        return i>= digits.size()
                               
                              */

void solve(string digits,vector<string>&ans,int index,string output,string keypad[]){

    if(index >=digits.size()){
        ans.push_back(output);
        return;
    }

    string value = keypad[digits[index] - '0']; 
    
    for(int i = 0;i<value.size();i++){
        output.push_back(value[i]);
        solve(digits,ans,index+1,output,keypad);
        output.pop_back();
    }
}

int main(){

    string keypad[] = {"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string>ans;
    string output;
    int index = 0;
    string digits;
    cin >> digits;
    solve(digits,ans,index,output,keypad);
    for(auto i : ans){
        cout<<i<<" ";
    }
    
    return 0;

}