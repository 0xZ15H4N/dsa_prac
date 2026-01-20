#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*


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
void insert_at_tail(Node * &tail,int data){
    
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void print(Node* &head){
    Node * temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";

}

void merge_LL(Node* &head1, Node* &head2){
    // we will account for head1->data is always greater or equals to head2->data
    if(head1->next ==nullptr){
        head1->next = head2;
    }
    Node* prev = head1;
    Node* curr1 = head1->next;
    Node* curr2 = head2;
    while(curr1!=nullptr && curr2!=nullptr){
        if((curr2->data>= prev->data) && (curr1->data >= curr2->data)){
            Node*temp = curr2->next;
            prev->next = curr2;
            curr2->next = curr1;
            // update the pointers
            curr2 = temp;
            prev = prev->next;
        }else{
            prev = prev->next;
            curr1 = curr1->next;
        }
    }
    if(curr1==nullptr){
        if(curr2!=nullptr){
            prev->next = curr2;
        }
    }
}

int main(){

    Node* node1 = new Node(1);
    Node* head1 = node1;
    Node* tail = node1;
    insert_at_tail(tail,3);
    insert_at_tail(tail,5);
    insert_at_tail(tail,7);
    insert_at_tail(tail,9);
    insert_at_tail(tail,11);
    insert_at_tail(tail,13);
    insert_at_tail(tail,15);
    print(head1);
    
    Node *node2 = new Node(2);
    Node* head2 = node2;
    Node* tail2 = node2;
    insert_at_tail(tail2,4);
    insert_at_tail(tail2,6);
    insert_at_tail(tail2,8);
    insert_at_tail(tail2,10);
    insert_at_tail(tail2,12);
    insert_at_tail(tail2,14);
    insert_at_tail(tail2,16);
    print(head2);

    merge_LL(head1,head2);
    print(head1);
    return 0;
}