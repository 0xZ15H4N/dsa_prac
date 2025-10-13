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