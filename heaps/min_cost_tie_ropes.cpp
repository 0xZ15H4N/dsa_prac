#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int min_cost_tie_ropes(vector<int> &arr){
    priority_queue<int,vector<int>,greater<int>> pq; // minimum heap

    for(auto i : arr){
        pq.push(i);
    }
    while(pq.size()>1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a+b);
    }
    return pq.top();
}