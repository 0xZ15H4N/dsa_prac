#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> arr = {7,8,8,8,9,9,9,9,1,1,1,2,3,4,4,5,6};
    int start = 0;
    int end = arr.size() - 1;
    while(start < end){
        int mid = start + (end - start)/2;
        if(arr[mid] >=arr[0]){
            start = mid +1;
        }else{
            end = mid;
        }
    }
    cout<<"Pivot element is at "<<end;
    return 0;
}