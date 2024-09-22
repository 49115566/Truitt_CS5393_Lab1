/*
Craig Truitt (49115566)
Code made using https://chatgpt.com/g/g-2DQzU5UZl-code-copilot
Primary Contributor: Craig Truitt
Other Contributors: Ava Everett, Jordan Cox, Alex Gao, & Jeremy Baron
*/
#ifndef _DOUBLYLINKEDLIST_H_
#define _DOUBLYLINKEDLIST_H_

#include "Node.h"

// Define the DLL class, which is a doubly linked list
class DLL {
private:
    Node* head;  // Pointer to the first node in the list
    Node* tail;  // Pointer to the last node in the list

public:
    DLL();  // Constructor to initialize an empty doubly linked list
    ~DLL();  // Destructor to clean up memory when the list is destroyed

    void insert(char var);  // Function to insert a new node with the given data
    void deleteNode(char var);  // Function to delete the node with the given data
    void displayReverse();  // Function to display the contents of the list in reverse order
};

#endif  // End of the header guard
