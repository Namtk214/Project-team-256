#ifndef QUEUE_H
#define QUEUE_H

#include <string>
#include <iostream>
using namespace std;

// Purchase request class for queue
class PurchaseRequest {
private:
    string customerName;
    int vehicleIndex;

public:
    PurchaseRequest(string customerName = "", int vehicleIndex = 0);

    string getCustomerName() const;
    int getVehicleIndex() const;
};

// Node structure for Queue (Linked List based)
class QueueNode {
public:
    PurchaseRequest data;
    QueueNode* next;

    QueueNode(PurchaseRequest value);
};

// Queue class - Linked List based implementation for PurchaseRequest type
class Queue {
private:
    QueueNode* front;    // Points to front of queue
    QueueNode* rear;     // Points to rear of queue
    int size;

public:
    // Constructor and Destructor
    Queue();
    ~Queue();

    // Core queue operations
    void enqueue(PurchaseRequest value);
    PurchaseRequest dequeue();
    PurchaseRequest getFront() const;
    PurchaseRequest getRear() const;

    // Utility methods
    bool isEmpty() const;
    int getSize() const;
    void clear();
    void display() const;
};

#endif
