#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*

Now we need to recursively calculate the sum of each element in an array

*/

int sum(int arr[],int size){

    int sum_ = 0;
    if(size <= 0){ // base case 
        return 0; 
    }else{
        sum_ += arr[--size] + sum(arr,size);
    }
    return sum_;
}

int sum(int arr[], int size) {
    if (size <= 0)
        return 0;
    return arr[0] + sum(arr + 1, size - 1);
}



int main(){

    int arr[] = {1,2,3,4,5,6,7,8,9};

    cout<<sum(arr,9);

    return 0;
}