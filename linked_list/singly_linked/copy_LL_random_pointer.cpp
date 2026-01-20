#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.
Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.
For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.
Return the head of the copied linked list.
The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.
    
Example 1:
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

1 -> 2 -> 3 -> 4 -> 5

random pointer
2->1
5->2
4->3
3->5
1->3



*/
// this code use T.C O(n)
//               S.C O(1)

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // step1: clone list
        Node* cloneHead = nullptr;
        Node* cloneTail = nullptr;
        Node* temp = head;
        while (temp != nullptr) {
            if (cloneHead == nullptr) {
                cloneHead = new Node(temp->val);
                cloneTail = cloneHead;
            } else {
                Node* neww = new Node(temp->val);
                cloneTail->next = neww;
                cloneTail = neww;
            }
            temp = temp->next;
        }

        // step2: cloneNode in btw original list
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while(originalNode!=nullptr && cloneNode!=nullptr){
            Node* next = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = next;
            next = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = next;
        }

        // step3: copying random pointer
        Node* curr = head;
        while(curr!=nullptr){
            if(curr->next!=nullptr){
            curr->next->random =curr->random?curr->random->next:curr->random;
            }
            curr = curr->next->next;
        }
        // step4: revert changes done in step2

        originalNode  = head;
        cloneNode = cloneHead;
        while(originalNode!=nullptr && cloneNode!=nullptr){
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;
            if(originalNode!=nullptr){
                cloneNode->next = originalNode->next;
            }
            cloneNode = cloneNode->next;
        }
        // step5: return ans
        return cloneHead;
    }
};