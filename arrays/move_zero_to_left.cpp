#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*


Quick-Notes


*/
int main(){
    vector<int>arr = {2,0,3,1,0,0,0};
    int non_zero = 0;
    for(int i = 0; i<arr.size();i++){
        if(arr[i]==0){
            swap(arr[i],arr[non_zero]);
            non_zero++;
        }
    }
    for(auto i : arr){
        cout<< i<< " ";
    }


    return 0;
}