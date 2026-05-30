#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Vehicle.h"
#include <string>
#include <vector>
using namespace std;

class Customer {
private:
    string name;
    vector<Vehicle*> boughtVehicles;

public:
    // Constructor and destructor
    Customer(string name);
    ~Customer();

    // Getter
    string getName() const;

    // Core methods
    void buyVehicle(Vehicle* v);
    void showBoughtVehicles() const;
    void compareBoughtVehicles(int index1, int index2) const;
    int getBoughtCount() const;
};

#endif
