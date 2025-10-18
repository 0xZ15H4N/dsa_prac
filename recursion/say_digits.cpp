#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*

in this we need to code for the following input 421 and output should be four two one
using recursion

*/

void digit_parse(int);
void print(int n) {
    switch(n) {
        case 0: cout << "Zero "; break;
        case 1: cout << "One "; break;
        case 2: cout << "Two "; break;
        case 3: cout << "Three "; break;
        case 4: cout << "Four "; break;
        case 5: cout << "Five "; break;
        case 6: cout << "Six "; break;
        case 7: cout << "Seven "; break;
        case 8: cout << "Eight "; break;
        case 9: cout << "Nine "; break;
        default: cout<<n<< " Invalid "; // optional
    }
}

void digit_parse(int n){

    if(n == 0){
        return;
    }

    int ans = n % 10;
    digit_parse(n/10);
    print(ans);

}


int main(){

    int n ;
    cin>>n;
    digit_parse(n);

    return 0;
}