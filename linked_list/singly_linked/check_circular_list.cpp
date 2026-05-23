#include<iostream>
#include<bits/stdc++.h>

using namespace std;
/*


Quick-Notes


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


// optimised used to detect the inner loops in a linked list
bool checkCircular(Node* &head){
    Node*start = head;
    unordered_map<Node*,bool>list;
    while(start!= nullptr){
        if(list.find(start) == list.end()){
            list[start] = false;
            start = start->next;
        }else{
            return true;
        }
    }
    return false;
}

int main(){

    Node*node1 = new Node(1);
    Node*node2 = new Node(2);
    Node*node3 = new Node(3);
    node1->next = node2;
    node2->next = node3;
    // node3->next = node1;
    Node* head=  node1;
    if(checkCircular(head)){
        cout<<"yess";
    }else{
        cout<<"NO";
    }
    return 0;
}