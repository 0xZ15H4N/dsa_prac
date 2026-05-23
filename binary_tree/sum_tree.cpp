#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*

we need to check if the bt is a sumtree 
    ie , root->data = sum(leftSubTreeAllNode->data) + sum(rightsubTreeAllNode->data)
        and this should also follow for the left subtree and right subtree.

    also edge case here is root = null , already sumtree hai vo
                           leaf node already subtree.

*/

class node{
    public:
        node * left;
        node* right;
        int data;
        node(int data){
            this->data = data;
            left = right = NULL;
        }
        
        ~node(){
            left = right = NULL;
        }
};
// first value of the pair denotes if the subpart is balance , 
// second value of the pair denotes the value of the child node data
pair<bool,int> sumTree(node* root){
    // if the root is null;
    if(root ==NULL){
        return {
            true,
            0
        };
    }

    // leaf node
    if(root->left == NULL && root ->right ==NULL){
        return {true,root->data};
    }

    pair<bool,int> left = sumTree(root->left); // this will check for sum tree in left part 
    pair<bool,int> right = sumTree(root->right); // this will check for sum tree in right part

    bool curr = root->data == left.second + right.second;

    pair<bool,int> ans;
    if(curr && left.first && right.first){
        ans.first  = true;
        ans.second = 2*root->data;
    }else{
        ans.first = false; 
    }
    return ans;
}