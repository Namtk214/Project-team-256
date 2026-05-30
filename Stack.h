#ifndef STACK_H
#define STACK_H

#include <string>
#include <iostream>
#include "Vehicle.h"
using namespace std;

// Action class for stack (undo feature)
class Action {
private:
    string actionType;
    Vehicle* vehicle;
    int index;

public:
    Action(string actionType = "", Vehicle* vehicle = nullptr, int index = -1);

    string getActionType() const;
    Vehicle* getVehicle() const;
    int getIndex() const;
};

// Node structure for Stack (Linked List based)
class StackNode {
public:
    Action data;
    StackNode* next;

    StackNode(Action value);
};

// Stack class - Linked List based implementation for Action type
class Stack {
private:
    StackNode* top;    // Points to top of stack
    int size;

public:
    // Constructor and Destructor
    Stack();
    ~Stack();

    // Core stack operations
    void push(Action value);
    Action pop();
    Action peek() const;

    // Utility methods
    bool isEmpty() const;
    int getSize() const;
    void clear();
    void display() const;
};

#endif
