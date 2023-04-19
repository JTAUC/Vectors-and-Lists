#include "LinkedList.h"

LinkedList::LinkedList() {
    head = NULL;
}

void LinkedList::addNode(int value, int occurances) {
    Node* newNode = new Node;
    newNode->occ = occurances;
    newNode->value = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void LinkedList::removeNode(int value) {
    if (head == NULL) { return; }

    if (head->value == value) {
        Node* temp = head;
        head = head->next;

        delete temp;
        return;
    }

    Node* current = head;
    while (current->next != NULL && current->next->value != value) {
        current = current->next;
    }

    if (current->next == NULL) { return; }

    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
}

void LinkedList::printList() {
    Node* current = head;
    while (current != NULL) {
        cout << current->value << " occurs: " << current->occ << endl;
        current = current->next;
    }
    cout << endl;
}

int LinkedList::SumOfNodes() {
    int count = 0;
    Node* current = head;

    while (current != NULL) {
        count += current->occ;
        current = current->next;
    }
    return count;
}
