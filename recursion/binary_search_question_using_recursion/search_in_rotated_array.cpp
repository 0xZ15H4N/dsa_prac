#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*

Now searchin in the rotated array 
* find the pivot in the array 
* apply binary search in the array base of if target > pivot && target < arr[end] search in right half
  else search in left half

*/

int binarySearch(int arr[], int start, int end, int target) {
    if (start > end)
        return -1; // Not found

    int mid = start + (end - start) / 2;

    if (arr[mid] == target)
        return mid;
    else if (target < arr[mid])
        return binarySearch(arr, start, mid - 1, target);
    else
        return binarySearch(arr, mid + 1, end, target);
}

// Recursive pivot finder
int findPivot(int arr[], int start, int end) {
    if (start == end)
        return start;

    int mid = start + (end - start) / 2;

    if (arr[mid] > arr[end])
        return findPivot(arr, mid + 1, end);
    else
        return findPivot(arr, start, mid);
}

// Search in rotated sorted array using pivot
int searchRotated(int arr[], int n, int target) {
    int pivot = findPivot(arr, 0, n - 1);

    // If target is the pivot
    if (arr[pivot] == target)
        return pivot;

    // Decide which subarray to search
    if (target >= arr[0])
        return binarySearch(arr, 0, pivot - 1, target);
    else
        return binarySearch(arr, pivot + 1, n - 1, target);
}
int main(){

    int arr[] = {50, 60, 70, 80, 90, 100, 10, 20, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target1 = 30;



    int idx1 = searchRotated(arr, n, target1);

    cout << "Element " << target1 << " found at index " << idx1 << endl;





    return 0;
}