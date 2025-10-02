#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};
    size_t  target = 5;
    size_t r_size = arr.size();
    auto c_size = arr[0].size();
    int start = 0;
    int end = (r_size*c_size) - 1;
    while(start <= end){
        int mid = start + (end - start)/2;
        int ele = arr[mid/c_size][mid % c_size]; // this is the learning part
        cout<<"element is "<<ele;
        if(target == ele){
            printf("The element is at arr[%d][%d]",mid/c_size,mid%c_size);
            return 0;
        }
        if(target < ele){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    cout<<"couldnt find the fucking element!";
    return 0;
}