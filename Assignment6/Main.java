class Person {
    private String name;
    private int age;
    private String gender;

    public Person(String name, int age, String gender) {
        this.name = name;
        this.age = age;
        this.gender = gender;
    }

    public void display() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Gender: " + gender);
    }
}

class Student extends Person {
    private String dept;
    private int year;

    public Student(String name, int age, String gender, String dept, int year) {
        super(name, age, gender);
        this.dept = dept;
        this.year = year;
    }

    @Override
    public void display() {
        super.display();
        System.out.println("Dept: " + dept);
        System.out.println("Year: " + year);
    }
}

class Professor extends Person {
    private String dept;
    private int courseLoad;
    private double salary;

    public Professor(String name, int age, String gender, String dept, int courseLoad, double salary) {
        super(name, age, gender);
        this.dept = dept;
        this.courseLoad = courseLoad;
        this.salary = salary;
    }

    @Override
    public void display() {
        super.display();
        System.out.println("Dept: " + dept);
        System.out.println("Course Load: " + courseLoad);
        System.out.println("Salary: $" + salary);
    }
}

public class Main {

    public static void main(String[] args) {
        Student student1 = new Student("John", 20, "Male", "CS", 3);
        Professor professor1 = new Professor("Alice", 40, "Female", "CS", 4, 100000.00);

        System.out.println("Student Details:");
        student1.display();

        System.out.println("\nProfessor Details:");
        professor1.display();
    }
}
