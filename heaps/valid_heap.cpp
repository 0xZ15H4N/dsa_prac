#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// is Max Heap root->data >= root->left->data is also a valid case too!

class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int data){
            this->data = data;
            this->left = this->right = NULL;
        }   
};

class Solution {
private :
    void totolCount(TreeNode* root,int &count){
        if(root == NULL){
            return;
        } 
        totolCount(root->left,count);
        totolCount(root->right,count);
        count++;
    }

    bool isCBT(TreeNode* root, int index, int nodeCount){
        if(root == NULL){
            return true;
        }
        if(index >= nodeCount){
            return false;
        }
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        return isCBT(root->left,left,nodeCount) && isCBT(root->right,right,nodeCount);
    }

    bool MaxOrder(TreeNode* root){
        if(root == NULL){
            return true;
        }
        if(root->left == NULL && root->right == NULL){
            return true;
        }
        else if(root->right == NULL){
            return root->data > root->left->data;
        }
        else{
            return root->data > root->left->data && root->data > root->right->data && MaxOrder(root->left) && MaxOrder(root->right); 
        }
    }
public:
    bool isCompleteTree(TreeNode* root) {
        int count = 0;
        totolCount(root,count);
        return isCBT(root,0,count)&& MaxOrder(root);
    }
};


 