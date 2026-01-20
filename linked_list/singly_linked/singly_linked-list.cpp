#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/*
Quick-Notes
*/

class Node {
    public:
        int data;
        Node *next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
        ~Node(){
                this->next = nullptr;
        }
};

void insert_at_head(Node* &node,Node * &head){
    node->next = head;
    head = node;
}
void insert_at_head(Node * &head,int data){
    
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void print(Node* &head){
    Node * temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

}


void delete_node(Node* &head,int pos){
    if(pos==1){
        Node*temp = head;
        head= head->next;
        delete temp;
        return;
    } //deletion at head
    
   else{

    Node* curr= head;
    Node* prev = NULL;
    int cnt = 1;

    while(cnt < pos){
        prev = curr ;
        curr = curr->next;
        cnt ++;
    }
    // deletion at middle or tail
    prev ->next = curr->next;
    delete curr;
   }
}
