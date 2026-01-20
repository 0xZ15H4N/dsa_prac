#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*

to revrse a stack using recursion 
first we will top each element from the stack until stack is empty 
secondly , we will push the elemnt back in to the stack with correct position just like we did in reverse_stack.cpp


*/

void insert_at_correct_position(stack<int>&stk,int top){
    if(stk.empty()){
        stk.push(top);
        return;
    }
    int new_top = stk.top();
    if(new_top<top){
        stk.push(top);
    }
    else{
        stk.pop();
        insert_at_correct_position(stk,top);
        stk.push(new_top);
    }
}


void sort_stack(stack<int>&stk){
    if(stk.empty()){
        return;
    }
    int top = stk.top();
    stk.pop();
    sort_stack(stk);
    insert_at_correct_position(stk,top);
}


int main(){

    stack<int>stk;
    stk.push(5);
    stk.push(-2);
    stk.push(9);
    stk.push(-7);
    stk.push(3);
    sort_stack(stk);
    while(!stk.empty()){
        cout<<stk.top();
        stk.pop();
    }

    return 0;
}