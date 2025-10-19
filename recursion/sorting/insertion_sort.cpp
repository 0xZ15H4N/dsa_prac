#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*

base case
start >= size   
    return;

//
start -> 1;
int j = start-1;
int temp = arr[start]
for(;j>=0;j--){
    if(arr[temp] < arr[j])
        arr[j+1] = arr[j];
}

arr[j+1]= temp ;
func(arr,start+1,size);

*/

void InsertionSort(int* arr,int start,int size){
    if(size == 0 || size ==1 ){
        return;
    }
    if(start >= size){
        return;
    }
    int j = start -1; // previous index
    int temp = arr[start]; //current element  we didnot hold the index cause the element at the index get updated
    for(;j>=0;j--){
        if(temp<arr[j]){
            arr[j+1] = arr[j];
        }else{
            break;
        }
    }
    arr[j+1] = temp; 
    InsertionSort(arr,start+1,size);
}

int main(){

    int arr[] = {2,5,1,6,3,66,8,10};

    InsertionSort(arr,1,sizeof(arr)/sizeof(int));
    for(auto i : arr){
        cout<<i<<" ";
    }

    return 0;
}