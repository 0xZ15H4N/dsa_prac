#include<iostream>
#include<vector>
using namespace std;

/*

Write the efficient algorithm that searches for a target value in an MxN
It should follow
-> Integers in each rows are sorted in ascending from left to rigth
-> Intergers in each colums are sorted in ascending from top to bottom

*/

/*

To Solve this what we will do is 
    first rowIndex -> 0
          colIndex -> Nofcolumns - 1;
          row = arr.size();
          col = arr[0}.size();

    while(rowIndex < row && colIndex >=0)
    if(target) > arr[rowIndex}[colIndex} -> rowIndex++;
    else colIndex --;
    with this we will decrease our search space with each iteration

    1   4  7 11 15
    2   5  8 12 19
    3   6  9 16 22
    10 13 14 17 24
    18 21 23 26 30
    




*/


int main(){

    vector<vector<int>> arr = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int row = arr.size();
    int col = arr[0].size();

    int rowIndex = 0;
    int colIndex = col - 1;
    int target = 34;

    while(rowIndex < row && colIndex >=0){
        int ele = arr[rowIndex][colIndex];
        if(ele == target){
            printf("The element found at arr[%d][%d]",rowIndex,colIndex);
            return 0;
        }
        if(ele > target){
            colIndex --;
        }else{
            rowIndex++;
        }
    }
    cout<<"element not found !";
    return 0;
}


