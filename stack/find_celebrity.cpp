#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
in 2D matrix we have people in rows and if it knows some one their respective column will contain 1 other wise 0
for example

            _0   1   2_
        0  | 0   1   0 |
        1  | 0   0   0 |
        2  |_0   1   0_|


        here 0 knows 1
             1 knows no-One cause 
             2 knows 1


 we will use stack for find a potential celebrity 
 we will first push all the person into the stack and then poping 2 A,B element at a time under a while loop condition(stk.size()!=1)
 after popping will used the matrix accesssiong value using the index to find either A , B is celeb if found A celeb we will push it into stack 
 after reaching size 1 element at the top will be our potential candidate

 after find the potential candidate will apply 
    -> 2 for loop to find the row is all zero 
    -> and if the coloumn contain 1 expect for it selft

*/


int find_the_celeb(stack<int>&stk,vector<vector<int>>&matrix)
{
    while(stk.size()>1){
        int A = stk.top();
        stk.pop();
        int B = stk.top();
        stk.pop();
        if(!matrix[A][B]){
            stk.push(A);
        }
        else{
            stk.push(B);
        }
    }
    // if we are out of this loop 
    int pCeleb = stk.top();
    bool col = true;
    bool row = true;
    // checking for column 
    for(int i = 0; i < matrix[0].size();i++){
        if(i == pCeleb){
            continue;
        }
        if(matrix[i][pCeleb] ==  0){
            col = false;
            break;
        }
    }
    for(int i = 0; i < matrix[0].size();i++){
        if(matrix[pCeleb][i] ==  1){
            row = false;
            break;
        }
    }

    if(col && row){
        return pCeleb;
    }else{
        return -1;
    }

}



int main(){

    vector<vector<int>>matrix = {
                                {0,1,0},
                                {0,0,0},
                                {0,1,0}};

    stack<int>stk;
    int size = matrix[0].size();
    for(int i = 0; i < size ; i++){
        stk.push(i);
    }

    cout<< "Our celeb is "<< find_the_celeb(stk,matrix);

    return 0;
}