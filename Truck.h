#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck : public Vehicle {
private:
    double maxLoadCapacity;
    double lengthBase;

public:
    static double pollution;

    // Constructors
    Truck();
    Truck(string brand, string model, double price, double maxLoadCapacity, double lengthBase);

    // Destructor
    ~Truck();

    // Getters
    double getMaxLoadCapacity() const;
    double getLengthBase() const;

    // Setters
    void setMaxLoadCapacity(double maxLoadCapacity);
    void setLengthBase(double lengthBase);

    // Override pure virtual functions
    void displayInfo() const override;
    void fuelConsumption() const override;
    double getPollution() const override;
};

#endif
