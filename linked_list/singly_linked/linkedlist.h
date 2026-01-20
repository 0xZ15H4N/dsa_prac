#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data);
    ~Node();
};

// function declarations
void insert_at_head(Node*& head, Node*& node);
void insert_at_head(Node*& head, int data);
void delete_node(Node*& head, int pos);
void print(Node* head);

#endif
