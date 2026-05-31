#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int arr[]  = {3, 4, 2, 1, 6, 0, 8}; // 0 1 2 3 4 6 8
    priority_queue<int> pq;
    int k  = 4;
    // PQ.TOP WILL CONTAIN THE LARGEST FROM THE FIRST K ELEMENTS
    // IF WE KEEP POPING & PUSHING THE SMALLER ELEMENTS (PQ.TOP > ARR[I])
    // THE HEAP WILL CONTAIN FIRST K SMALLEST ELEMENTS AT LAST 
    // AT TOP IT WILL CONTAIN THE KTH SMALLEST ELEMENTS
    for(int i = 0; i<k;i++){
        pq.push(arr[i]);
    }

    for(int i = k; i< 7; i++){
        if(pq.top() > arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    cout<<pq.top();

    return 0;
}