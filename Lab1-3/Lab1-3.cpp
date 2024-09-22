/*
Craig Truitt (49115566)
Code made using https://chatgpt.com/g/g-2DQzU5UZl-code-copilot
Primary Contributor: Craig Truitt
Other Contributors: Ava Everett, Jordan Cox, Alex Gao, & Jeremy Baron
*/
#include <iostream>
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "CircularlyLinkedList.h"
using namespace std;

int main() {                             // Main function to execute the program.
    SLL slist;                           // Create an instance of the Singly Linked List (SLL).
    DLL dlist;                           // Create an instance of the Doubly Linked List (DLL).
    CLL clist;                           // Create an instance of the Circularly Linked List (CLL).

    cout << "Enter a string: ";          // Prompts user for string to store
    char str[50];                          // Declare a string variable to hold user input.
    cin.getline(str, 50);                          // Read the user input string.

    for (int i = 0; str[i]; i++) {  // Iterate through each character in the input string.
        slist.insert(str[i]);            // Insert the character into the Singly Linked List.
        dlist.insert(str[i]);            // Insert the character into the Doubly Linked List.
        clist.insert(str[i]);            // Insert the character into the Circularly Linked List.
    }

    cout << "Singularly Linked List Output:\t\t"; // Display label for SLL output.
    slist.display();                     // Call the display function to show the Singly Linked List.

    cout << "Doubly Linked List Reverse Output:\t"; // Display label for DLL reverse output.
    dlist.displayReverse();              // Call the displayReverse function to show the Doubly Linked List in reverse.

    cout << "Circularly Linked List Double Output:\t"; // Display label for CLL double output.
    clist.displayTwice();                // Call the displayTwice function to show the Circularly Linked List twice.

    return 0;                            // Return 0 to indicate successful execution of the program.
}
