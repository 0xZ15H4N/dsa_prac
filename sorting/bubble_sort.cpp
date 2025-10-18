#include<iostream>
#include<vector>
using namespace std;

// bubble sort Every ith Iteration the Ith largest element is sorted to it corrected position

// in the second for loop the iteration goes from 0 to arr.size() - i -1 , why -i is added cause we dont need to iterate 
// everytime to the last cause the last is already sorted

// Time Complexity O(n^2)
// Space Complexity o(1)

int main(){

    vector<int> arr = {14,13,12,2,6,8,3,1,5,9,91,78,34,56,11};

    for(int i = 0;i< arr.size()-1;i++){

        for(int j = 0;j<arr.size()-1-i;j++){
            if(arr[j]> arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        for(auto i : arr){
        cout<<i<<" ";
    }
        cout<<"\n";

    }

    return 0;

}