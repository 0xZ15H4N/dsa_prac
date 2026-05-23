#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Quick-Notes
*/
class node{
    public:
        int data;
        node* left;
        node* right;

        node(int data){
            this->data = data;
            this->left = NULL;
            this->right = nullptr;
        }
        ~node(){
            this->left = nullptr;
            this->right = nullptr;
        }
};


void solve(node* root,int sum,int &maxSum,int len,int& maxLen){

    if(root == NULL){
        if(len > maxLen){
            maxLen = len;
            maxSum = sum;
        }else if(len == maxLen)
        {
            maxSum = max(sum,maxSum);
        }
        return;
    }
    sum = sum + root->data;
    solve(root->left,sum,maxSum,len+1,maxLen);
    solve(root->right,sum,maxSum,len+1,maxLen);
}