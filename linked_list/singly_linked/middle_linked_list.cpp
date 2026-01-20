#include<iostream>
#include<bits/stdc++.h>
#include "linkedlist.h"
using namespace std;
/*


Quick-Notes


*/




int main(){
    
    Node* node1 = new Node(1);
    Node* head = node1;
    for(int i = 2; i< 50;i++){
        insert_at_head(head,i);
    }
    print(head);
    Node* prev = head;
    Node* curr = head->next; // already ahead 
    while(curr != nullptr){
        curr = curr->next;
        if(curr!=nullptr){
            curr = curr->next;
        }
        prev  = prev->next;
    }
    cout<<prev -> data<<"\n";
    return 0;
}