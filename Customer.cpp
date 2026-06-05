#include "Customer.h"
#include <iostream>
using namespace std;

// Constructor
Customer::Customer(string name) : name(name) {}

// Destructor
Customer::~Customer() {
    // Delete all bought vehicles
    for (Vehicle* v : boughtVehicles) {
        delete v;
    }
}

// Get customer name
string Customer::getName() const {
    return name;
}

// Buy vehicle
void Customer::buyVehicle(Vehicle* v) {
    if (v == nullptr) {
        cout << "Error: Cannot buy null vehicle." << endl;
        return;
    }

    boughtVehicles.push_back(v);
}

// Show bought vehicles
void Customer::showBoughtVehicles() const {
    if (boughtVehicles.empty()) {
        cout << name << " has not bought any vehicles yet." << endl;
        return;
    }

    cout << "========== " << name << "'s BOUGHT VEHICLES ==========" << endl;
    for (size_t i = 0; i < boughtVehicles.size(); i++) {
        cout << "[" << (i + 1) << "] ";
        boughtVehicles[i]->displayInfo();
    }
    cout << "================================================" << endl;
}

// Compare two bought vehicles
void Customer::compareBoughtVehicles(int index1, int index2) const {
    if (index1 < 1 || index1 > (int)boughtVehicles.size() ||
        index2 < 1 || index2 > (int)boughtVehicles.size()) {
        cout << "Error: Invalid index." << endl;
        return;
    }

    Vehicle* v1 = boughtVehicles[index1 - 1];
    Vehicle* v2 = boughtVehicles[index2 - 1];

    cout << "========== COMPARISON ==========" << endl;
    cout << "Vehicle 1: " << v1->getBrand() << " " << v1->getModel()
         << " - $" << v1->getPrice() << endl;
    cout << "Vehicle 2: " << v2->getBrand() << " " << v2->getModel()
         << " - $" << v2->getPrice() << endl;

    if (*v1 > *v2) {
        cout << "Vehicle 1 is more expensive than Vehicle 2." << endl;
    } else if (*v1 < *v2) {
        cout << "Vehicle 1 is cheaper than Vehicle 2." << endl;
    } else {
        cout << "Both vehicles have the same price." << endl;
    }
    cout << "===============================" << endl;
}

// Get bought vehicle count
int Customer::getBoughtCount() const {
    return boughtVehicles.size();
}
