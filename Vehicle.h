#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

class Vehicle {
protected:
    string brand;
    string model;
    double price;

public:
    // Constructors
    Vehicle();
    Vehicle(string brand, string model, double price);

    // Virtual destructor
    virtual ~Vehicle();

    // Getters
    string getBrand() const;
    string getModel() const;
    double getPrice() const;

    // Setters
    void setBrand(string brand);
    void setModel(string model);
    void setPrice(double price);

    // Pure virtual functions (abstract methods)
    virtual void displayInfo() const = 0;
    virtual void fuelConsumption() const = 0;
    virtual double getPollution() const = 0;

    // Operator overloading (compare by price)
    bool operator<(const Vehicle& other) const;
    bool operator>(const Vehicle& other) const;
    bool operator==(const Vehicle& other) const;
};

#endif
