#ifndef _NODE_H_
#define _NODE_H_

/*
Node Structure:
This structure is the basis for all of the linked lists in the project.
It contains:
-A character
-A pointer to the next
-A pointer to the previous
-A constructor
Note: the pointer to the previous is only used by the CircularlyLinkedList class.
*/
struct Node {
    char var;       // Character data stored in the node
    Node* next;      // Pointer to the next node in the list
    Node* prev;      // Pointer to the previous node (used only in a doubly linked list)

    Node(char v);
};

#endif