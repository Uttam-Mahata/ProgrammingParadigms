#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;
    string gender;

public:
// default constructor

    Person() {
        name = "";
        age = 0;
        gender = "";
    }

    Person(string name, int age, string gender) : name(name), age(age), gender(gender) {}

    void read_profile() {
        cout << "Enter name: ";
        cin >> name;
       
        
        cout << "Enter age: ";
        
        cin >> age;
      
        cout << "Enter gender: ";
        cin >> gender;
    }

    void display_profile() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
    }
};

class Student : public Person {
    private:
    string dept;
    int year;

public:
// Default constructor
    Student() {
        dept = "";
        year = 0;
    }
    Student(string name, int age, string gender, string dept, int year) : Person(name, age, gender), dept(dept), year(year) {}

    void read_profile() {
        Person::read_profile();
        cout << "Enter Dept: ";
        cin >> dept;
        cout << "Enter Year: ";
        cin >> year;
    }


    void display_profile() {
        Person::display_profile();
        cout << "Department: " << dept << endl;
        cout << "Year: " << year << endl;
    }
};

class Clerk : public Person {
    string workload;
    int salary;

public:
// default constructor
    Clerk() {
        workload = "";
        salary = 0;
    }
    Clerk(string name, int age, string gender, string workload, int salary) : Person(name, age, gender), workload(workload), salary(salary) {}

    void read_profile() {
        Person::read_profile();
        cout << "Enter Workload: ";
        cin >> workload;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    void display_profile() {
        Person::display_profile();
        cout << "Workload: " << workload << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Professor : public Person {
    string dept;
    string courseLoad;
    int salary;

public:
// default constructor
    Professor() {
        dept = "";
        courseLoad = "";
        salary = 0;
    }
    Professor(string name, int age, string gender, string dept, string courseLoad, int salary) : Person(name, age, gender), dept(dept), courseLoad(courseLoad), salary(salary) {}

    void read_profile() {
        Person::read_profile();
        cout << "Enter Dept: ";
        cin >> dept;
        cout << "Enter Course Load: ";
        cin >> courseLoad;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    void display_profile() {
        Person::display_profile();
        cout << "Department: " << dept << endl;
        cout << "Course Load: " << courseLoad << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {

    Student s1;
    s1.read_profile();
    s1.display_profile();
    
    Student student("Uttam", 19, "Male", "Computer Science", 2);
    Clerk clerk("Alice", 35, "Male", "Medium", 40000);
    Professor professor("Aswini Kumar", 45, "Male", "Mathematics", "Heavy", 80000);

    cout << "Student Profile:" << endl;
    student.display_profile();
    cout << "\nClerk Profile:" << endl;
    clerk.display_profile();
    cout << "\nProfessor Profile:" << endl;
    professor.display_profile();

    return 0;
}
