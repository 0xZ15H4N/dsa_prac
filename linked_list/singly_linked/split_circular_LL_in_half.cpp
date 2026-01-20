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

void split_cll(Node* &head,Node*&head1,Node *&head2){
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){break;}
    }
    head1 = head;
    int cnt = 1;
    while(slow->next!=fast){
        // here we will count all the nodes in the CLL
        cnt++;
        slow  = slow->next;
    }
    int mid = cnt/2;
    int cnt1 = 0;
    while(cnt1!=mid){
        slow = slow->next;
        cnt1++;
    }
    fast = slow->next;
    slow->next = nullptr;
    print(head1);
    slow->next = head1;
    head2 = fast;
    while(cnt1!=cnt){
        fast = fast->next;
        cnt1++;
    }
    fast->next = nullptr;
    print(head2);
    fast->next = head2;
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