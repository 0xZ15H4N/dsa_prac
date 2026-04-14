#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
what we are doing here is moving a pointer along the array and 
if non zero is found we replace the is replace with position the pointer is pointing to
i.e. place where zero is 
*/


int main(){
    vector<int> arr = {2,0,3,1,0,0,0}; // final result = {2,3,1,0,0,0,0}

    int zero = 0;
    for(int i = 0;i<arr.size();i++){
        if(arr[i] !=  0){
            swap(arr[i],arr[zero]);
            zero++;
        }
    }
    for(auto i : arr){
        cout<< i<< " ";
    }
    return 0;
}