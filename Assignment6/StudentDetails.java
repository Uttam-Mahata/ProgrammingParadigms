import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

class StudentInfo {
    String name;
    int age;
    String department;
    String year;
}

public class StudentDetails {
    private static final int MAX_STUDENTS = 100;

    public static void readStudentData(StudentInfo student, Scanner scanner) {
        System.out.print("Enter student name: ");
        student.name = scanner.nextLine();
        System.out.print("Enter student age: ");
        student.age = scanner.nextInt();
        scanner.nextLine(); // Consume newline character
        System.out.print("Enter student department: ");
        student.department = scanner.nextLine();
        System.out.print("Enter student year: ");
        student.year = scanner.nextLine();
    }

    public static void printStudentData(StudentInfo student) {
        System.out.println("Student Name: " + student.name);
        System.out.println("Student Age: " + student.age);
        System.out.println("Student Department: " + student.department);
        System.out.println("Student Year: " + student.year);
    }

    public static void saveStudentData(StudentInfo[] students, int numStudents) {
        try {
            PrintWriter outFile = new PrintWriter(new FileWriter("student_data.csv"));
            outFile.println("Name,\tAge,\tDepartment,\tYear");
            for (int i = 0; i < numStudents; ++i) {
                outFile.println(students[i].name + ",\t" + students[i].age + ",\t" +
                        students[i].department + ",\t" + students[i].year);
            }
            outFile.close();
            System.out.println("Student data saved to file.");
        } catch (IOException e) {
            System.out.println("Unable to open file.");
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        StudentInfo[] students = new StudentInfo[MAX_STUDENTS];
        System.out.print("Enter the number of students: ");
        int numStudents = scanner.nextInt();
        scanner.nextLine(); // Consume newline character

        for (int i = 0; i < numStudents; i++) {
            System.out.println("Enter information for student " + (i + 1) + ":");
            students[i] = new StudentInfo();
            readStudentData(students[i], scanner);
        }

        System.out.println("\nStudent Information:");
        for (int i = 0; i < numStudents; i++) {
            System.out.println("Student " + (i + 1) + ":");
            printStudentData(students[i]);
            System.out.println();
        }

        saveStudentData(students, numStudents);

        scanner.close();
    }
}
