/*
Craig Truitt (49115566)
Code made using https://chatgpt.com/g/g-2DQzU5UZl-code-copilot
Primary Contributor: Craig Truitt
Other Contributors: Ava Everett, Jordan Cox, Alex Gao, & Jeremy Baron
*/
#include <iostream>  
#include "DoublyLinkedList.h"  
using namespace std;  


DLL::DLL() {  // Constructor for the DLL class
    head = nullptr;  // Initialize head to null
    tail = nullptr;  // Initialize tail to null
}

DLL::~DLL() {  // Destructor for the DLL class
    Node* current = head;  // Start at the head of the list
    while (current != nullptr) {  // Loop through each node
        Node* next = current->next;  // Store the next node
        delete current;  // Delete the current node
        current = next;  // Move to the next node
    }
}

void DLL::insert(char var) {  // Function to insert a node with a character value
    Node* new_node = new Node(var);  // Create a new node with the given value
    if (head == nullptr) {  // If the list is empty
        head = tail = new_node;  // Set both head and tail to the new node
    }
    else {  // If the list is not empty
        tail->next = new_node;  // Link the new node after the current tail
        new_node->prev = tail;  // Link the current tail to the new node
        tail = new_node;  // Update the tail to the new node
    }
}

void DLL::deleteNode(char var) {  // Function to delete a node with the specified value
    if (head == nullptr) return;  // If the list is empty, exit

    if (head->var == var) {  // If the head node contains the value
        Node* temp = head;  // Store the head node
        head = head->next;  // Move head to the next node
        if (head) head->prev = nullptr;  // If the new head exists, remove its previous link
        else tail = nullptr;  // If no new head, set tail to null (list is empty)
        delete temp;  // Delete the old head node
        return;  // Exit the function
    }

    Node* current = head;  // Start at the head of the list
    while (current != nullptr && current->var != var) {  // Search for the node with the specified value
        current = current->next;  // Move to the next node
    }

    if (current != nullptr) {  // If the node was found
        if (current->next) {  // If there is a next node
            current->next->prev = current->prev;  // Update the next node's previous link
        }
        if (current->prev) {  // If there is a previous node
            current->prev->next = current->next;  // Update the previous node's next link
        }
        if (current == tail) {  // If the node is the tail
            tail = current->prev;  // Update the tail to the previous node
        }
        delete current;  // Delete the current node
    }
}

void DLL::displayReverse() {  // Function to display the list in reverse
    Node* current = tail;  // Start at the tail of the list
    while (current != nullptr) {  // Traverse the list backwards
        cout << current->var;  // Output the value of the current node
        current = current->prev;  // Move to the previous node
    }
    cout << endl;  // Print a new line at the end
}
