#include "Motorcycle.h"
#include <iostream>
using namespace std;

// Initialize static pollution value
double Motorcycle::pollution = 10.0;

// Default constructor
Motorcycle::Motorcycle() : Vehicle(), engineType(""), maxSpeed(0.0) {}

// Parameterized constructor
Motorcycle::Motorcycle(string brand, string model, double price, string engineType, double maxSpeed)
    : Vehicle(brand, model, price), engineType(engineType), maxSpeed(maxSpeed) {}

// Destructor
Motorcycle::~Motorcycle() {}

// Getters
string Motorcycle::getEngineType() const {
    return engineType;
}

double Motorcycle::getMaxSpeed() const {
    return maxSpeed;
}

// Setters
void Motorcycle::setEngineType(string engineType) {
    this->engineType = engineType;
}

void Motorcycle::setMaxSpeed(double maxSpeed) {
    this->maxSpeed = maxSpeed;
}

// Override displayInfo
void Motorcycle::displayInfo() const {
    cout << "Motorcycle: Brand: " << brand
         << " -- Model: " << model
         << " -- Price: $" << price
         << " -- Engine Type: " << engineType
         << " -- Max Speed: " << maxSpeed << "km/h"
         << " -- Pollution: " << pollution << endl;
}

// Override fuelConsumption
void Motorcycle::fuelConsumption() const {
    cout << "Motorcycle fuel consumption: Approximately 2-4 liters per 100km" << endl;
}

// Override getPollution
double Motorcycle::getPollution() const {
    return Motorcycle::pollution;
}
