#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
T.C is O(n)
S.C is O(height)
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

node* lca(node * root,int n1, int n2){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    node* leftAns  = lca(root->left,n1,n2);
    node* rightAns = lca(root->right,n1,n2);

    if(leftAns != NULL && rightAns != NULL){
        return root;
    }
    else if(leftAns!= NULL && rightAns == NULL){
        return leftAns;
    }
    else if(leftAns==NULL && rightAns != NULL){
        return rightAns;
    }
    else{
        return NULL;
    }   
}