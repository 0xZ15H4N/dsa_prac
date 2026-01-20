#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*

using recursion we need to reverse a stack
we will insert_at bottom code for this one



*/

void insert_at_bottom(stack<int>&stk,int top){
    if(stk.empty()){
        stk.push(top);
        return;
    }
    int new_top = stk.top();
    stk.pop();
    insert_at_bottom(stk,top);
    stk.push(new_top);
}

void reverse_stack(stack<int>&stk){
    if(stk.empty()){
        return;
    }
    int top = stk.top();
    stk.pop();
    reverse_stack(stk);
    insert_at_bottom(stk,top);
}




int main(){

    stack<int>stk;
    for(int i= 0 ; i< 10;i++){
        stk.push(i);
    }

    reverse_stack(stk);
    while(!stk.empty()){
        cout<<stk.top();
        stk.pop();
    }

    return 0;
}