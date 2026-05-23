#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    void solve(TreeNode* root,stack<TreeNode*>&stk){
        if(root==nullptr){
            return;
        }
        stk.push(root);
        solve(root->left,stk);
        solve(root->right,stk);
    }
public:
    void flatten(TreeNode* root) {
        stack<TreeNode*> stk;
        solve(root,stk);
        TreeNode* dummpy = new TreeNode(-1);
        while(!stk.empty()){
            TreeNode* temp = stk.top();
            if(dummpy->right==nullptr){
                temp->right=nullptr;
                temp->left=nullptr;
                dummpy->right=temp;
            }else{
                TreeNode *ntemp = dummpy->right;
                dummpy->right = temp;
                temp->right = ntemp;
                temp->left = nullptr;
            }
            stk.pop();
        }
    }
};