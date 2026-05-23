#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*

using hashmap we will delete the duplicate in a linked list
with the help of two pointer

1 3 2 1 5 2 8 4 6 7
1 3 2 5 8 4 6 7

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

    cout<<"\n";
}
void insert_at_tail(Node*&tail,int data){
    Node*temp = new Node(data);
    tail ->next  = temp;
    tail  = temp;
}

void remove_duplicate(Node*&head){
    unordered_map<int , bool>lst;
    Node*prev = nullptr;
    Node*curr = head;
    while(curr !=nullptr){
        if(lst.find(curr->data) == lst.end()){
            lst[curr->data] = true;
            prev = curr;
            if(curr){
                curr = curr->next;
            }
        }
        else{
            Node*temp = curr;
            prev->next = curr->next;
            prev = curr;
            curr =curr->next;
            delete temp;
        }
    }
}

int main(){

    Node* node1 = new Node(1);
    Node* head = node1;
    Node*tail = node1;

    insert_at_tail(tail,3);
    insert_at_tail(tail,2);
    insert_at_tail(tail,2);
    insert_at_tail(tail,9);
    insert_at_tail(tail,4);
    insert_at_tail(tail,4);
    insert_at_tail(tail,6);
    insert_at_tail(tail,5);
    insert_at_tail(tail,7);
    insert_at_tail(tail,8);
    print(head);
    remove_duplicate(head);
    print(head);

    return 0;
}