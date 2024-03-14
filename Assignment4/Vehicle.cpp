#include <bits/stdc++.h>
using namespace std;

class Vehicle {
    private:
    int price;
    string manufacturer;

    public:
    // Default constructor
    Vehicle() {
        price = 0;
        manufacturer = "";
    }
    // parameterized constructor
    Vehicle(int p, string m) {
        price = p;
        manufacturer = m;
    }

    // Copy constructor
    Vehicle(const Vehicle &v) {
        price = v.price;
        manufacturer = v.manufacturer;
    }

    // Assignment operator
    Vehicle& operator=(const Vehicle &v) {
        price = v.price;
        manufacturer = v.manufacturer;
        return *this;
    }
    // Read Data
    void readData() {
        cout << "Enter price: ";
        cin >> price;
        cout << "Enter manufacturer: ";
        cin >> manufacturer;
    }
    // Display Data
    void displayData() {
        cout << "Price: " << price << endl;
        cout << "Manufacturer: " << manufacturer << endl;
    }
};

class Car : public Vehicle {
    private:
    string color;
    int numberOfSeats;
    string model;

    public:
    // Default constructor
    Car() {
        color = "";
        numberOfSeats = 0;
        model = "";
    }
    // parameterized constructor
    Car(int p, string m, string c, int n, string mod) : Vehicle(p, m) {
        color = c;
        numberOfSeats = n;
        model = mod;
    }

    // Copy constructor
    Car(const Car &c) {
        // Vehicle::price = c.price;
        // Vehicle::manufacturer = c.manufacturer;
        
        color = c.color;
        numberOfSeats = c.numberOfSeats;
        model = c.model;
    }

    // Assignment operator
    Car& operator=(const Car &c) {

        color = c.color;
        numberOfSeats = c.numberOfSeats;
        model = c.model;
        return *this;
    }
    // Read Data
    void readData() {
        Vehicle::readData();
        cout << "Enter color: ";
        cin >> color;
        cout << "Enter number of seats: ";
        cin >> numberOfSeats;
        cout << "Enter model: ";
        cin >> model;
    }
    // Display Data
    void displayData() {
        Vehicle::displayData();
        cout << "Color: " << color << endl;
        cout << "Number of seats: " << numberOfSeats << endl;
        cout << "Model: " << model << endl;
    }

    

};



int main() {
    Car c1;
    cout << "Enter details of car 1: \n";
    c1.readData();
    cout << "-----------------------------\n";
    cout << "Displaying details of car 1: \n";
    c1.displayData();
    cout << "-----------------------------\n";
    cout << "Displaying details of car 2: \n";


    Car c2(1000000, "Toyota", "Red", 4, "Corolla");
    c2.displayData();
    cout << "-----------------------------\n";
    Car c3(c1);
    cout << "Displaying data of car 3 copied from c1 using copy constructor: \n";

    c3.displayData();
    cout << "-----------------------------\n";

    Car c4;
    c4 = c2;
    cout << "Displaying data of car 4 = car 2 using assignment operator: \n";

    c4.displayData();

    Car c5(c1);
    c5.displayData();

    return 0;
}