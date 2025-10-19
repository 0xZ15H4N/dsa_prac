#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
base case 
int min_idx;
int check;
for(int i =0;i<size-1;i++){
if(arr[i] > arr[i+1]){
    min_idx = i+1;
    }
}


*/

void SelectionSort(int * arr,int start,int size){


    if(size<=1){
        return;
    }
    if(start >= size){
        return ;
    }
    int min_idx = start;
    for(int i  = start+1 ;i<size;i++){
        if(arr[min_idx] > arr[i] ){
            min_idx = i;
        }
    }
    if(min_idx != start){
        // swap them
        int temp = arr[min_idx];
        arr[min_idx] = arr[start];
        arr[start] = temp;
    }
    SelectionSort(arr,start+1,size);

}


int main(){


    int arr[] = {4,3,2,6,7,8,9,1};
    SelectionSort(arr,0,sizeof(arr)/sizeof(int));

    for(auto i : arr){
        cout<<i<<" ";
    }

    return 0;
}