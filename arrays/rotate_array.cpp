#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> arr= {1,2,3,4,5,6,7}; // ->  {4,5,6,7,1,2,3}
    int rot = 4;
    vector<int> temp(arr.size());
    for(int i = 0; i <arr.size();i++){
        temp[(i+rot)%arr.size()] = arr[i];
    }
    arr = temp;
    for(auto i : arr){
        cout<<i<<" ";
    }
    return 0;
}

/*
✅ In-place Rotation (O(1) space)

For rotating right by rot:
Reverse the whole array
Reverse the first rot elements
Reverse the remaining n - rot elements


int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int rot = 4;
    int n = arr.size();
    
    rot %= n; // handle rot > n
    
    // Step 1: reverse whole array
    reverse(arr.begin(), arr.end());
    
    // Step 2: reverse first rot elements
    reverse(arr.begin(), arr.begin() + rot);
    
    // Step 3: reverse the rest
    reverse(arr.begin() + rot, arr.end());
    
    for (auto x : arr) cout << x << " ";
    
    return 0;
}
*/