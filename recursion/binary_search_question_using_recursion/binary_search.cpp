#include<iostream>
#include<bits/stdc++.h>
using namespace std;


bool binary_search(int arr[],int target,int start, int end){

    int mid = start + (end - start) / 2;
    if(start > end){  // base case
        return false;
    }
    if (arr[mid] == target)
        return true;
    else if (arr[mid] > target)
        return binary_search(arr, target, start, mid - 1);
    else
        return binary_search(arr, target, mid + 1, end);

}


int main(){


    int arr[] = {1,2,3,4,5,6,7,8,9};
    int target = 7;
    bool found = binary_search(arr,target,0,sizeof(arr)/sizeof(int));

    if(found){
        cout<<"ELEMENT FOUND NIGGA";
    }else{
        cout<<"NOT FOUND NIGGA";
    }

    return 0;
}