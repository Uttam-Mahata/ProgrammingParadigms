import java.util.Scanner;

public class StudentRecord {
    String name;
    int age;
    String department;
    int year;

    public void readData(String name, int age, String department, int year) {
        this.name = name;
        this.age = age;
        this.department = department;
        this.year = year;
    }

    public void printData() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Department: " + department);
        System.out.println("Year: " + year);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of students: ");
        int numberOfStudents = scanner.nextInt();
        scanner.nextLine();
        StudentRecord[] students = new StudentRecord[numberOfStudents];

        for (int i = 0; i < numberOfStudents; i++) {
            StudentRecord student = new StudentRecord();
            System.out.println("\nEnter details for student " + (i + 1) + ":");
            System.out.print("Name: ");
            String name = scanner.nextLine();
            System.out.print("Age: ");
            int age = scanner.nextInt();
            scanner.nextLine();
            System.out.print("Department: ");
            String department = scanner.nextLine();
            System.out.print("Year: ");
            int year = scanner.nextInt();
            scanner.nextLine();
            student.readData(name, age, department, year);
            students[i] = student;
        }

        System.out.println("\nStudent Details:");
        for (int i = 0; i < numberOfStudents; i++) {
            System.out.println("\nDetails of student " + (i + 1) + ":");
            students[i].printData();
        }

        scanner.close();
    }
}
