#include <iostream>
#include <memory>

//linked list - Dynamic structure where each node (element) points to the next

/* advantages: 
    Dynamic size
    no memory waste
    good insertion and deletion
    
    
    disadvantages: 
    extra memory for pointers
    no random access*/

struct Node{
    int data; 

    //each unique node OWNS the next node
    std::unique_ptr<Node> next;
    Node(int value = 0) : data(value), next(nullptr) {}


};

//you can insert a node and the front and back, search for a value, remove a node, and display the list
//STL CONTAINERS ALREADY DO THIS 
    //for linked list, just use std::list
    //for BST behavior use SET OR MAP

int main(){

    
    
    return 0;
}