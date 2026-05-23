#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// this was my solution i used move zero to left
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero_index = 0;
        int one_index = 0;
        int two_index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                swap(nums[i], nums[zero_index]);
                zero_index++;
            }
        }
        one_index = zero_index;
        for (int i = zero_index; i < nums.size(); i++) {
            if (nums[i] == 1) {
                swap(nums[i], nums[one_index]);
                one_index++;
            }
        }
        two_index = one_index;
        for (int i = one_index; i < nums.size(); i++) {
            if (nums[i] == 1) {
                swap(nums[i], nums[two_index]);
                two_index++;
            }
        }
    }
};

// we can use dutch national flag algorithm

void sort012(vector<int> &arr) {
    int n = arr.size();
    
    // initialize three pointers:
    // lo: boundary for 0s
    // mid: current element being checked
    // hi: boundary for 2s
    int lo = 0;
    int hi = n - 1;
    int mid = 0;
    
    // process elements until mid crosses hi
    while (mid <= hi) {
        if (arr[mid] == 0) {
            
            // current is 0: swap with lo and move both 
            // pointers forward
            swap(arr[lo++], arr[mid++]);
        }
        else if (arr[mid] == 1) {
            // current is 1: it's already in correct position
            mid++;
        }
        else {
            // current is 2: swap with hi and move hi backward
            // do not increment mid, as swapped value needs
            // to be re-checked
            swap(arr[mid], arr[hi--]);
        }
    }
}
