#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*


In this we will calculate the power 
for that i will take a number and the power of it and i will recursively multiply by it util the power become 


*/

int power(int i,int j){
    if(j==0){
        return 1;
    }

    return i*(power(i,--j));
}


int main(){

    cout<<power(2,10);




    return 0;
}