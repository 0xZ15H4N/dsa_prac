#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// merging two sorted array


/*

this is a simple approach we just iterate through both arry simutaneouly using the while loop and check if the arr1[m] >< arr2[k] 
and then increament as follows

*/

int main(){

    vector<int> arr1 = {1,3,5,7};
    vector<int> arr2 = {2,4,6,8};
    
    int i = arr1.size();
    int j = arr2.size();
    int p = i + j;
    
    int m =  0;
    int k = 0;
    int l = 0;
    vector<int> arr3(p);
    
    while(m<i && k <j){
        if(arr1[m] < arr2[k]){ // here arr2 has the smaller element 
            arr3[l++] = arr1[m++];
        }else{
            arr3[l++] = arr2[k++];  // if arr1 have a bigger element
        }
    }
    while(m < i ){
        arr3[l++] = arr1[m++];
    }

    while(k < j){
        arr3[l++] = arr2[k++];

    }

    for(auto i : arr3){
        cout<<i<<" ";
    }
    return 0;


}