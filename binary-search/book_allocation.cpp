#include<iostream>
#include<vector>
using namespace std;


bool isPossible(vector<int>arr,int n , int m , int mid){

    int StudentCount = 1;
    int PageSum =0;

    for(int i = 0;i<n;i++){
        if(PageSum + arr[i] <= mid){
            PageSum +=arr[i];
        }else{
            StudentCount++;
            PageSum = arr[i];
            if(StudentCount > m || arr[i] > mid ){
                return false;
            }
        }
    }
    return true;

}


int main(){

    vector<int> arr = {10,20,30,40};
    int n = arr.size(); // total no of books
    int m = 2 ; // total no of students
    int sum = 0;
    if(m>n){
        return -1;// if no of students are greater then no of books how can we divide it!
    }
    for (auto i : arr){
        sum += i;
    }
    int start = 0;
    int end = sum;
    int ans = -1;
    while(start<=end){

        int mid = start + (end - start)/2;

        if(isPossible(arr,n,m,mid)){
            ans = mid;
            end = mid -1;
        }else{
            start  = mid + 1;
        }

    }

    cout<<"The minimum No of pages a student get is "<<ans;
    return 0;

}