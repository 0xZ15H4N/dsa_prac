#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*



with the help of two pointer

1 2 2 2 3 3 4 5 6
1 2 3 4 5 6


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
    Node* prev = head;
    Node* curr = head->next;
    while(curr!= nullptr){
        if(prev->data == curr ->data){
            Node*temp = curr;
            curr = curr ->next;
            prev->next = temp->next;
            delete temp;
        }else{
            prev = curr;
            curr = curr ->next;
        }
    }

}

int main(){
    Node* node1 = new Node(1);
    Node* head = node1;
    Node*tail = node1;
    insert_at_tail(tail,2);
    insert_at_tail(tail,2);
    insert_at_tail(tail,3);
    insert_at_tail(tail,3);
    insert_at_tail(tail,4);
    insert_at_tail(tail,5);
    insert_at_tail(tail,6);
    insert_at_tail(tail,7);
    print(head);
    remove_duplicate(head);
    print(head);
    return 0;
}