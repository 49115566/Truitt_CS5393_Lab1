/*
Craig Truitt (49115566)
Code made using https://chatgpt.com/g/g-2DQzU5UZl-code-copilot
Primary Contributor: Craig Truitt
Other Contributors: Ava Everett, Jordan Cox, Alex Gao, & Jeremy Baron
*/

#include <iostream>  // Include the iostream library for input/output operations
#include "SinglyLinkedList.h"  // Include the header file for the SLL class
using namespace std;  // Use the standard namespace for easier access to std classes and functions

// Constructor for SLL
SLL::SLL() {
    head = nullptr;  // Initialize the head pointer to null (empty list)
    tail = nullptr;  // Initialize the tail pointer to null (empty list)
}

// Destructor for SLL
SLL::~SLL() {
    Node* current = head;  // Start from the head of the list
    while (current != nullptr) {  // Loop through the list until the end
        Node* next = current->next;  // Store the next node before deleting the current one
        delete current;  // Delete the current node to free memory
        current = next;  // Move to the next node in the list
    }
}

// Function to insert a new node with given var
void SLL::insert(char var) {
    Node* new_node = new Node(var);  // Create a new node with the given data
    if (head == nullptr) {  // If the list is empty
        head = new_node;  // Set the new node as the head
        tail = new_node;  // Set the new node as the tail
    }
    else {  // If the list is not empty
        tail->next = new_node;  // Link the current tail to the new node
        tail = new_node;  // Update the tail to be the new node
    }
}

// Function to delete a node with the given data
void SLL::deleteNode(char var) {
    if (head == nullptr) return;  // If the list is empty, return immediately

    if (head->var == var) {  // If the node to delete is the head
        Node* temp = head;  // Temporarily store the head node
        head = head->next;  // Move the head to the next node
        delete temp;  // Delete the original head
    }
    else {  // If the node to delete is not the head
        Node* current = head;  // Start from the head node
        while (current->next != nullptr && current->next->var != var) {
            current = current->next;  // Traverse the list until the node is found or end is reached
        }

        if (current->next != nullptr) {  // If the node is found
            if (current->next->next == nullptr) {
                tail = current;  // Update the tail if the last node is being deleted
            }
            Node* temp = current->next;  // Temporarily store the node to delete
            current->next = current->next->next;  // Bypass the node to be deleted
            delete temp;  // Delete the node
        }
    }

    if (!head) tail = nullptr;  // If the list becomes empty, set tail to null
}

// Function to display the contents of the list
void SLL::display() {
    Node* current = head;  // Start from the head of the list
    while (current != nullptr) {  // Loop through all the nodes in the list
        cout << current->var;  // Print the data of the current node
        current = current->next;  // Move to the next node
    }
    cout << endl;  // Print a newline at the end of the list display
}
