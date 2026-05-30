#include "Truck.h"
#include <iostream>
using namespace std;

// Initialize static pollution value
double Truck::pollution = 50.0;

// Default constructor
Truck::Truck() : Vehicle(), maxLoadCapacity(0.0), lengthBase(0.0) {}

// Parameterized constructor
Truck::Truck(string brand, string model, double price, double maxLoadCapacity, double lengthBase)
    : Vehicle(brand, model, price), maxLoadCapacity(maxLoadCapacity), lengthBase(lengthBase) {}

// Destructor
Truck::~Truck() {}

// Getters
double Truck::getMaxLoadCapacity() const {
    return maxLoadCapacity;
}

double Truck::getLengthBase() const {
    return lengthBase;
}

// Setters
void Truck::setMaxLoadCapacity(double maxLoadCapacity) {
    this->maxLoadCapacity = maxLoadCapacity;
}

void Truck::setLengthBase(double lengthBase) {
    this->lengthBase = lengthBase;
}

// Override displayInfo
void Truck::displayInfo() const {
    cout << "Truck: Brand: " << brand
         << " -- Model: " << model
         << " -- Price: $" << price
         << " -- Max Load: " << maxLoadCapacity << "kg"
         << " -- Length Base: " << lengthBase << "m"
         << " -- Pollution: " << pollution << endl;
}

// Override fuelConsumption
void Truck::fuelConsumption() const {
    cout << "Truck fuel consumption: Approximately 25-35 liters per 100km" << endl;
}

// Override getPollution
double Truck::getPollution() const {
    return Truck::pollution;
}
