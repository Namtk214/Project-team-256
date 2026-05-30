#include "Car.h"
#include <iostream>
using namespace std;

// Initialize static pollution value
double Car::pollution = 30.0;

// Default constructor
Car::Car() : Vehicle(), color(""), numSeats(0) {}

// Parameterized constructor
Car::Car(string brand, string model, double price, string color, int numSeats)
    : Vehicle(brand, model, price), color(color), numSeats(numSeats) {}

// Destructor
Car::~Car() {}

// Getters
string Car::getColor() const {
    return color;
}

int Car::getNumSeats() const {
    return numSeats;
}

// Setters
void Car::setColor(string color) {
    this->color = color;
}

void Car::setNumSeats(int numSeats) {
    this->numSeats = numSeats;
}

// Override displayInfo
void Car::displayInfo() const {
    cout << "Car: Brand: " << brand
         << " -- Model: " << model
         << " -- Price: $" << price
         << " -- Color: " << color
         << " -- Seats: " << numSeats
         << " -- Pollution: " << pollution << endl;
}

// Override fuelConsumption
void Car::fuelConsumption() const {
    cout << "Car fuel consumption: Approximately 7-10 liters per 100km" << endl;
}

// Override getPollution
double Car::getPollution() const {
    return Car::pollution;
}
