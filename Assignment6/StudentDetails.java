import java.util.Scanner;

class Student {
    private String name;
    private int rollNumber;

    public Student(String name, int rollNumber) {
        this.name = name;
        this.rollNumber = rollNumber;
    }

    public String getName() {
        return name;
    }

    public int getRollNumber() {
        return rollNumber;
    }
}

public class StudentDetails {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of students: ");
        int numberOfStudents = scanner.nextInt();

        scanner.nextLine();
        Student[] students = new Student[numberOfStudents];

        for (int i = 0; i < numberOfStudents; i++) {
            System.out.println("Enter details for student " + (i + 1) + ":");
            System.out.print("Name: ");
            String name = scanner.nextLine();
            System.out.print("Roll Number: ");
            int rollNumber = scanner.nextInt();

            students[i] = new Student(name, rollNumber);

            scanner.nextLine();
        }

        System.out.println("\nStudent Details:");
        for (int i = 0; i < numberOfStudents; i++) {
            System.out.println("Student " + (i + 1) + ":");
            System.out.println("Name: " + students[i].getName());
            System.out.println("Roll Number: " + students[i].getRollNumber());
            System.out.println();
        }

        scanner.close();
    }
}
