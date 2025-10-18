#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*


Now we are going to apply bubble sort using recursion
first we will sort the last element and 
recall the function with end = (size - 1) -1;
every time until the size-1 !=0;

edge case the size can be 0 or 1;
that will come under our base case also;

*/

void sort(int*arr,int size){
    if(size == 0 || size == 1){
        return ;
    } // this is the base case if size reach 1 for any array , then it returns


    // single case solve 

    for(int i =0;i<size-1;i++){
        if(arr[i] > arr[i+1]){
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    int temp = 0;
    while(temp!=size){
        cout<<arr[temp]<<" ";
        temp ++ ;
    }
    cout<<endl;

    //calling it recursively
    sort(arr,size-1);
}

int main(){


    int arr[] = {14,13,12,2,6,8,3,1,5,9,91,78,34,56,11};
    
    sort(arr,sizeof(arr)/sizeof(int));
    for(auto i : arr){
        cout<<i<<" ";
    }


    return 0;
}