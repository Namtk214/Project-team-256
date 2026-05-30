#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Vehicle.h"
#include <iostream>

// Node structure for linked list
class VehicleNode {
public:
    Vehicle* data;
    VehicleNode* next;

    VehicleNode(Vehicle* vehicle);
};

// Linked List class with full implementation
class LinkedList {
private:
    VehicleNode* head;
    VehicleNode* tail;
    int size;

public:
    // Constructor and Destructor
    LinkedList();
    ~LinkedList();

    // Core operations
    void insertAtBeginning(Vehicle* vehicle);
    void insertAtEnd(Vehicle* vehicle);
    void insertAtPosition(Vehicle* vehicle, int position);

    Vehicle* deleteAtBeginning();
    Vehicle* deleteAtEnd();
    Vehicle* deleteAtPosition(int position);
    Vehicle* deleteByValue(Vehicle* vehicle);

    // Search and access
    Vehicle* search(Vehicle* vehicle) const;
    Vehicle* getAt(int position) const;
    int find(Vehicle* vehicle) const;

    // Utility methods
    bool isEmpty() const;
    int getSize() const;
    void clear();
    void display() const;

    // Sorting
    void sortAscending();
    void sortDescending();

    // Getters for iteration
    VehicleNode* getHead() const;
    VehicleNode* getTail() const;
};

#endif
