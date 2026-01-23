#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*

we need to find the height of the binary tree using recursion 
what is height ?: longest path between root node and leaf node

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


int height(node*root){
    if(root == NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);

    return max(left,right) + 1;
}