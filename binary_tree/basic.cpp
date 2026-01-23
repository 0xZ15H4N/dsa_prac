#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*


binary tree consist of 
    root node top of the tree
    and children below it directly connected to it
    and siblings that are on the same level as the other children 

                        1
                    2       3    (both are siblings) (same 2 , 3 are children of 1)
                  4   5   6   7 (these are sblings too and are also childrens of 2 and 3)
example 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
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

node* buildtree(node* root){
    int data;
    cin>>data;
    root = new node(data);
    if(data == -1){
        return NULL;
    }
    root->left = buildtree(root->left);
    root->right = buildtree(root->right);
    return root;
}

void levelOrderTraversal(node* root){
    if(root == nullptr || root == NULL){
        return;
    }
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node*temp = q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void reverseLevelOrderTraversal(node*root){

    if(root ==NULL){
        cout<<"null root present exiting";
        return;
    }
    queue<node*> q;
    vector<int> vec;
    q.push(root);

    while(!q.empty()){
        node*temp = q.front();
        q.pop();
        vec.push_back(temp->data);
        if(temp->right){
            q.push(temp->right);
        }
        if(temp->left){
            q.push(temp->left);
        }
    }
    for(int i = vec.size()-1; i >= 0 ;i--){
        cout<<vec[i]<<" ";
    }
}



int main(){


    node* root = NULL;
    root = buildtree(root);

    levelOrderTraversal(root);
    reverseLevelOrderTraversal(root);
    return 0;
}