# Garage Vehicle Management System

A console-based C++ application demonstrating Object-Oriented Programming principles and fundamental Data Structures.

## Project Structure

### Core Classes
- **Vehicle** (Abstract base class)
  - **Car** (Derived class)
  - **Motorcycle** (Derived class)
  - **Truck** (Derived class)
- **GarageOwner** (Manages garage inventory)
- **Customer** (Manages purchased vehicles)

### Data Structures
- **Linked List**: Manages garage inventory
- **Queue**: Handles purchase requests
- **Stack**: Implements undo functionality

### File Organization
```
Project-team-256/
├── Vehicle.h
├── Vehicle.cpp
├── Car.h
├── Car.cpp
├── Motorcycle.h
├── Motorcycle.cpp
├── Truck.h
├── Truck.cpp
├── LinkedList.h
├── Queue.h
├── Stack.h
├── GarageOwner.h
├── GarageOwner.cpp
├── Customer.h
├── Customer.cpp
├── main.cpp
├── Makefile
└── README.md
```

## OOP Concepts Implemented

- **Abstraction**: Vehicle is an abstract base class with pure virtual functions
- **Inheritance**: Car, Motorcycle, and Truck inherit from Vehicle
- **Polymorphism**: Virtual functions allow different vehicle types to be stored in the same linked list
- **Encapsulation**: Private and protected member variables with public getters/setters
- **Operator Overloading**: Comparison operators (<, >, ==) for comparing vehicles by price
- **Static Members**: Pollution values are static for each vehicle type

## Features

### GarageOwner Features
1. Add vehicles to inventory (with pollution control)
2. Remove vehicles from inventory
3. View all available vehicles
4. Sort vehicles by price (ascending/descending)
5. View pollution status
6. Process customer purchase requests from queue
7. Undo last action (ADD/REMOVE/SELL)

### Customer Features
1. View all available vehicles
2. Buy vehicles directly
3. Find vehicles within budget
4. Compare two purchased vehicles by price
5. Register purchase requests (added to queue)
6. View purchased vehicles

## Compilation and Execution

### Using Makefile (Recommended)

Compile the project:
```bash
make
```

Run the program:
```bash
make run
```

Clean build files:
```bash
make clean
```

### Manual Compilation

```bash
g++ -std=c++11 -Wall -c Vehicle.cpp
g++ -std=c++11 -Wall -c Car.cpp
g++ -std=c++11 -Wall -c Motorcycle.cpp
g++ -std=c++11 -Wall -c Truck.cpp
g++ -std=c++11 -Wall -c GarageOwner.cpp
g++ -std=c++11 -Wall -c Customer.cpp
g++ -std=c++11 -Wall -c main.cpp
g++ -std=c++11 -Wall -o garage_system Vehicle.o Car.o Motorcycle.o Truck.o GarageOwner.o Customer.o main.o
./garage_system
```

## Usage

When you run the program, you'll see a main menu:

```
========== MAIN MENU ==========
1. Login as GarageOwner
2. Login as Customer
3. Exit
```

### As GarageOwner:
- Add, remove, and manage vehicle inventory
- Monitor pollution levels
- Process customer purchase requests
- Undo operations

### As Customer:
- Browse available vehicles
- Purchase vehicles directly or via request queue
- View and compare purchased vehicles
- Search by budget

## Pollution Control

Each vehicle type has a pollution value:
- Car: 30
- Motorcycle: 10
- Truck: 50

The garage has a maximum pollution limit of 100. Vehicles cannot be added if they exceed this limit.

## Example Session

1. Login as GarageOwner
2. View all vehicles (3 default vehicles are pre-loaded)
3. Add a new motorcycle
4. View pollution status
5. Sort vehicles by price
6. Return to main menu
7. Login as Customer
8. Buy a vehicle
9. View bought vehicles
10. Exit

## Memory Management

The project properly manages dynamic memory:
- Vehicles are created with `new` and deleted appropriately
- GarageOwner destructor deletes all vehicles in inventory
- Customer destructor deletes all purchased vehicles
- Undo functionality maintains vehicle pointers safely

## Requirements

- C++ compiler with C++11 support (g++, clang++, etc.)
- Standard Template Library (STL) for queue, stack, and vector

## Notes

- All vehicle comparisons are based on price
- The undo feature works for ADD, REMOVE, and SELL operations
- Purchase requests are processed in FIFO order (queue)
- Input validation is implemented for menu choices and indexes
