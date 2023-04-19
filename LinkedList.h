#pragma once
#include "Header.h"

class Node {
public:
    int value;
    int occ;
    Node* next;
};

class LinkedList
{
private:
    Node* head;
public:
    LinkedList();

    // Function to add a node to the linked list
    void addNode(int value, int occurances);

    // Function to remove a node from the linked list
    void removeNode(int value);

    // Function to print all elements of the linked list
    void printList();

    // Function to return sum of all nodes of the linked list
    int SumOfNodes();
};

