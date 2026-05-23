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

void traverseLeft(node * root,vector<int> &ans){
    if(root == NULL || (root->left == NULL && root->right == NULL)) {
        return;
    }
    ans.push_back(root->data);
    if(root->left){
    traverseLeft(root->left,ans);   
    }
    if(root->right){
        traverseLeft(root->right,ans);
    }
}

void traverseLeaf(node* root,vector<int>&ans){
    if(root == NULL){
        return ;
    }
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }
    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);
}

void traverseRight(node* root,vector<int> &ans){
    if(root == NULL || root->left == NULL && root->right == NULL){
        return;
    }  
    if(root->right){
        traverseRight(root->right,ans);
    }else{
        traverseRight(root->left,ans);
    }
    ans.push_back(root->data); 
}

vector <int> boundary(node * root){
    vector<int> ans;
    if(root == NULL){
        return {};
    }
    ans.push_back(root->data);

    // left part print
    traverseLeft(root->left,ans);

    // traverseLeaf Node
            //left subtree
        traverseLeaf(root->left,ans);
            // right subtree
        traverseLeaf(root->right,ans);
    
    //right part print
    traverseRight(root->right,ans);    
}
