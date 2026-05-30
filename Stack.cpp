#include "Stack.h"

// ============= ACTION CLASS IMPLEMENTATION =============

Action::Action(string actionType, Vehicle* vehicle, int index) {
    this->actionType = actionType;
    this->vehicle = vehicle;
    this->index = index;
}

string Action::getActionType() const {
    return actionType;
}

Vehicle* Action::getVehicle() const {
    return vehicle;
}

int Action::getIndex() const {
    return index;
}

// ============= STACKNODE IMPLEMENTATION =============

StackNode::StackNode(Action value) {
    data = value;
    next = nullptr;
}

// ============= STACK IMPLEMENTATION =============

// Constructor
Stack::Stack() {
    top = nullptr;
    size = 0;
}

// Destructor
Stack::~Stack() {
    clear();
}

// Push element onto stack (add at top)
void Stack::push(Action value) {
    StackNode* newNode = new StackNode(value);
    newNode->next = top;
    top = newNode;
    size++;
}

// Pop element from stack (remove from top)
Action Stack::pop() {
    if (isEmpty()) {
        cout << "Stack underflow! Stack is empty." << endl;
        return Action();  // Return default Action
    }

    StackNode* temp = top;
    Action value = temp->data;
    top = top->next;
    delete temp;
    size--;

    return value;
}

// Peek at top element without removing
Action Stack::peek() const {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return Action();  // Return default Action
    }

    return top->data;
}

// Check if stack is empty
bool Stack::isEmpty() const {
    return top == nullptr;
}

// Get current size of stack
int Stack::getSize() const {
    return size;
}

// Clear all elements from stack
void Stack::clear() {
    while (!isEmpty()) {
        pop();
    }
}

// Display stack contents (top to bottom)
void Stack::display() const {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return;
    }

    cout << "========== ACTION HISTORY (Stack) ==========" << endl;
    cout << "Top to Bottom:" << endl;

    StackNode* current = top;
    int index = 1;

    while (current != nullptr) {
        cout << "[" << index << "] Action Type: " << current->data.getActionType();
        if (current->data.getVehicle() != nullptr) {
            cout << " | Vehicle: " << current->data.getVehicle()->getBrand()
                 << " " << current->data.getVehicle()->getModel();
        }
        cout << endl;
        current = current->next;
        index++;
    }
    cout << "Total actions in stack: " << size << endl;
    cout << "===========================================" << endl;
}
