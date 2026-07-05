#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Time  : O(n)
Space : O(n)
*/

class Node{
    public:
        Node* left;
        Node* right;
        int data;

        Node(int data){
            this->data = data;
            left = right = NULL;
        }
};

void bstToMInHeap(vector<int> &arr,Node* root){
    if(root ==  NULL){
        return;
    }
    bstToMInHeap(arr,root->left);
    arr.push_back(root->data);
    bstToMInHeap(arr,root->right);
}

void PreOrderFilling(vector<int>arr,int &index,Node* root){
    if(root == NULL){
        return;
    }
    root->data = arr[index++];
    PreOrderFilling(arr,index,root->left);
    PreOrderFilling(arr,index,root->right);
}



int main(){
// Your Driver Code
    return 0;
}

