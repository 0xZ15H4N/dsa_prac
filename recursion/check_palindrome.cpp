#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*


Now we are checkin the given string is palindrome or not

*/

bool check_palindrome(string str,int i ,int j){

    if(i>j){
        return true;
    }
    if(str[i] == ' '){
        i++;
    }
    if(str[j] == ' '){
        j--;
    }
    if(str[i] == str[j]){
        i++;
        j--;
        return check_palindrome(str,i,j);
    }
    else{
        return false;
    }

}


int main(){

    string str ;
    getline(cin,str);
    cout<<check_palindrome(str,0,str.size()-1);
    

    return 0;
}