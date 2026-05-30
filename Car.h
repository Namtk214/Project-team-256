#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
private:
    string color;
    int numSeats;

public:
    static double pollution;

    // Constructors
    Car();
    Car(string brand, string model, double price, string color, int numSeats);

    // Destructor
    ~Car();

    // Getters
    string getColor() const;
    int getNumSeats() const;

    // Setters
    void setColor(string color);
    void setNumSeats(int numSeats);

    // Override pure virtual functions
    void displayInfo() const override;
    void fuelConsumption() const override;
    double getPollution() const override;
};

#endif
