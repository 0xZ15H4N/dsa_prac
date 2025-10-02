#include<iostream>
#include<vector>
using namespace std;

// Space Complexity O(1)
// Time Complexity O(n^2)


int main(){

    vector<int> arr = {4,3,2,6,7,8,9,1};

    for(int i = 0; i < arr.size() - 1; i++){
        int mix_idx = i;
        for(int j = i+1;j<arr.size();j++){
            if(arr[mix_idx] > arr[j]){
                mix_idx = j;
            }
        }
        if(mix_idx !=i){
            swap(arr[i],arr[mix_idx]);
        }
    }
    for(auto i : arr){
        cout<<i<<" ";
    }
    return 0;
}