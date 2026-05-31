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

int maxInLeft(Node* root){
    if(root==NULL){
        return -1;
    }
    while(root->right){
        root= root->right;
    }
    return root->data;

}
int minInRight(Node* root){
    if(root==NULL){
        return -1;
    }
    while(root->left){
        root= root->left;
    }
    return root->data;
}

void inorderTravesal(Node * root,int &pred,int &succ,int target){
    
    while(root->data !=target){
        if(root->data > target){
            succ = root->data;
            root = root->left;
        }else{
            pred = root->data;
            root = root->right;
        }
    }
    int tpred;
    int tsucc;
    if(root->data == target){
        tpred = maxInLeft(root->left);
        tsucc = minInRight(root->right);
    }
    tpred!=-1?pred = tpred:pred= pred;
    tsucc!=-1?succ = tsucc:succ= succ;
    
    return;
     
}


void inorderTravesal(Node* root){
    if(root==NULL)
{
    return;
}
    inorderTravesal(root->left);
    cout<<root->data<<" ";
    inorderTravesal(root->right);
}


int main(){

    int pred = -1;
    int succ = -1;

    Node* root = NULL;
    takeInput(root);
//10 8 21 7 27 5 4 3 -1
    inorderTravesal(root);
    inorderTravesal(root,pred,succ,2);
    cout<<endl;
    cout<<pred<<" "<<succ;


    return 0;
}