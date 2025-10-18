#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*

Now we are going to reverse a string "abcdefgh" -> "hgfedcba"
for that i am going to start from the back and concaticate it character by character until the size if <=0

*/

string revString(string str , int size){
    if(size<=0){
        return "";
    }
    return str[size-1] + revString(str,size-1);
}


int main(){


    string str = "helloworld";
    cout<<revString(str,str.size());

    return 0;
}