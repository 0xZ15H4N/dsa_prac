#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void insertIntoBST(Node* &root,int data){
    if(root==NULL){
        root = new Node(data);
        return;
    }
    if(data > root->data){
        insertIntoBST(root->right,data);
    }
    else{
        insertIntoBST(root->left,data);
    }
}

void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        insertIntoBST(root,data);
        cin>>data;
    }
}
void lot(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
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

Node* maxInBST(Node* root){
    if(root==NULL){
        return root;
    }
    while(root->right){
        root = root->right;
    }
    return root;
}

Node* deletionInBST(Node* root,int data){
    if(root==NULL){
        return NULL;
    }
    else if(root->data == data){
        // No child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // single child 
        else if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else if(root->right != NULL && root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // 2 children
        else{
            Node* temp = maxInBST(root->left);
            root->data = temp->data;
            root->left = deletionInBST(root->left,temp->data);
            return root;
        }
    }
    else if(root->data > data){
        root->left = deletionInBST(root->left,data);
        return root;
    }else{
        root->right = deletionInBST(root->right,data);
        return root;
    }
}


int main(){
    Node* root=NULL;
    takeInput(root);
    // lot(root);
    cout<<maxInBST(root)->data;
    deletionInBST(root,10 ); // 10 8 21 7 27 5 4 3 -1
    lot(root);
    return 0;
}