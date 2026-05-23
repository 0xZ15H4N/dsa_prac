#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*

1 -> 2 -> 3 -> 4 -> 5      1 -> 2       3 -> 4 -> 5
^                   ^   -> ^    ^  ,    ^         ^
|___________________|      |____|       |_________|

we will use floyd cyclic detection method to find start and end
after that will calculate the no of nodes in the cycle
then will wil iterate in it

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
    cout<<"\n";

}
void insert_at_tail(Node * &tail,int data){
    
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void split_cll(Node* &head, Node*& head1, Node*& head2) {
    if (!head) return;

    // count nodes
    int cnt = 1;
    Node* temp = head;
    while (temp->next != head) {
        cnt++;
        temp = temp->next;
    }

    int mid = cnt / 2;

    // move to mid node
    temp = head;
    for (int i = 1; i < mid; i++) {
        temp = temp->next;
    }

    head1 = head;
    head2 = temp->next;

    // close first CLL
    temp->next = head1;

    // move to last node of second half
    Node* last = head2;
    while (last->next != head) {
        last = last->next;
    }

    // close second CLL
    last->next = head2;
}


int main(){

    Node* node1 = new Node(1);
    Node* head = node1;
    Node*tail = node1;
    Node*temp = head;
    insert_at_tail(tail,3);
    insert_at_tail(tail,2);
    insert_at_tail(tail,2);
    insert_at_tail(tail,9);
    insert_at_tail(tail,4);
    insert_at_tail(tail,4);

    while(temp->next!=nullptr){
        temp = temp ->next;
    }
    temp->next = head;
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    split_cll(head,head1,head2);
    return 0;
}