#include<iostream>
#include<bits/stdc++.h>
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

void reverse_linked_list(Node*&head){
    Node* prev = nullptr;
    Node* curr = head;
    // three pointer problem
    while(curr != nullptr){
        Node*forward = curr->next;
        curr ->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev; //update head
}

// recursion
void reverse_linked_list(Node*&head,Node*prev,Node*curr){
    if(curr == nullptr){
        head = prev; //update head
        return;
    }
    Node*forward = curr->next;
    curr ->next = prev;
    prev = curr;
    curr = forward;
    return reverse_linked_list(head,prev,curr);
}


int main(){

    Node* node1 = new Node(1);
    Node* head = node1;
    for(int i = 2;i<11;i++)
{
    insert_at_head(head,i);
}
    print(head);

    reverse_linked_list(head,nullptr,head);
    cout<<"\n";
    print(head);

    return 0;
}