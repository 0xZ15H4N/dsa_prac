#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void heapify(vector<int> &arr ,int n, int i){
    int largest = i;
    int left = 2* i + 1;
    int right = 2* i + 2;
    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

vector<int> MergeTwoHeap(vector<int> arr1 ,vector<int> arr2 ){
    int n = arr1.size();
    int m = arr2.size();
    vector<int> arr3;
    for(auto i : arr1){
        arr3.push_back(i);       
    }
    for(auto i : arr2){
        arr3.push_back(i);
    }
    int size = (n+m) / 2;
    for(int i = size-1; i>=0; i -- ){
        heapify(arr3,n+m,i);       
    }
    return arr3;
}


int main() {
    vector<int> arr1 = {10, 5, 6, 2};
    vector<int> arr2 = {12, 7, 9};

    vector<int> ans = MergeTwoHeap(arr1, arr2);

    for (int x : ans)
        cout << x << " ";
}