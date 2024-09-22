/*
Craig Truitt (49115566)
Code made using https://chatgpt.com/g/g-2DQzU5UZl-code-copilot
Primary Contributor: Craig Truitt
Other Contributors: Ava Everett, Jordan Cox, Alex Gao, & Jeremy Baron
*/
#ifndef _CIRCULARLYLINKEDLIST_H_
#define _CIRCULARLYLINKEDLIST_H_
#include "Node.h"

class CLL {               // Declaration of the CLL (Circular Linked List) class.
private:
    Node* head;           // Pointer to the first node (head) in the circular linked list.
    Node* tail;           // Pointer to the last node (tail), which connects to the head.

public:
    CLL();                // Constructor to initialize the circular linked list.
    ~CLL();               // Destructor to clean up resources when the list is destroyed.

    void insert(char var); // Inserts a node with the value `var` into the list.
    void deleteNode(char var); // Removes the node with the value `var` from the list.
    void displayTwice();   // Displays the list twice to emphasize the circular nature.
};


#endif