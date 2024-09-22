/*
Craig Truitt (49115566)
Code made using https://chatgpt.com/g/g-2DQzU5UZl-code-copilot
Primary Contributor: Craig Truitt
Other Contributors: Ava Everett, Jordan Cox, Alex Gao, & Jeremy Baron
*/
#include <iostream>
#include "CircularlyLinkedList.h"
using namespace std;


CLL::CLL() {                               // Constructor for the Circular Linked List class.
    head = nullptr;                        // Initializes head pointer to null, meaning the list is empty.
    tail = nullptr;                        // Initializes tail pointer to null, meaning the list is empty.
}

CLL::~CLL() {                              // Destructor for the Circular Linked List class.
    if (!head) return;                     // If the list is empty, do nothing and return.

    Node* current = head;                  // Start from the head node.
    do {
        Node* next = current->next;        // Store the next node pointer.
        delete current;                    // Delete the current node.
        current = next;                    // Move to the next node.
    } while (current != head);             // Continue until we've come back to the head node (circular).
}

void CLL::insert(char var) {               // Inserts a new node with the character `var`.
    Node* new_node = new Node(var);        // Create a new node with the given value.
    if (head == nullptr) {                 // If the list is empty:
        head = new_node;                   // Set the new node as head.
        tail = new_node;                   // Set the new node as tail.
        head->next = head;                 // Point head to itself to maintain circular structure.
    }
    else {                                 // If the list is not empty:
        tail->next = new_node;             // Link the current tail to the new node.
        tail = new_node;                   // Update the tail to be the new node.
        tail->next = head;                 // Make the list circular by pointing tail's next to head.
    }
}

void CLL::deleteNode(char var) {           // Deletes the node with the value `var`.
    if (head == nullptr) return;           // If the list is empty, do nothing.

    if (head->var == var) {                // If the node to delete is the head:
        if (head->next == head) {          // If the list has only one node:
            delete head;                   // Delete the head node.
            head = nullptr;                // Set head to null.
            tail = nullptr;                // Set tail to null.
        }
        else {                             // If there are multiple nodes:
            Node* current = head;          // Start from the head.
            while (current->next != head) {// Traverse to the last node (before the head).
                current = current->next;
            }
            Node* temp = head;             // Temporarily store the head node.
            current->next = head->next;    // Update the last node's next pointer to the new head.
            head = head->next;             // Set the new head.
            delete temp;                   // Delete the old head node.
        }
    }
    else {                                 // If the node to delete is not the head:
        Node* current = head;              // Start from the head node.
        while (current->next->var != var && current->next != head) {
            current = current->next;       // Traverse the list to find the node with value `var`.
        }
        if (current->next->var == var) {   // If the node with value `var` is found:
            if (current->next == tail)     // If the node to delete is the tail:
                tail = current;            // Update the tail pointer to the current node.
            Node* temp = current->next;    // Temporarily store the node to delete.
            current->next = current->next->next; // Update the link to bypass the deleted node.
            delete temp;                   // Delete the node.
        }
    }
}

void CLL::displayTwice() {                 // Displays the list twice to show its circular nature.
    if (head == nullptr) return;           // If the list is empty, do nothing.

    Node* current = head;                  // Start from the head node.
    int i = 0;                             // Counter to track how many times we've completed a loop.
    while (i < 2) {                        // Loop through the list twice:
        cout << current->var;              // Output the current node's value.
        current = current->next;           // Move to the next node.
        if (current == head) i++;          // When back to head, increment the counter.
    }

    cout << endl;                          // End with a new line after displaying the list twice.
}
