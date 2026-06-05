#include <iostream>
#include <limits>
#include "GarageOwner.h"
#include "Customer.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Truck.h"
#include "Queue.h"

using namespace std;

// Function prototypes
void garageOwnerMenu(GarageOwner& garage, Queue& purchaseQueue, Customer& customer);
void customerMenu(GarageOwner& garage, Queue& purchaseQueue, Customer& customer);
void addVehicleMenu(GarageOwner& garage);

int main() {
    GarageOwner garage;
    Customer customer("DefaultCustomer");
    Queue purchaseQueue;  // Custom Queue implementation

    // Add some default vehicles
    garage.addVehicle(new Car("Toyota", "Corolla", 20000, "Red", 5));
    garage.addVehicle(new Motorcycle("Yamaha", "R15", 1500, "150cc", 180));
    garage.addVehicle(new Truck("Volvo", "FH16", 120000, 25000, 8));

    cout << "=========================================" << endl;
    cout << "  GARAGE VEHICLE MANAGEMENT SYSTEM" << endl;
    cout << "=========================================" << endl;

    int mainChoice;
    bool running = true;

    while (running) {
        cout << "\n========== MAIN MENU ==========" << endl;
        cout << "1. Login as GarageOwner" << endl;
        cout << "2. Login as Customer" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> mainChoice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (mainChoice) {
            case 1:
                garageOwnerMenu(garage, purchaseQueue, customer);
                break;
            case 2:
                customerMenu(garage, purchaseQueue, customer);
                break;
            case 3:
                cout << "Thank you for using Garage Vehicle Management System!" << endl;
                running = false;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}

// Garage Owner Menu
void garageOwnerMenu(GarageOwner& garage, Queue& purchaseQueue, Customer& customer) {
    int choice;
    bool back = false;

    while (!back) {
        cout << "\n========== GARAGE OWNER MENU ==========" << endl;
        cout << "1. Add a vehicle" << endl;
        cout << "2. Remove a vehicle" << endl;
        cout << "3. View all vehicles" << endl;
        cout << "4. Sort vehicles by price" << endl;
        cout << "5. View pollution status" << endl;
        cout << "6. Process purchase request queue" << endl;
        cout << "7. Undo last action" << endl;
        cout << "8. Back to main menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                addVehicleMenu(garage);
                break;
            case 2: {
                garage.showGarage();
                cout << "Enter vehicle index to remove: ";
                int index;
                cin >> index;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input." << endl;
                } else {
                    garage.removeVehicle(index);
                }
                break;
            }
            case 3:
                garage.showGarage();
                break;
            case 4: {
                cout << "Sort by: 1. Ascending  2. Descending" << endl;
                cout << "Enter your choice: ";
                int sortChoice;
                cin >> sortChoice;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input." << endl;
                } else if (sortChoice == 1) {
                    garage.sortByPriceAscending();
                    garage.showGarage();
                } else if (sortChoice == 2) {
                    garage.sortByPriceDescending();
                    garage.showGarage();
                } else {
                    cout << "Invalid option." << endl;
                }
                break;
            }
            case 5:
                garage.viewPollutionStatus();
                break;
            case 6:
                garage.processPurchaseRequestQueue(purchaseQueue, customer);
                break;
            case 7:
                garage.undoLastAction();
                break;
            case 8:
                back = true;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }
}

// Customer Menu
void customerMenu(GarageOwner& garage, Queue& purchaseQueue, Customer& customer) {
    int choice;
    bool back = false;

    while (!back) {
        cout << "\n========== CUSTOMER MENU ==========" << endl;
        cout << "1. Show all vehicles" << endl;
        cout << "2. Buy a vehicle directly" << endl;
        cout << "3. Find vehicles by budget" << endl;
        cout << "4. Compare two bought vehicles" << endl;
        cout << "5. Register purchase request" << endl;
        cout << "6. View bought vehicles" << endl;
        cout << "7. Back to main menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                garage.showGarage();
                break;
            case 2: {
                garage.showGarage();
                cout << "Enter vehicle index to buy: ";
                int index;
                cin >> index;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input." << endl;
                } else {
                    Vehicle* v = garage.sellVehicle(index);
                    if (v != nullptr) {
                        customer.buyVehicle(v);
                        cout << "Purchase successful! " << customer.getName() << " bought "
                             << v->getBrand() << " " << v->getModel()
                             << " for $" << v->getPrice() << endl;
                    }
                }
                break;
            }
            case 3: {
                cout << "Enter your budget: $";
                double budget;
                cin >> budget;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input." << endl;
                } else {
                    garage.findByBudget(budget);
                }
                break;
            }
            case 4: {
                customer.showBoughtVehicles();
                if (customer.getBoughtCount() >= 2) {
                    cout << "Enter first vehicle index: ";
                    int index1;
                    cin >> index1;
                    cout << "Enter second vehicle index: ";
                    int index2;
                    cin >> index2;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input." << endl;
                    } else {
                        customer.compareBoughtVehicles(index1, index2);
                    }
                }
                break;
            }
            case 5: {
                garage.showGarage();
                cout << "Enter your name: ";
                cin.ignore();
                string customerName;
                getline(cin, customerName);
                cout << "Enter vehicle index you want to buy: ";
                int vehicleIndex;
                cin >> vehicleIndex;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input." << endl;
                } else {
                    purchaseQueue.enqueue(PurchaseRequest(customerName, vehicleIndex));
                    cout << "Purchase request added successfully." << endl;
                    cout << "Current waiting queue size: " << purchaseQueue.getSize() << endl;
                }
                break;
            }
            case 6:
                customer.showBoughtVehicles();
                break;
            case 7:
                back = true;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }
}

// Add Vehicle Menu
void addVehicleMenu(GarageOwner& garage) {
    cout << "\nSelect vehicle type:" << endl;
    cout << "1. Car" << endl;
    cout << "2. Motorcycle" << endl;
    cout << "3. Truck" << endl;
    cout << "Enter your choice: ";

    int typeChoice;
    cin >> typeChoice;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input." << endl;
        return;
    }

    cin.ignore();
    string brand, model;
    double price;

    cout << "Enter brand: ";
    getline(cin, brand);
    cout << "Enter model: ";
    getline(cin, model);
    cout << "Enter price: $";
    cin >> price;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input." << endl;
        return;
    }

    switch (typeChoice) {
        case 1: {
            string color;
            int numSeats;
            cout << "Enter color: ";
            cin.ignore();
            getline(cin, color);
            cout << "Enter number of seats: ";
            cin >> numSeats;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input." << endl;
                return;
            }
            garage.addVehicle(new Car(brand, model, price, color, numSeats));
            break;
        }
        case 2: {
            string engineType;
            double maxSpeed;
            cout << "Enter engine type: ";
            cin.ignore();
            getline(cin, engineType);
            cout << "Enter max speed (km/h): ";
            cin >> maxSpeed;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input." << endl;
                return;
            }
            garage.addVehicle(new Motorcycle(brand, model, price, engineType, maxSpeed));
            break;
        }
        case 3: {
            double maxLoadCapacity, lengthBase;
            cout << "Enter max load capacity (kg): ";
            cin >> maxLoadCapacity;
            cout << "Enter length base (m): ";
            cin >> lengthBase;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input." << endl;
                return;
            }
            garage.addVehicle(new Truck(brand, model, price, maxLoadCapacity, lengthBase));
            break;
        }
        default:
            cout << "Invalid vehicle type." << endl;
    }
}
