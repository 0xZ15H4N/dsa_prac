#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arr = {7,8,9,1,2,3,4,5,6};
    int target = 8;
    int start = 0;
    int end = arr.size() -1 ;
     // finding the pivot
    while(start <end){
        int mid = start + (end-start)/2;
        if(arr[mid] > arr[0]){
            start = mid + 1;
        }else{
            end = mid;
        }
    }
    cout<<"Pivot element @ "<<start<<endl;

// pivot divides the array in two 

// condition if target is in the second split of the array

    if((arr[start] <= target) && (arr[arr.size() - 1] >= target)){ 
        end = arr.size() -1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(arr[mid] == target){
                cout<<"Element @ "<<mid<<" and the element is "<<arr[mid];
                return 0;
            }else if(arr[mid] > target){
                end = mid - 1;
            }else{
                start = mid+1;
            }
        }
    }else{ // else if the target is in first split of the array
        start = 0;
        end = end - 1; // cause we already have end = mid while finding the pivot
        while(start <= end){
            int mid = start + (end-start)/2;
            if(arr[mid] == target){
                cout<<"Element @ "<<mid<<" and the element is "<<arr[mid];
                return 0;
            }else if(arr[mid] > target){
                end = mid - 1;
            }else{
                start = mid+1;
            }
        }

    } 

}