#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*


remove middle element from the stack 
we will use recursion for this
*/

void remove_middle(stack<int>&stk,int count,int size){
    if(count==size/2){
        stk.pop();
        return;
    }
    int top = stk.top();
    stk.pop();
    remove_middle(stk,count++,size);
    stk.push(top);
}

int main(){
    stack<int>stk;
    for(int i =0;i<5;i++){
        stk.push(i);
    }
    remove_middle(stk,0,stk.size());
    while(!stk.empty()){
        cout<<stk.top();
        stk.pop();
    }
    return 0;
}