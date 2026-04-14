#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*


we will search the array or base case would be that if the element found at arr[0] return True!

*/

bool search(int arr[],int size,int target){

    if(size <= 0)
        return false;

    if(arr[0] == target)
        return true;

    else
        return search(&arr[1],--size,target);

}


int main(){

    int arr[] = {47, 12, 89, 33, 5, 71, 24, 68, 91, 40};

    cout<<"The elment 100 in that : "<<search(arr,10,100);
    cout<<"The elment 89 in that : "<<search(arr,10,89);

    return 0;
}