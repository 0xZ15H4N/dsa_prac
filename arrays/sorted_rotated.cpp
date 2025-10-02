#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int>arr = {7,8,9,1,2,3,4,5,6};

    int count = 0;
    for(int i = 0;i<arr.size()-1;i++){
        if(arr[i]> arr[i+1]){
            count ++ ;
        }
    }
    if(arr[0] < arr[arr.size()-1]){
        count++;
    }
    if(count == 1){
        cout<<"the Array is rotated and sorted";
    }else{
        cout<<"the Arrray is not sorted and rotated";
    }


}