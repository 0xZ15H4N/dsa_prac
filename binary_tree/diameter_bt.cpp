#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*

longest part between two nodes

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

int height(node* root){
    if(root == NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return max(left,right)+1;
}

// this solution is given us soluting in O(n^2)
int diameter_bt(node*root){
    if(root ==NULL){
        return 0;
    }

    int op1 = diameter_bt(root->left);
    int op2 = diameter_bt(root->right);
    int op3 = height(root->left) + 1 + height(root->right);

    return max(op1,max(op2,op3));
}


// this is the better approach solving in o(n)
// we will use pair the first part will store diameter and the second will store the height 
// so we dont have to call the height funciton any more
pair<int,int> diameter_fast(node*root){
    
    if(root == NULL){
        return {0,0};
    }

    pair<int,int> left = diameter_fast(root->left);
    pair<int,int> right = diameter_fast(root->right);

    int op1 =  left.first;                    // this stores the current diamter of the left
    int op2 =  right.first;                   // this stores the current diamter of the right
    int op3 = left.second + right.second + 1; // this stores the current height

    pair<int,int> ans ;
    ans.first = max(op1,max(op2,op3));            // this will store the diameter
    ans.second = max(left.second,right.second)+1; // this will storet the height
    return ans;
}   