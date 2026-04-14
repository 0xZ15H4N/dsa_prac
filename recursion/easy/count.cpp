#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void count(int,int);
void count(int);

int main(){
    int n;
    cout<< "Enter the number :";
    cin>>n;
    count(1,n);
    cout<<endl;
    count(n);
    return 0;
}

void count(int s,int d){


    cout<<s;
    if(s == d){
        return;
    }
    
    return count(s+1,d);
}

void count(int n){
    if(n == 0){
        return;
    }
    
    count(n-1);
    cout<<n;
}