#include <iostream>
using namespace std;

class Vehicle
{
public:
    Vehicle() 
    {
        cout << "Vehicle::Vehicle" << endl;
    }
    virtual void start() const = 0;
    virtual ~Vehicle() {};
};

class Car : public Vehicle
{
public:
    Car() {};
    void start() const
    {
        cout << "Car starts with a key." << endl;
    }
};

class Motorcycle : public Vehicle
{
public:
    Motorcycle() {};
    void start() const
    {
        cout << "Motorcycle starts with a kick." << endl;
    }
};

class Bicycle : public Vehicle
{
public:
    Bicycle() {};
    void start() const
    {
        cout << "Bicycle starts by pedaling." << endl;
    }
};



int main() {
Vehicle* vehicle1 = new Car();
Vehicle* vehicle2 = new Motorcycle();
Vehicle* vehicle3 = new Bicycle();
vehicle1->start();
vehicle2->start();
vehicle3->start();
delete vehicle1;
delete vehicle2;
delete vehicle3;
}