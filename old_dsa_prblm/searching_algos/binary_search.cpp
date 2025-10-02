#include<iostream>


int binary_search(int arr[],int size ,int key){

    int start = 0; //index value of first element
    int end = size - 1; //index value of last element
    int mid = start + (end - start )/2; // for the optimisation as the size of int is 2^31 -1 so start + end will theoratically can give a number greater than that so we optimise our soulution so it donot give us a greater numbr then int range!

    while(start <= end ){

        if(arr[mid]==key){
            return mid;
        }
        if(key < arr[mid]){
            end =  mid  - 1 ;
        }
        if(key > arr[mid]){
            start = mid + 1;
        }
        mid = start + (end - start )/2;
    } 
    return -1;
}

int main(){

    int arr[] = {1,2,3,4,5,6,7,8,9};
    int key = 10;
    
    std::cout<<"the value "<<key<<" found in the array at "<<binary_search(arr,sizeof(arr)/sizeof(int),key)<<std::endl;

    return 0;


}