#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*

using hashmap we will delete the duplicate in a linked list
with the help of two pointer

1 2 2 4 4 5 6 7 8 8 9
1 5 6 7 9

to remove all the repeated elements with the one that is first occur in the repeated one.
in hashmap we will save prev , next to the curr
unordered_map<int data,pair<Node*prev,Node*next>> lst;

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
        if (head == nullptr || head->next == nullptr) {
        return;
        }
        Node* curr = head;
        Node* temp = new Node(0); // dummy node keep track of where our head is
        temp->next = head;
        Node* prev = temp;
        while (curr != nullptr) {
            bool is_dup = false;
            while (curr->next and curr->data == curr->next->data) {
                is_dup = true;
                curr = curr->next;
            }
            if(is_dup){
                prev->next = curr->next;
            }else{
                prev = prev->next;
            }
            curr = curr->next;
        }
        head = temp->next;
}

int main(){
    
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;
    insert_at_tail(tail,2);
    insert_at_tail(tail,2);
    insert_at_tail(tail,4);
    insert_at_tail(tail,4);
    insert_at_tail(tail,5);
    insert_at_tail(tail,6);
    insert_at_tail(tail,7);
    insert_at_tail(tail,8);
    insert_at_tail(tail,8);
    insert_at_tail(tail,9);

    print(head);
    remove_duplicate(head);
    print(head);
    return 0;
}