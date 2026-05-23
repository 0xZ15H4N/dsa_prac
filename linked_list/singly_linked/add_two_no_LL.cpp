#include<iostream>
using namespace std;
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


Node* reverse(Node*head){
    Node* prev = nullptr;
    Node* curr = head;
    while(curr!=nullptr){
        Node*temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

    Node* addTwoNumbers(Node* l1, Node* l2) {
        int carry = 0;
        int sum = 0;
        Node* total = new Node(0); // dummy node 
        while(l1!=nullptr && l2!=nullptr){
            sum = l1->data + l2->data + carry;
            carry = sum / 10;
            Node*temp = new Node(sum%10);
            Node*next = total->next;
            total ->next = temp;
            temp->next = next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=nullptr){
            sum = l1->data + carry;
            carry = sum / 10;
            Node*temp = new Node(sum%10);
            Node*next = total->next;
            total ->next = temp;
            temp->next = next;
            l1 = l1->next;
        }
        while(l2!=nullptr){
            sum = l2->data + carry;
            carry = sum / 10;
            Node*temp = new Node(sum%10);
            Node*next = total->next;
            total ->next = temp;
            temp->next = next;
            l2 = l2->next;
        }
        if(carry!=0){
            Node*temp = new Node(carry%10);
            carry = carry/10;
            Node*next = total->next;
            total ->next = temp;
            temp->next = next;
        }
        return reverse(total->next);
    }