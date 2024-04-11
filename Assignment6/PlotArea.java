import java.util.ArrayList;
import java.util.Scanner;

abstract class Shape {
    public abstract double area();
}

class Triangle extends Shape {
    private double base;
    private double height;

    public Triangle(double b, double h) {
        base = b;
        height = h;
    }

    public double area() {
        return 0.5 * base * height;
    }
}

class Rectangle extends Shape {
    private double length;
    private double breadth;

    public Rectangle(double l, double b) {
        length = l;
        breadth = b;
    }

    public double area() {
        return length * breadth;
    }
}

class Circle extends Shape {
    private double radius;

    public Circle(double r) {
        radius = r;
    }

    public double area() {
        return Math.PI * radius * radius;
    }
}

public class PlotArea {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter number of shapes: ");
        int n = scanner.nextInt();

        ArrayList<Shape> shapes = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            System.out.print("Enter type of shape (1 for Triangle, 2 for Rectangle, 3 for Circle): ");
            int type = scanner.nextInt();

            if (type == 1) {
                System.out.print("Enter base and height: ");
                double base = scanner.nextDouble();
                double height = scanner.nextDouble();
                shapes.add(new Triangle(base, height));
            } else if (type == 2) {
                System.out.print("Enter length and breadth: ");
                double length = scanner.nextDouble();
                double breadth = scanner.nextDouble();
                shapes.add(new Rectangle(length, breadth));
            } else if (type == 3) {
                System.out.print("Enter radius: ");
                double radius = scanner.nextDouble();
                shapes.add(new Circle(radius));
            }
        }

        double totalArea = 0;
        for (int i = 0; i < n; i++) {
            totalArea += shapes.get(i).area();
        }

        System.out.println("Total area: " + totalArea);

        scanner.close();
    }
}
