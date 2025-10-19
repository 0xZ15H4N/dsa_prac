#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*

[2,6,1,8,9] 
divide the array into two parts [2,6,1] [8,9]
divide the arrys into two parts until single element left [2,6] [1] [8] [9]
divide the arrays into two parts [2] [6] [1] [8] [9]
now merge them while sorting [2,6] [1] [8,9]
now merge them [1,2,6] [8,9]
now merge them [1,2,6,8,9]


approach 
    base case s>= e -> return;
    first we will seperate the array using mid into half and call the mergeSort in the left half and inthe right half using the s, e
    in left half we will call with mergeSort(arr,s,mid) and in right half we will call mergeSort(arr,mid+1,e);
    until s>=e after that single item returns and we call merge(arr,s,e) just like merge two sorted array


*/
void merge(int * arr,int start,int end){

    int mid = start + (end-start)/2;

    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *arr1= new int[len1];
    int *arr2= new int[len2];


    // making the cpy of the array cause we are going to make changes in the main array
    // so the element in the main array are going to be changed so we need the copy of it in somewhere
    //copying the subarray from the main array
    int temp = start;
    for(int i = 0;i<len1;i++){
        arr1[i]= arr[temp++];
    }
    temp = mid+1;
    for(int i = 0;i<len2;i++){
        arr2[i]= arr[temp++];
    }
    // merging the two sorted array

    int m = 0;
    int n = 0;
    temp = start;
    while(m<len1 && n< len2){
        if(arr1[m] < arr2[n]){  // left subarray has a smaller element in it.
            arr[temp++] = arr1[m++]; 
        }else{
            arr[temp++] = arr2[n++];
        }
    }

    while(m<len1){
        arr[temp++] = arr1[m++]; 
    }
    while(n<len2){
        arr[temp++] = arr2[n++];  
    }
}



void mergeSort(int* arr,int start,int end){

    if(start>=end)
        return;

    int mid = start + (end - start)/2;

    // mergeSort in left 
    
    mergeSort(arr,start,mid);


    // mergeSort in right
    mergeSort(arr,mid+1,end);

    //now we merge the two sorted array
    merge(arr,start,end);
}




int main(){


   int arr[] = {2,5,1,6,3,66,8,10};
   mergeSort(arr,0,sizeof(arr)/sizeof(int));
   for(auto i : arr){
    cout<<i<<" ";
   }
   return 0;
}