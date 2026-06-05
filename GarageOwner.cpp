#include "GarageOwner.h"
#include "Customer.h"
#include <iostream>
using namespace std;

// Initialize static variables
double GarageOwner::totalPollution = 0.0;
double GarageOwner::maxPollution = 100.0;

// Constructor
GarageOwner::GarageOwner() : head(nullptr) {}

// Destructor
GarageOwner::~GarageOwner() {
    // Delete all vehicles in the linked list
    VehicleNode* current = head;
    while (current != nullptr) {
        VehicleNode* temp = current;
        current = current->next;
        delete temp->data;
        delete temp;
    }
}

// Add vehicle to garage
void GarageOwner::addVehicle(Vehicle* v) {
    if (v == nullptr) {
        cout << "Error: Cannot add null vehicle." << endl;
        return;
    }

    double newTotalPollution = totalPollution + v->getPollution();

    if (newTotalPollution > maxPollution) {
        cout << "Error: Cannot add this vehicle because total pollution would exceed the maximum allowed limit." << endl;
        delete v;
        return;
    }

    // Create new node
    VehicleNode* newNode = new VehicleNode(v);

    // Insert at the end of the list
    if (head == nullptr) {
        head = newNode;
    } else {
        VehicleNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    totalPollution = newTotalPollution;
    actionHistory.push(Action("ADD", v));
    cout << "Vehicle added successfully!" << endl;
}

// Remove vehicle from garage by index
void GarageOwner::removeVehicle(int index) {
    if (head == nullptr) {
        cout << "Error: Garage is empty." << endl;
        return;
    }

    if (index < 1) {
        cout << "Error: Invalid index." << endl;
        return;
    }

    VehicleNode* current = head;
    VehicleNode* prev = nullptr;
    int currentIndex = 1;

    // Find the node at the given index
    while (current != nullptr && currentIndex < index) {
        prev = current;
        current = current->next;
        currentIndex++;
    }

    if (current == nullptr) {
        cout << "Error: Invalid index." << endl;
        return;
    }

    // Remove the node
    if (prev == nullptr) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    totalPollution -= current->data->getPollution();
    actionHistory.push(Action("REMOVE", current->data));

    // Note: We keep the vehicle pointer for undo, don't delete it immediately
    delete current; // Only delete the node
    cout << "Vehicle removed successfully!" << endl;
}

// Display all vehicles in garage
void GarageOwner::showGarage() const {
    if (head == nullptr) {
        cout << "Garage is empty." << endl;
        return;
    }

    cout << "========== GARAGE VEHICLE LIST ==========" << endl;
    VehicleNode* current = head;
    int index = 1;

    while (current != nullptr) {
        cout << "[" << index << "] ";
        current->data->displayInfo();
        current = current->next;
        index++;
    }
    cout << "=========================================" << endl;
}

// Sell vehicle (remove and transfer ownership)
Vehicle* GarageOwner::sellVehicle(int index) {
    if (head == nullptr) {
        cout << "Error: Garage is empty." << endl;
        return nullptr;
    }

    if (index < 1) {
        cout << "Error: Invalid index." << endl;
        return nullptr;
    }

    VehicleNode* current = head;
    VehicleNode* prev = nullptr;
    int currentIndex = 1;

    // Find the node at the given index
    while (current != nullptr && currentIndex < index) {
        prev = current;
        current = current->next;
        currentIndex++;
    }

    if (current == nullptr) {
        cout << "Error: Invalid index." << endl;
        return nullptr;
    }

    // Remove the node
    if (prev == nullptr) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    Vehicle* soldVehicle = current->data;
    totalPollution -= soldVehicle->getPollution();
    actionHistory.push(Action("SELL", soldVehicle));

    delete current; // Delete only the node, not the vehicle
    return soldVehicle;
}

// Find vehicles by budget
void GarageOwner::findByBudget(double budget) const {
    if (head == nullptr) {
        cout << "Garage is empty." << endl;
        return;
    }

    cout << "========== VEHICLES WITHIN BUDGET ==========" << endl;
    VehicleNode* current = head;
    bool found = false;

    while (current != nullptr) {
        if (current->data->getPrice() <= budget) {
            current->data->displayInfo();
            found = true;
        }
        current = current->next;
    }

    if (!found) {
        cout << "No vehicles found within your budget of $" << budget << endl;
    }
    cout << "===========================================" << endl;
}

// Sort vehicles by price (ascending)
void GarageOwner::sortByPriceAscending() {
    if (head == nullptr || head->next == nullptr) {
        cout << "Not enough vehicles to sort." << endl;
        return;
    }

    bool swapped;
    do {
        swapped = false;
        VehicleNode* current = head;

        while (current != nullptr && current->next != nullptr) {
            if (current->data->getPrice() > current->next->data->getPrice()) {
                // Swap the Vehicle* data
                Vehicle* temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);

    cout << "Vehicles sorted by price (ascending)." << endl;
}

// Sort vehicles by price (descending)
void GarageOwner::sortByPriceDescending() {
    if (head == nullptr || head->next == nullptr) {
        cout << "Not enough vehicles to sort." << endl;
        return;
    }

    bool swapped;
    do {
        swapped = false;
        VehicleNode* current = head;

        while (current != nullptr && current->next != nullptr) {
            if (current->data->getPrice() < current->next->data->getPrice()) {
                // Swap the Vehicle* data
                Vehicle* temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);

    cout << "Vehicles sorted by price (descending)." << endl;
}

// View pollution status
void GarageOwner::viewPollutionStatus() const {
    cout << "========== POLLUTION STATUS ==========" << endl;
    cout << "Current Total Pollution: " << totalPollution << endl;
    cout << "Maximum Allowed Pollution: " << maxPollution << endl;
    cout << "Remaining Capacity: " << (maxPollution - totalPollution) << endl;
    cout << "======================================" << endl;
}

// Process purchase request queue
void GarageOwner::processPurchaseRequestQueue(Queue& purchaseQueue, Customer& customer) {
    if (purchaseQueue.isEmpty()) {
        cout << "No purchase requests in queue." << endl;
        return;
    }

    cout << "Processing next purchase request..." << endl;
    PurchaseRequest request = purchaseQueue.dequeue();

    cout << "Customer: " << request.getCustomerName() << endl;
    cout << "Requested vehicle index: " << request.getVehicleIndex() << endl;

    Vehicle* vehicle = sellVehicle(request.getVehicleIndex());
    if (vehicle != nullptr) {
        customer.buyVehicle(vehicle);
        cout << "Transaction successful." << endl;
        cout << request.getCustomerName() << " bought "
             << vehicle->getBrand() << " " << vehicle->getModel() << "." << endl;
    } else {
        cout << "Transaction failed. Vehicle not available." << endl;
    }
}

// Undo last action
void GarageOwner::undoLastAction() {
    if (actionHistory.isEmpty()) {
        cout << "No action to undo." << endl;
        return;
    }

    Action lastAction = actionHistory.pop();

    if (lastAction.getActionType() == "ADD") {
        // Undo ADD: Remove the last added vehicle
        VehicleNode* current = head;
        VehicleNode* prev = nullptr;

        // Find the vehicle that was added
        while (current != nullptr) {
            if (current->data == lastAction.getVehicle()) {
                if (prev == nullptr) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                totalPollution -= current->data->getPollution();
                delete current->data;
                delete current;
                cout << "Undo: Vehicle addition reversed." << endl;
                return;
            }
            prev = current;
            current = current->next;
        }
    } else if (lastAction.getActionType() == "REMOVE") {
        // Undo REMOVE: Add the vehicle back
        Vehicle* vehicle = lastAction.getVehicle();
        VehicleNode* newNode = new VehicleNode(vehicle);

        // Insert at the end
        if (head == nullptr) {
            head = newNode;
        } else {
            VehicleNode* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }

        totalPollution += vehicle->getPollution();
        cout << "Undo: Vehicle removal reversed." << endl;
    } else if (lastAction.getActionType() == "SELL") {
        // Undo SELL: Add the vehicle back to garage
        Vehicle* vehicle = lastAction.getVehicle();
        VehicleNode* newNode = new VehicleNode(vehicle);

        // Insert at the end
        if (head == nullptr) {
            head = newNode;
        } else {
            VehicleNode* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }

        totalPollution += vehicle->getPollution();
        cout << "Undo: Vehicle sale reversed." << endl;
    }
}

// Get vehicle count
int GarageOwner::getVehicleCount() const {
    int count = 0;
    VehicleNode* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// Get vehicle at specific index
Vehicle* GarageOwner::getVehicleAtIndex(int index) const {
    if (index < 1) {
        return nullptr;
    }

    VehicleNode* current = head;
    int currentIndex = 1;

    while (current != nullptr && currentIndex < index) {
        current = current->next;
        currentIndex++;
    }

    if (current != nullptr) {
        return current->data;
    }
    return nullptr;
}
