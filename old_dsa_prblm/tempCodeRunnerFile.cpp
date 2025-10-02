#include<iostream>
using namespace std;


void insertion_sort(int arr [] , int n){
    // for(int i =  0 ;i<= n-1;i++){
    //     int j = i;
    //     while(j>0&& arr[j-1] > arr[j]){
    //         int temp = arr[j-1];
    //         arr[j-1] = arr[j];
    //         arr[j] = temp;
    //         j--;
    //     }
    // }
    // for(int i = 0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        for(;j>=0;j--){
            if(arr[j]>temp){
                arr[j+1]=arr[j];
            }
            else{
                break;
            }

        }
        arr[j+1]=temp;
    }
}

int main(){
    int arr[] = {2,3,4,5,1,6,2,4,68,65,1};
    insertion_sort(arr,sizeof(arr)/sizeof(int));
    for(int i=0;i<sizeof(arr)/4;i++){
        cout<<arr[i]<<" ";
    }


}