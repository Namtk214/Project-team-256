# Makefile for Garage Vehicle Management System

CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = garage_system

# Object files
OBJS = Vehicle.o Car.o Motorcycle.o Truck.o LinkedList.o Stack.o Queue.o GarageOwner.o Customer.o main.o

# Build target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files
Vehicle.o: Vehicle.cpp Vehicle.h
	$(CXX) $(CXXFLAGS) -c Vehicle.cpp

Car.o: Car.cpp Car.h Vehicle.h
	$(CXX) $(CXXFLAGS) -c Car.cpp

Motorcycle.o: Motorcycle.cpp Motorcycle.h Vehicle.h
	$(CXX) $(CXXFLAGS) -c Motorcycle.cpp

Truck.o: Truck.cpp Truck.h Vehicle.h
	$(CXX) $(CXXFLAGS) -c Truck.cpp

LinkedList.o: LinkedList.cpp LinkedList.h Vehicle.h
	$(CXX) $(CXXFLAGS) -c LinkedList.cpp

Stack.o: Stack.cpp Stack.h Vehicle.h
	$(CXX) $(CXXFLAGS) -c Stack.cpp

Queue.o: Queue.cpp Queue.h
	$(CXX) $(CXXFLAGS) -c Queue.cpp

GarageOwner.o: GarageOwner.cpp GarageOwner.h LinkedList.h Stack.h Queue.h Customer.h
	$(CXX) $(CXXFLAGS) -c GarageOwner.cpp

Customer.o: Customer.cpp Customer.h Vehicle.h
	$(CXX) $(CXXFLAGS) -c Customer.cpp

main.o: main.cpp GarageOwner.h Customer.h Car.h Motorcycle.h Truck.h Queue.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Clean build files
clean:
	rm -f $(OBJS) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)
