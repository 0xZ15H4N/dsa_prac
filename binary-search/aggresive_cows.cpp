#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
/*


Given an array of length ‘N', where each element denotes the position of a stall. Now you have
“N' stalls and an integer 'K’ which denotes the number of cows that are aggressive. To prevent
the cows from hurting each other, you need to assign the cows to the stalls, such that the
minimum distance between any two of them is as large as possible. Return the largest
minimum distance. x


*/
bool ispossible(vector<int>arr,int mid,int k){
    int cowCount = 1;
    int lastpos = arr[0];
    
    for(int i = 0;i<arr.size();i++){
        if(arr[i] - lastpos>=mid){
            cowCount++;
            if(cowCount==k){
                return true;
            }
            lastpos = arr[i];
        }
    }
    
    return false;
}

int main(){

    vector<int> arr = {4,2,1,3,6};
    int k = 2; // no of cows
    sort(arr.begin(),arr.end());
    int start = 0;
    int end = -1;
    for(auto i:arr){
        end = max(end,i);
    }
    int ans = -1;
    int i = 0;
    int size = arr.size();
    
    while(start<=end){
        int mid = start + (end - start)/2;
        if(ispossible(arr,mid,k)){
            ans = mid;
            start=mid+1;
        }else{
            end = mid-1;
        }
        i++;
    }
    cout<<ans;
    return 0;
}