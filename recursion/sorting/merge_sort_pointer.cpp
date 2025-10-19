#include <iostream>
using namespace std;

// Merge two sorted halves in-place using pointers
void inPlaceMerge(int* start, int* mid, int* end) {
    int* start2 = mid + 1;

    // If already sorted, skip merging
    if (*mid <= *start2)
        return;

    while (start <= mid && start2 <= end) {
        if (*start <= *start2) {
            start++;
        } else {
            int value = *start2;
            int* index = start2;

            // Shift all elements between start and start2 right by one
            while (index != start) {
                *index = *(index - 1);
                index--;
            }
            *start = value;

            // Update all pointers
            start++;
            mid++;
            start2++;
        }
    }
}

// Recursive merge sort using pointers
void mergeSort(int* start, int* end) {
    if (start >= end)
        return;

    int* mid = start + (end - start) / 2;

    mergeSort(start, mid);
    mergeSort(mid + 1, end);

    inPlaceMerge(start, mid, end);
}

int main() {
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, arr + n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
