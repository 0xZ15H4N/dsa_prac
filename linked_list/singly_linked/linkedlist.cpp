#include "LinkedList.h"
// Node constructor
Node::Node(int data) {
    this->data = data;
    this->next = nullptr;
}

// Node destructor
Node::~Node() {
    this->next = nullptr;
}

void insert_at_head(Node*& head, Node*& node) {
    node->next = head;
    head = node;
}

void insert_at_head(Node*& head, int data) {
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void delete_node(Node* &head,int pos){
    if(pos==1){
        Node*temp = head;
        head= head->next;
        delete temp;
        return;
    } //deletion at head
    
   else{

    Node* curr= head;
    Node* prev = NULL;
    int cnt = 1;

    while(cnt < pos){
        prev = curr ;
        curr = curr->next;
        cnt ++;
    }
    // deletion at middle or tail
    prev ->next = curr->next;
    delete curr;
   }
}

void print(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
