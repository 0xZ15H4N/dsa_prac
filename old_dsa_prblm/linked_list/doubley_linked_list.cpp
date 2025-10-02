#include<iostream>
using namespace std;

class Node{
    public:
        Node* prev;
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }
};

void print(Node *head){
    cout<<"NULL"<<"  <- ";
    while(head !=NULL){
        //cout<<"|"<<head-> prev<<"|"<<head ->data<<"|"<<head->next<<"|"<<" <-> ";
        cout<<head -> data<<" ";
        head = head -> next;
    }
    cout<<"NULL"<<endl ;
}
int length(Node *head){
    int length =0;
    while(head!=NULL){
        length++;
        head = head -> next;
    }
    return length;

}

void insert_at_head(Node *&head,int data){
    Node *temp = new Node(data);
    head -> prev = temp;
    temp -> next = head;
    head = temp;
}
void insert_at_tail(Node*&tail,int data){
    Node* temp = new Node(data);
    temp->prev = tail;
    tail->next = temp;
          tail = temp;
}

void insert_at_position(Node *&head,Node* &tail,int data,int position){
    if(position == 1){
        insert_at_head(head,data);
        return;
    }
    else{
        int cnt =1;
        Node*temp = head;
        while(cnt < position - 1){
            cnt ++;
            temp = temp->next;
        }
        if(temp -> next ==NULL){
            insert_at_tail(tail,data);
            return;
        }else{
            Node* ntemp =new Node(data);
            ntemp ->prev = temp;
            ntemp ->next = temp->next;
            temp ->next->prev = ntemp;  
            temp->next = ntemp;
            return;
        }
    }

}
void print_void(Node* tail){
    while(tail!=NULL){
        cout<<tail ->data<<" ";
        tail = tail -> prev;
    }
}

void delete_at_position(Node* &head,Node* &tail,int position){
    if(position == 1){
        Node*temp = head;
        head = head ->next;
        head -> prev= NULL;
        delete temp;
        return;
    }else{
        Node *curr=head;
        Node *prev=NULL;
        int cnt =1;
        while(cnt < position){
            prev=curr;
            curr = curr->next;
            cnt++;
        }
        if(curr ->next == NULL){
            tail = prev;
            curr->next = NULL;
            delete curr;
            return;
        }
        prev -> next = curr -> next;
        curr->next->prev = prev;
        delete curr;
        return;     
    }

}
int main(){
    Node * n1 = new Node(10);
    Node *head = n1; 
    Node *tail =  n1;
    insert_at_head(head,11);
    cout<<length(head)<<endl;
    //print(head);
    insert_at_tail(tail,12);
    //print(head);
    insert_at_position(head,tail,14,1);
    insert_at_position(head,tail,15,5);
    insert_at_position(head,tail,16,6);
    print(head);
    //delete_at_position(head,tail,1);
    //print(head);
    //delete_at_position(head,tail,4);
    //print(head);
    //delete_at_position(head,tail,3);
    //print(head);
    cout<<head->data<<endl;
    cout<<tail->data<<endl;
    print_void(tail); 
    return 0;

}