#include "LinkedList.h"

// VehicleNode constructor
VehicleNode::VehicleNode(Vehicle* vehicle) {
    data = vehicle;
    next = nullptr;
}

// LinkedList constructor
LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

// LinkedList destructor
LinkedList::~LinkedList() {
    clear();
}

// Insert at the beginning
void LinkedList::insertAtBeginning(Vehicle* vehicle) {
    VehicleNode* newNode = new VehicleNode(vehicle);

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    size++;
}

// Insert at the end
void LinkedList::insertAtEnd(Vehicle* vehicle) {
    VehicleNode* newNode = new VehicleNode(vehicle);

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

// Insert at specific position (1-indexed)
void LinkedList::insertAtPosition(Vehicle* vehicle, int position) {
    if (position < 1 || position > size + 1) {
        std::cout << "Invalid position!" << std::endl;
        return;
    }

    if (position == 1) {
        insertAtBeginning(vehicle);
        return;
    }

    if (position == size + 1) {
        insertAtEnd(vehicle);
        return;
    }

    VehicleNode* newNode = new VehicleNode(vehicle);
    VehicleNode* current = head;

    for (int i = 1; i < position - 1; i++) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    size++;
}

// Delete at the beginning
Vehicle* LinkedList::deleteAtBeginning() {
    if (head == nullptr) {
        std::cout << "List is empty!" << std::endl;
        return nullptr;
    }

    VehicleNode* temp = head;
    Vehicle* vehicle = temp->data;

    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    }

    delete temp;
    size--;
    return vehicle;
}

// Delete at the end
Vehicle* LinkedList::deleteAtEnd() {
    if (head == nullptr) {
        std::cout << "List is empty!" << std::endl;
        return nullptr;
    }

    if (head == tail) {
        return deleteAtBeginning();
    }

    VehicleNode* current = head;
    while (current->next != tail) {
        current = current->next;
    }

    Vehicle* vehicle = tail->data;
    delete tail;
    tail = current;
    tail->next = nullptr;
    size--;

    return vehicle;
}

// Delete at specific position (1-indexed)
Vehicle* LinkedList::deleteAtPosition(int position) {
    if (position < 1 || position > size) {
        std::cout << "Invalid position!" << std::endl;
        return nullptr;
    }

    if (position == 1) {
        return deleteAtBeginning();
    }

    VehicleNode* current = head;
    for (int i = 1; i < position - 1; i++) {
        current = current->next;
    }

    VehicleNode* temp = current->next;
    Vehicle* vehicle = temp->data;
    current->next = temp->next;

    if (temp == tail) {
        tail = current;
    }

    delete temp;
    size--;
    return vehicle;
}

// Delete by value
Vehicle* LinkedList::deleteByValue(Vehicle* vehicle) {
    if (head == nullptr) {
        return nullptr;
    }

    if (head->data == vehicle) {
        return deleteAtBeginning();
    }

    VehicleNode* current = head;
    while (current->next != nullptr && current->next->data != vehicle) {
        current = current->next;
    }

    if (current->next == nullptr) {
        return nullptr;
    }

    VehicleNode* temp = current->next;
    Vehicle* foundVehicle = temp->data;
    current->next = temp->next;

    if (temp == tail) {
        tail = current;
    }

    delete temp;
    size--;
    return foundVehicle;
}

// Search for a vehicle
Vehicle* LinkedList::search(Vehicle* vehicle) const {
    VehicleNode* current = head;

    while (current != nullptr) {
        if (current->data == vehicle) {
            return current->data;
        }
        current = current->next;
    }

    return nullptr;
}

// Get vehicle at position (1-indexed)
Vehicle* LinkedList::getAt(int position) const {
    if (position < 1 || position > size) {
        return nullptr;
    }

    VehicleNode* current = head;
    for (int i = 1; i < position; i++) {
        current = current->next;
    }

    return current->data;
}

// Find position of vehicle (1-indexed, returns 0 if not found)
int LinkedList::find(Vehicle* vehicle) const {
    VehicleNode* current = head;
    int position = 1;

    while (current != nullptr) {
        if (current->data == vehicle) {
            return position;
        }
        current = current->next;
        position++;
    }

    return 0;
}

// Check if list is empty
bool LinkedList::isEmpty() const {
    return head == nullptr;
}

// Get size of list
int LinkedList::getSize() const {
    return size;
}

// Clear the entire list
void LinkedList::clear() {
    VehicleNode* current = head;

    while (current != nullptr) {
        VehicleNode* temp = current;
        current = current->next;
        delete temp->data;
        delete temp;
    }

    head = tail = nullptr;
    size = 0;
}

// Display all vehicles
void LinkedList::display() const {
    if (head == nullptr) {
        std::cout << "List is empty!" << std::endl;
        return;
    }

    VehicleNode* current = head;
    int index = 1;

    while (current != nullptr) {
        std::cout << "[" << index << "] ";
        current->data->displayInfo();
        current = current->next;
        index++;
    }
}

// Sort in ascending order (Bubble Sort)
void LinkedList::sortAscending() {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    bool swapped;
    do {
        swapped = false;
        VehicleNode* current = head;

        while (current != nullptr && current->next != nullptr) {
            if (current->data->getPrice() > current->next->data->getPrice()) {
                Vehicle* temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

// Sort in descending order (Bubble Sort)
void LinkedList::sortDescending() {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    bool swapped;
    do {
        swapped = false;
        VehicleNode* current = head;

        while (current != nullptr && current->next != nullptr) {
            if (current->data->getPrice() < current->next->data->getPrice()) {
                Vehicle* temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

// Get head pointer
VehicleNode* LinkedList::getHead() const {
    return head;
}

// Get tail pointer
VehicleNode* LinkedList::getTail() const {
    return tail;
}
