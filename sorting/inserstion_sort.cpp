#include<iostream>
#include<vector>
using namespace std;


// in Inserstion sort we assume that 0th postion element is already sorted so we start with i = 1;
// Very Adaptable Algorithm,Stable algo
// TC -> O(n^2)
// SC -> O(1)

int main(){

    vector<int> arr = {2,5,1,6,3,66,8,10};

    for(int i = 1;i<arr.size() - 1; i++){
        int temp = arr[i];  // compare element store
        int j = i -1 ;      // initialised outside
        for( ;j>=0;j--){
            if(arr[j] > temp){  // back comparing the temp stored element
                arr[j+1] = arr[j];
            }else{
                break;
            }
        }
        arr[j+1] = temp; // now putting the element to its original position
    }

    for (auto i : arr){
        cout<<i<<" ";
    }
    return 0;

}