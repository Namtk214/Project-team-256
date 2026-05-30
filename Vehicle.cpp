#include "Vehicle.h"

// Default constructor
Vehicle::Vehicle() : brand(""), model(""), price(0.0) {}

// Parameterized constructor
Vehicle::Vehicle(string brand, string model, double price)
    : brand(brand), model(model), price(price) {}

// Virtual destructor
Vehicle::~Vehicle() {}

// Getters
string Vehicle::getBrand() const {
    return brand;
}

string Vehicle::getModel() const {
    return model;
}

double Vehicle::getPrice() const {
    return price;
}

// Setters
void Vehicle::setBrand(string brand) {
    this->brand = brand;
}

void Vehicle::setModel(string model) {
    this->model = model;
}

void Vehicle::setPrice(double price) {
    this->price = price;
}

// Operator overloading - compare by price
bool Vehicle::operator<(const Vehicle& other) const {
    return this->price < other.price;
}

bool Vehicle::operator>(const Vehicle& other) const {
    return this->price > other.price;
}

bool Vehicle::operator==(const Vehicle& other) const {
    return this->price == other.price;
}
