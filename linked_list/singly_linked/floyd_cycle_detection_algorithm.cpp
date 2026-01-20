#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
In Floyd cyclel detection algorithm
we can detect the cycle or circular linked list.
The idea is to start with the two pointers slow and fast, both starting at the head of the linked list.
While traversing the List:
-> slow pointer will move one step at a time.
-> fast pointer moves two steps at a time.
-> If there's a cycle, the fast pointer will eventually catch up with the slow pointer within the cycle because it's moving faster.
-> If there's no cycle, the fast pointer will reach the end of the list (i.e., it will become NULL).
-> When the slow and fast pointers meet, a cycle or loop exists.
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

// applying floyd circular detection algo
void check_circular(Node* &head){
    if(head == nullptr){
        return;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast!=nullptr ){
        slow = slow ->next;
        fast = fast->next;
        if(fast->next){
            fast = fast->next;
        }
        if(slow == fast){
            cout<<"Yes linked list is cicular in nature";
            return;
        }
        
    }
    if(fast==nullptr || fast->next==nullptr){
        return;
    }
    slow = head;
    while(slow != fast){
        fast = fast->next;
        slow = slow->next;
    }
   

}

int main(){

    Node*node1 = new Node(1);
    Node*head = node1;
    for(int i = 2; i< 5;i++){
        insert_at_head(head,i);
    }
//  Inducing circular tendency in the linked list
    Node*temp = head;
    Node*temp2 = head;
    while(temp->next){
        temp = temp->next;
    }
    temp2 = temp2->next->next;
    temp->next  = temp2;

    check_circular(head);

    return 0;
}

// my solution using the hashmap
 Node* detectCycle(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        if(head->next == NULL){
            return NULL;
        }
        Node* start = head;
        unordered_map<Node*, int> list;
        int cnt = 0; // position
        while (start != NULL) {
            if (list.find(start) == list.end()) {
                list[start] = cnt++;
                start = start->next;
            } else {
                return start;
            }
        }
        return NULL;
}