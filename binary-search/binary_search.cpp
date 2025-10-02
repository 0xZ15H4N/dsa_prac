#include<iostream>
#include<vector>

using namespace std;

// Time Complexity O(logn)
// Space Complexity O(1)

int main()
{
    vector<int>arr = {1,2,3,4,5,6,7,8,9};
    int start = 0;
    int end   = arr.size() - 1;
    while(start <= end ){
        int mid = start + (end - start )/2;
        if(arr[mid] == 6){
            cout<< " Found 6 @" << mid;
            break;
        }else if(arr[mid] >  6){
            end = mid - 1;

        }else{
            start = mid + 1;
        }

    }
    return 0;
}