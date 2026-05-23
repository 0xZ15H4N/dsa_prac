#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
we need to find the left view of the binary tree
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

 void solve(node * root, vector<int>&ans,int level){
    if(root==NULL){
        return;
    }
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    solve(root->left,ans,level+1);
    solve(root->right,ans,level+1);
}


int main(){
    vector<int>ans;
    node * root = NULL;
    solve(root,ans,0);
    return 0;
}


