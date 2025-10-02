#include<iostream>
#include<string.h>

using namespace std;

class Node{
    public:
        int data;
        Node *  node;

        Node(int val){
            data = val;
            node = NULL;
        }
};
void insertion_at_head(Node* &head,int data){
    Node*   temp = new Node(data);
    temp -> node = head ;
    head = temp;
}
void insertion_at_tail(Node* &tail,int data){
    Node * temp = new Node(data);
    tail -> node = temp;
    tail = temp;
}
void insertAtposition(Node* &head,Node* &tail,int data,int position){
    Node * temp;
    temp = head;
    int cnt = 1;
    //insertion at the start
    if(position ==1){
        insertion_at_head(head,data);
        return;
    }
    while(cnt < position-1){
        cnt ++;
        temp = temp ->node; 
    }
    //insertion at the last
    if(temp->node ==NULL){
        insertion_at_tail(tail,data);
        return;
    }
    //insertion at the middle; 
    Node* ntemp = new Node(data);
    ntemp->node = temp->node;
    temp->node = ntemp;                                       
}

void print(Node* head){
    while(head !=NULL){
        cout<<"|"<<" "<<head ->data<<" "<<"|"<<" "<<head->node<<" "<<"|"<<" ---> ";
        head = head ->node;
    }
    cout<<"N U L L"<<endl;
}


void deleteNode(Node*&head,Node* &tail,int position){

         //deletion from the start
         if(position == 1){
            Node *temp = head;
            head = head -> node;   
            temp -> node = NULL;
            delete temp;
            return;
         }
         // deletion at the middle or last
         else{
            Node* curr= head;
            Node* prev= NULL;
            int cnt =1;
            while(cnt < position){
                prev = curr;
                curr = curr-> node;  
                cnt++;            
            }
            if(curr->node==NULL){
                tail = prev;
            }
            prev -> node = curr->node;
            delete  curr;
         }
         return;
}

int main(){
    Node*n1 = new Node(10);
    Node *head = n1;
    Node *tail = n1;
    insertion_at_tail(tail,20);
    insertion_at_tail(tail,30);
    insertion_at_tail(tail,40);
    insertion_at_head(head,120);
    insertion_at_tail(tail,130);
    insertAtposition(head,tail,140,7);
    print(head);
    cout<<"head @ "<<head->data<<endl;
    cout<<"tail @ "<<tail->data<<endl;
    deleteNode(head,tail,7);
    cout<<"head @ "<<head->data<<endl;
    cout<<"tail @ "<<tail->data<<endl;
    print(head);
    insertAtposition(head,tail,140,7);
    cout<<"head @ "<<head->data<<endl;
    cout<<"tail @ "<<tail->data<<endl;
    print(head);
    deleteNode(head,tail,5);
    print(head);
    return 0;
}
