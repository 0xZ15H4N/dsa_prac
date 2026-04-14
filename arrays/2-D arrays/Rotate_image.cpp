#include<iostream>
#include<vector>
using namespace std;

// to rotate the 2-D matrix with 90degree
// first we will transpose it 
// them we will reverse each row

int main(){

    vector<vector<int>> arr= {{1,2,3},{4,5,6},{7,8,9}};

    // transposing the matrix

    int size = arr.size();
    for(int i = 0;i<size-1;i++){
        for(int j = i+1; j<size;j++){
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
            
        }
    }


    // reversing each row;

    for(int i = 0;i < size; i++){
        int start = 0;
        int end = arr[i].size()-1;
       while(start < end){
            int temp = arr[i][start];
            arr[i][start] = arr[i][end];
            arr[i][end] = temp;
            start++;
            end--;
        }
    }

    for(int i = 0;i<size;i++){
        for(int j = 0;j<size;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}