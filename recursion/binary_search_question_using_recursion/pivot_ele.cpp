#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
pivot element in rotated - sorted array using binary search with RECURSION

to find the pivot we start with start < end  -> base case; return start;
if(mid > arr[0]) search(&arr[mid+1],arr[end])
if(mid < arr[end]) search(&arr[start],arr[mid])


*/

int pivot(int arr[],int start, int end){

    
    if(start >= end){
        return start;
    }
    int mid = start + (end - start)/2;
    if(arr[mid] > arr[0]){
        
        return pivot(arr,mid+1,end);
    }
        else{
        return pivot(arr,start,mid);
    }
}


int main(){

    int arr[] = {50, 60, 70, 80, 90, 100, 10, 20, 30, 40};

    cout<<pivot(arr,0,9);

    return 0;
}