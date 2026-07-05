#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[],int size, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2* i + 2;
    if(left < size  && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < size  && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest] , arr[i]);
        heapify(arr,size,largest);
    }
}


int main(){

    int arr[] = {70,60,55,45,50};  // this array is already heapified!
    int size = 4;
    while(size >= 1){
        swap(arr[0],arr[size]);
        size--;
        heapify(arr,size,0);
    }
    for(auto i : arr){
        cout<< i << " ";
    }
    cout<<endl;
    return 0;
}