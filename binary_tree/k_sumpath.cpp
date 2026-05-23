#include<iostream>
#include<bits/stdc++.h>
using namespace std;

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

void solve(node*root,vector<int>ans,int K,int &cnt){
    if(root==NULL){
        
        return;
    }
    ans.push_back(root->data);
    solve(root->left,ans,K,cnt);
    solve(root->right,ans,K,cnt);
    int size = ans.size();
    int sum = 0;
    for(int i = size-1;i>=0;i--){
        sum += ans[i];
        if(sum == K){
            cnt++;
        }
    }
    ans.pop_back();
}
 