#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
for this we will go level by level creating an ordered map 
in which each level have its horizontal distance from {node : value of the node}
if the key value pair is already created we will not add another pair in to it
with this logic we will find the topView of the Tree
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


vector<int> bottomView(node* root){
    vector<int>ans;
    if(root == NULL){
        return ans;
    }
    //  hd,data
    map<int,int> topNode;
        //     node , hd
    queue<pair<node*,int>>q;

    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<node*,int> tmp = q.front();
        q.pop();
        int hd = tmp.second; 
        topNode[hd] = tmp.first->data;
        if(tmp.first->left){
            q.push(make_pair(tmp.first->left,hd-1));
        }
        if(tmp.first->right){
            q.push(make_pair(tmp.first->right,hd+1));
        }
    }
    for(auto i : topNode){
        ans.push_back(i.second);
    }
    return ans;
}
