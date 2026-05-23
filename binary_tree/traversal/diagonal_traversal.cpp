#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*


Now we need to print the tree in diagonal 
for the we go from left to right in diagonal manner

we will create a q in which we will push root->left and will
push element in right into vector


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

vector<int> diagonal(node * root){
    if(root == NULL){
        return {};
    }
    vector<int> diag;

    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node* tmp = q.front();
        q.pop();
        while(tmp!=NULL){
            diag.push_back(tmp->data);
            if(tmp->left)
            {
                q.push(tmp->left);
            }
            tmp = tmp->right;
        }
    }
    return diag;
}