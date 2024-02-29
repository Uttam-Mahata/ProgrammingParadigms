#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Student {
private:
    const int studentID; 
     string name;
    int age;
     string department;
    int year;

    static int nextID;

public:
    
    Student() : studentID(nextID++) {}

    
    Student( string name, int age,  string department, int year) : studentID(nextID++) {
        this->name = name;
        this->age = age;
        this->department = department;
        this->year = year;
    }

    Student(const Student& other) : studentID(nextID++) {
        name = other.name;
        age = other.age;
        department = other.department;
        year = other.year;
    }

    Student& operator=(const Student& other) {
        if (this != &other) {
            name = other.name;
            age = other.age;
            department = other.department;
            year = other.year;
        }
        return *this;
    }

    void PrintStudentData() {
         //cout << "ID: " << this->studentID <<  endl;
         cout << "Name: " << this->name <<  endl;
         cout << "Age: " << this->age <<  endl;
         cout << "Department: " << this->department <<  endl;
         cout << "Year: " << this->year <<  endl;
    }

    static void ReadStudentData(Student<T>& student) {
         cin.ignore();
         cout << "Enter Name: ";
         getline(cin, student.name);
         cout << "Enter Age: ";
         cin >> student.age;
         cin.ignore();
         cout << "Enter Department: ";
         cin >> student.department;
         cout << "Enter Year: ";
         cin >> student.year;
    }
};

template<typename T>
int Student<T>::nextID = 1;

int main() {
    int n;
     cout << "Enter the number of students: ";
     cin >> n;

    Student<int> students[n];

    for (int i = 0; i < n; ++i) {
         cout << "\nEnter details for student " << i + 1 <<  endl;
        Student<int>::ReadStudentData(students[i]);
    }

     cout << "\nStudent Information:" <<  endl;
    for (int i = 0; i < n; ++i) {
         cout << "\nDetails of student " << i + 1 <<  endl;
        students[i].PrintStudentData();
    }

    return 0;
}
