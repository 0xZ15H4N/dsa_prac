#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*


we need to check for
    if a bt is balance ie 
        abs(height(left) -  height(right)) <=1


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

pair<bool,int> is_balance_bt(node*root){

    if(root==NULL){
        return {true,0};
    }

    pair<bool,int> left = is_balance_bt(root->left);
    pair<bool,int> right = is_balance_bt(root->right);

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool,int>ans;

    ans.second = max(left.second,right.second) +1 ;
    if(left.first && right.first && diff){
        ans.first = true;
    }
    else{
        ans.first = false;
    }

    return ans;


}