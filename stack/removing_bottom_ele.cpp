#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
remove bottom element from the stack 
we will use recursion for this
*/

void remove_bottom(stack<int>&stk,int top){
    if(stk.empty()){
        stk.push(1000);
        return;
    }
    int new_top = stk.top();
    stk.pop();
    remove_bottom(stk,new_top);
    stk.push(top);
}



int main(){

    stack<int>stk;
    for(int i = 0; i<10;i++){
        stk.push(i);
    }

    int top = stk.top();
    stk.pop();
    remove_bottom(stk,top);
    while(!stk.empty()){
        cout<<stk.top();
        stk.pop();
    }
    return 0;
}