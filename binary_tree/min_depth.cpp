#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*

we need to find the minimum depth of the bt
    -> for that we will traverse a sub-tree until we hit a leaf node

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



int min_depth_bt(node* root){
    if(root ==NULL){
        return 0;
    }

    if(root->left == NULL && root->right == NULL){
        return 1;
    }

    int l , r;
    if(root->left){
        l = min_depth_bt(root->left);
    }
    if(root->right){
        r = min_depth_bt(root->right);
    }
    return min(l,r) + 1;

}
