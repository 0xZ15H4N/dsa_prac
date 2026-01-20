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
 
 Node* getMid(Node*head){
        Node*slow = head;
        Node*fast = head->next;
        while(fast!=nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Node* reverse(Node* head){
        Node*prev = nullptr;
        Node*curr = head;
        while(curr!=nullptr){
            Node*temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    bool isPalindrome(Node* head) {
        if(head == nullptr || head->next ==nullptr){
            return true;
        }
        Node* middle = getMid(head);
        middle->next = reverse(middle->next);
        Node* head1 = head;
        Node* head2 = middle->next;
        while(head2!=nullptr){
            if(head1->data == head2->data){
                head1 = head1->next;
                head2 = head2->next;
            }else{
                return false;
            }
        }
        reverse(middle->next);
        return true;
    }
