#include <bits/stdc++.h>

using namespace std;

class Shape {
    public:
    virtual double area() = 0;
};

class Triangle : public Shape {
    private:
    double base;
    double height;

    public:
    Triangle(double b, double h) : base(b), height(h) {}

    double area() {
        return 0.5 * base * height;
    }
};

class Rectangle : public Shape {
    private:
    double length;
    double breadth;

    public:
    Rectangle(double l, double b) : length(l), breadth(b) {}

    double area() {
        return length * breadth;
    }
};

class Circle : public Shape {
    private:
    double radius;

    public:
    Circle(double r) : radius(r) {}

    double area() {
        return 3.14 * radius * radius;
    }
};

int main() {
    int n;
    cout << "Enter number of shapes: ";
    cin >> n;

    vector<Shape*> shapes;
    for (int i = 0; i < n; i++) {
        int type;
        cout << "Enter type of shape (1 for Triangle, 2 for Rectangle, 3 for Circle): ";
        cin >> type;

        if (type == 1) {
            double base, height;
            cout << "Enter base and height: ";
            cin >> base >> height;
            shapes.push_back(new Triangle(base, height));
        } else if (type == 2) {
            double length, breadth;
            cout << "Enter length and breadth: ";
            cin >> length >> breadth;
            shapes.push_back(new Rectangle(length, breadth));
        } else if (type == 3) {
            double radius;
            cout << "Enter radius: ";
            cin >> radius;
            shapes.push_back(new Circle(radius));
        }
    }

    double totalArea = 0;
    for (int i = 0; i < n; i++) {
        totalArea += shapes[i]->area();
    }

    cout << "Total area: " << totalArea << endl;

    return 0;
}

