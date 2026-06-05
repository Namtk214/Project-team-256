#ifndef GARAGEOWNER_H
#define GARAGEOWNER_H

#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "Customer.h"
using namespace std;


class GarageOwner {
private:
    VehicleNode* head;
    Stack actionHistory;  // Custom Stack implementation

public:
    static double totalPollution;
    static double maxPollution;

    // Constructor and destructor
    GarageOwner();
    ~GarageOwner();

    // Core methods
    void addVehicle(Vehicle* v);
    void removeVehicle(int index);
    void showGarage() const;
    Vehicle* sellVehicle(int index);
    void findByBudget(double budget) const;
    void sortByPriceAscending();
    void sortByPriceDescending();
    void viewPollutionStatus() const;
    void processPurchaseRequestQueue(Queue& purchaseQueue, Customer& customer);
    void undoLastAction();
    int getVehicleCount() const;
    Vehicle* getVehicleAtIndex(int index) const;
};

#endif
