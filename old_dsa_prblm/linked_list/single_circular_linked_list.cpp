#include<iostream>
using namespace std;

class Node{
    public: 
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            next = NULL;
        } rohitbhaisexy
};

void insert_at_head(Node* &head,Node* &tail,int data){
    Node*temp   = new Node(data);
    temp->next  = head;
    head = temp;
    tail ->next = head;
}

void insert_at_tail(Node* &head,Node* &tail,int data){
    Node*temp   = new Node(data);
    temp -> next = tail -> next;
    tail-> next = temp;
    tail = temp; 
}

void insert_at_position(Node* &head,Node*&tail,int data,int position){
    if(position == 1){
        insert_at_head(head,tail,data);
        return;
    }else{
        int cnt = 1;
        Node*temp = head;
        while(cnt <position-1){
            cnt++;
            temp = temp->next;
        }
        if(temp->next == head){
            insert_at_tail(head,tail,data);
            return;
        }
        Node*ntemp = new Node(data);
        ntemp ->next = temp ->next;
        temp->next = ntemp;
        return;
    }

}
void print(Node*head,Node*tail){
    Node*temp = NULL;
    while(head->next != temp){
        cout<<head->data<<endl;
        temp =head;
        head = head->next;
    }
}


int main(){
    Node*n1 = new Node(10);
    Node*head = n1;
    Node*tail = n1;
    print(head,tail);
    insert_at_head(head,tail,20);
    print(head,tail);
}
