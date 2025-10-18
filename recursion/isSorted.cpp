#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*

also the edge case is that Single element in an array is also sorted. size=1; 
and No element in an array is Also sorted.                            size=0;

we are going to access two elements at a time and check if the previous one is smaller than the after one
after that i will call the function again but this time one shifted array from the start
1st call -> isSorted(arr[0],size);  camparision(arr[0] > arr[1]);
2nd call -> isSorted(arr[1],size);  camparision(arr[0] > arr[1]); but here arr[0] act. arr[1]


*/

bool isSorted(int arr[],int size){
    if(size == 0 || size == 1){
        return true;
    }

    if(arr[0] > arr[1]){
        return false;
    }else{
        isSorted(&arr[1],--size);
    }

}




int main(){

    int arr1[] = {};
    int arr2[] = {1};
    int arr3[] = {1,2,3,4,5,6,7,8,9};
    int arr4[] = {6,10,9};

    cout<<isSorted(arr1,0)<<endl;
    cout<<isSorted(arr2,1)<<endl;
    cout<<isSorted(arr3,9)<<endl;
    cout<<isSorted(arr4,3)<<endl;




    return 0;
}