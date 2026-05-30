#include "Queue.h"

// ============= PURCHASEREQUEST CLASS IMPLEMENTATION =============

PurchaseRequest::PurchaseRequest(string customerName, int vehicleIndex) {
    this->customerName = customerName;
    this->vehicleIndex = vehicleIndex;
}

string PurchaseRequest::getCustomerName() const {
    return customerName;
}

int PurchaseRequest::getVehicleIndex() const {
    return vehicleIndex;
}

// ============= QUEUENODE IMPLEMENTATION =============

QueueNode::QueueNode(PurchaseRequest value) {
    data = value;
    next = nullptr;
}

// ============= QUEUE IMPLEMENTATION =============

// Constructor
Queue::Queue() {
    front = nullptr;
    rear = nullptr;
    size = 0;
}

// Destructor
Queue::~Queue() {
    clear();
}

// Enqueue - add element at rear
void Queue::enqueue(PurchaseRequest value) {
    QueueNode* newNode = new QueueNode(value);

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    size++;
}

// Dequeue - remove element from front
PurchaseRequest Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue underflow! Queue is empty." << endl;
        return PurchaseRequest();  // Return default PurchaseRequest
    }

    QueueNode* temp = front;
    PurchaseRequest value = temp->data;
    front = front->next;

    if (front == nullptr) {
        rear = nullptr;
    }

    delete temp;
    size--;

    return value;
}

// Get front element without removing
PurchaseRequest Queue::getFront() const {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return PurchaseRequest();  // Return default PurchaseRequest
    }

    return front->data;
}

// Get rear element without removing
PurchaseRequest Queue::getRear() const {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return PurchaseRequest();  // Return default PurchaseRequest
    }

    return rear->data;
}

// Check if queue is empty
bool Queue::isEmpty() const {
    return front == nullptr;
}

// Get current size of queue
int Queue::getSize() const {
    return size;
}

// Clear all elements from queue
void Queue::clear() {
    while (!isEmpty()) {
        dequeue();
    }
}

// Display queue contents (front to rear)
void Queue::display() const {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }

    cout << "========== PURCHASE REQUEST QUEUE ==========" << endl;
    cout << "Front to Rear:" << endl;

    QueueNode* current = front;
    int index = 1;

    while (current != nullptr) {
        cout << "[" << index << "] Customer: " << current->data.getCustomerName()
             << " | Vehicle Index: " << current->data.getVehicleIndex() << endl;
        current = current->next;
        index++;
    }
    cout << "Total requests in queue: " << size << endl;
    cout << "===========================================" << endl;
}
