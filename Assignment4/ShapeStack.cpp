#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual void display() const = 0;
};

class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double area() const override {
        return 0.5 * base * height;
    }

    void display() const override {
        cout << "Triangle: base=" << base << ", height=" << height << endl;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double breadth;

public:
    Rectangle(double l, double b) : length(l), breadth(b) {}

    double area() const override {
        return length * breadth;
    }

    void display() const override {
        cout << "Rectangle: length=" << length << ", breadth=" << breadth << endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14 * radius * radius;
    }

    void display() const override {
        cout << "Circle: radius=" << radius << endl;
    }
};

class ShapeStack {
private:
    vector<unique_ptr<Shape>> stack;

public:
    void push(unique_ptr<Shape> shape) {
        stack.push_back(move(shape));
    }

    void pop() {
        if (!stack.empty()) {
            stack.pop_back();
        }
    }

    void display() const {
        cout << "Shapes in the stack:" << endl;
        for (const auto& shape : stack) {
            shape->display();
        }
    }

    double totalAreaCovered() const {
        double totalArea = 0;
        for (const auto& shape : stack) {
            totalArea += shape->area();
        }
        return totalArea;
    }
};

int main() {
    ShapeStack shapeStack;

    int choice;
    do {
        cout << "\n1. Add a shape\n";
        cout << "2. Display shapes\n";
        cout << "3. Calculate total area covered\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int type;
                cout << "Enter type of shape (1 for Triangle, 2 for Rectangle, 3 for Circle): ";
                cin >> type;

                if (type == 1) {
                    double base, height;
                    cout << "Enter base and height: ";
                    cin >> base >> height;
                    shapeStack.push(make_unique<Triangle>(base, height));
                } else if (type == 2) {
                    double length, breadth;
                    cout << "Enter length and breadth: ";
                    cin >> length >> breadth;
                    shapeStack.push(make_unique<Rectangle>(length, breadth));
                } else if (type == 3) {
                    double radius;
                    cout << "Enter radius: ";
                    cin >> radius;
                    shapeStack.push(make_unique<Circle>(radius));
                }
                break;
            }
            case 2:
                shapeStack.display();
                break;
            case 3:
                cout << "Total area covered: " << shapeStack.totalAreaCovered() << endl;
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
