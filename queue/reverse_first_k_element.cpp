#include<iostream>
#include<bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int>Q,int K){
    stack<int> stk;
    for(int i=0;i < K; i++){
        stk.push(Q.front());
        Q.pop();
    }
    while(!stk.empty()){
        Q.push(stk.top());
        stk.pop();
    }
    int steps = Q.size() - K;
    while(steps--){
        Q.push(Q.front());
        Q.pop();
    }
    return Q;
}