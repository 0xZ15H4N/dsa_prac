#include<iostream>
#include<vector>
using namespace std;
void reverse(vector<int>&);
int main(){
    vector<int> arr1 = {1,2,3,2,2,2,2,2,2};
    vector<int> arr2 ={4,0,0,8};
    vector<int> arr3;

    int carry = 0;
    int size1 = arr1.size()-1;
    int size2 = arr2.size()-1;
    
    while(size1>=0 && size2>=0){
        int sum = arr1[size1] + arr2[size2] + carry;
        carry = sum / 10;
        sum = sum % 10;
        arr3.push_back(sum);
        size1--;
        size2--;
    }
    while(size1>=0){
        int sum = arr1[size1] + carry ;
        carry = sum /10;
        sum = sum % 10;
        arr3.push_back(sum);
        size1--;
    }
    while(size2>=0){
        int sum = arr2[size2] + carry ;
        carry = sum /10;
        sum = sum % 10;
        arr3.push_back(sum);
        size2--;
    }
    while(carry !=0){
        int sum = carry;
        carry = sum /10;
        sum = sum % 10;
        arr3.push_back(sum);
    }
    reverse(arr3);
    for(auto i : arr3){
        cout<<i<<" ";
    }

    return 0;
}

void reverse(vector<int> &arr){
    int start = 0;
    int end = arr.size()-1;
    while(start <end){
        swap(arr[start++],arr[end--]);
    }
}