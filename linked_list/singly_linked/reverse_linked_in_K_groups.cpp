#include<iostream>
#include<bits/stdc++.h>
#include "linkedlist.h"
using namespace std;
/*


we need to reverse a linked list in k groups 
k  = 3 

1 -> 2 -> 3 -> 4 -> 5 -> 6

3 -> 2 -> 1 -> 6 -> 5 -> 4


thinking two pointer curr = prev = head starting
curr will be shifted to k-1 position

after that will call the reverse linkedlist func between curr and prev 

*/

int getLength(Node*forward){
    int cnt = 0;
    while(forward!=nullptr){
        forward = forward->next;
        cnt++;
    }
    return cnt;
}

Node* reverse_K_grp(Node* &head,int k){

    if(head== nullptr){
        return head;
    }

    Node* curr = head;
    Node* prev = nullptr;
    Node* forward = nullptr;

   int count = 0;

    while(curr != nullptr && count < k){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count++;
    }
    if(forward != nullptr){
        if(getLength(forward)>=k){
            head->next = reverse_K_grp(forward,  k);
        }else{
            head->next = forward;
        }
    }
    return prev;

}

int main(){

    Node* node1 = new Node(1);
    Node* head = node1;
    for(int i = 2 ; i<12 ;i){
        insert_at_head(head,i);
    }
    print(head);
    // head = reverse_K_grp(head,2);
    // print(head);
    return 0;
}