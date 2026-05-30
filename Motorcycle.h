#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Vehicle.h"

class Motorcycle : public Vehicle {
private:
    string engineType;
    double maxSpeed;

public:
    static double pollution;

    // Constructors
    Motorcycle();
    Motorcycle(string brand, string model, double price, string engineType, double maxSpeed);

    // Destructor
    ~Motorcycle();

    // Getters
    string getEngineType() const;
    double getMaxSpeed() const;

    // Setters
    void setEngineType(string engineType);
    void setMaxSpeed(double maxSpeed);

    // Override pure virtual functions
    void displayInfo() const override;
    void fuelConsumption() const override;
    double getPollution() const override;
};

#endif
