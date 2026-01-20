#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*


Quick-Notes


*/

class Node{
    public : 
        Node* prev;    
        int data;
        Node*next;
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node(){
        this->prev = nullptr;
        this->next = nullptr;
    }
};

void insert_at_head(Node* &head,int data){
    Node*temp = new Node(data);
    temp->next = head;
    temp->prev = head->prev;
    head->prev = temp;
    head=temp;
}


void print(Node*&head){
    Node*temp = head;
    while(temp!= nullptr){
        cout<<temp -> data<< " ";
        temp  = temp->next;
    }

}

void insert_at(Node* &head,int pos,int data){
    if(pos==1){
        insert_at_head(head,data);
    }else{
        int cnt=1;
        Node*curr = head;
        while(cnt<pos){
            curr  = curr->next;
            cnt ++;
        }
        Node*temp = new Node(data);
        temp->prev = curr;
        temp->next = curr->next;
        curr->next = temp;
        temp->next->prev = temp;
    }
}

void delete_node(Node*&head, int pos){
    if(pos==1){
        // deletion at head
        Node*temp  = head;
        head= head->next; 
        temp->next->prev = nullptr;
        temp->next = nullptr;
        delete temp;
        
    }else{

        Node * curr = head;
        Node * prev = nullptr;
        int cnt = 1;
        while(cnt < pos){
            prev = curr;
            curr = curr->next;
            cnt ++;
        }
        // unlinking A <-> B <-> C
        prev ->next = curr->next;
        curr->next->prev = curr->prev;        
        delete curr;
    }
}


int main(){

    Node* node1 = new Node(10);
    Node*head = node1;
    insert_at_head(head,20);
    insert_at_head(head,30);
    insert_at_head(head,40);
    insert_at_head(head,50);
    insert_at_head(head,60);
    print(head);
    delete_node(head,3);
    cout<<"\n";
    print(head);
    insert_at(head,3,30);
    cout<<"\n";
    print(head);
    return 0;
}