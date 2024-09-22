/*
Craig Truitt (49115566)
Code made using https://chatgpt.com/g/g-2DQzU5UZl-code-copilot
Primary Contributor: Craig Truitt
Other Contributors: Ava Everett, Jordan Cox, Alex Gao, & Jeremy Baron
*/
#include "Node.h"

//Constructor for Node class
Node::Node(char v) {
    var = v;      //Store information
    next = nullptr;   //Initiate without next node
    prev = nullptr;   //Initiate without previous node
}