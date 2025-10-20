#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*


in quick sort we first take a pivot from the array usually 0th indx element then count all the elements smaller than it
and move the pivot element to its correct spot using 0(pivot idx) + count ,after that we need to make sure that 
element in the left of the pivot  is smaller and elements in the right is bigger
 
the condition should be like this [a>] a [<a]
after that it returns the new pivot element idx and we recall the quick sort fnc from (s,p-1),(p+1,e)

worst case complexity is O(n^2)
average case and best case complexity is O(nlogn)


*/

int partition(int *arr,int start,int end){
    int pivot;

    int pivot_element = arr[start];
    int count = 0;
 // we dont start from the start position we start from the start + 1 cause the pivot is already siting at index start 
    for(int i = start+1;i<=end;i++){
        if(arr[i]<=pivot_element){
            count++;
        }
    }
    pivot = start+count;

    // switching the pivot with its correct index
    int temp = arr[pivot];
    arr[pivot] = pivot_element;
    arr[start] = temp;

    int i = start , j = end;
    while(i < pivot && j > pivot){
       while(arr[i] < pivot_element){
        i++;
       }
       while(arr[j] > pivot_element){
        j--;
       }

       if(i < pivot && j > pivot){
        swap(arr[i++],arr[j--]);
       }
    }

    return pivot;

}


void quickSort(int * arr,int start,int end){


    //base case 
    if(start>=end){
        return;
    }

    int pivot = partition(arr,start,end);
    quickSort(arr,start,pivot-1);
    quickSort(arr,pivot+1,end);
}




int main(){

    int arr[] ={2,5,1,6,3,66,8,10};
    quickSort(arr,0,sizeof(arr)/sizeof(int)-1);
    

    for(auto i : arr){
        cout<<i<<" ";
    }
    return 0;
}