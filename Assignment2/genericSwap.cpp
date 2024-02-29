//
// Created by uttam on 22-01-2024.
//

#include <iostream>
using namespace std;

template <typename T>
void swapElements(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

struct Point {
    int x;
    int y;
};

int main() {

    int intA = 5, intB = 10;
    cout << "Before swap - int: " << intA << ", " << intB << endl;
    swapElements(intA, intB);
     cout << "After swap - int: " << intA << ", " << intB <<  endl;

    short shortA = 2, shortB = 7;
     cout << "Before swap - short: " << shortA << ", " << shortB <<  endl;
    swapElements(shortA, shortB);
     cout << "After swap - short: " << shortA << ", " << shortB <<  endl;

    float floatA = 3.5f, floatB = 8.9f;
     cout << "Before swap - float: " << floatA << ", " << floatB <<  endl;
    swapElements(floatA, floatB);
     cout << "After swap - float: " << floatA << ", " << floatB <<  endl;

    double doubleA = 1.234, doubleB = 5.678;
     cout << "Before swap - double: " << doubleA << ", " << doubleB <<  endl;
    swapElements(doubleA, doubleB);
     cout << "After swap - double: " << doubleA << ", " << doubleB <<  endl;

    Point pointA = {1, 2};
    Point pointB = {3, 4};
     cout << "Before swap - Point: (" << pointA.x << ", " << pointA.y << "), ("
              << pointB.x << ", " << pointB.y << ")" <<  endl;
    swapElements(pointA, pointB);
     cout << "After swap - Point: (" << pointA.x << ", " << pointA.y << "), ("
              << pointB.x << ", " << pointB.y << ")" <<  endl;

    return 0;
}

