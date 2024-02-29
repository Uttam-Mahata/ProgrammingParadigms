#include<iostream>
#include <string>
#include <fstream>
using namespace std;

const int MAX_STUDENTS = 100;
struct StudentInfo {
    string name;
    int age;
    string department;
    string year;

};

void ReadStudentData(StudentInfo& student) {
    cout << "Enter student name: ";
    getline(cin, student.name);
    cout << "Enter student age: ";
    cin >> student.age;
    cin.ignore();
    cout << "Enter student department: ";
    getline(cin, student.department);
    cout << "Enter student year: ";
    getline(cin, student.year);
}

void PrintStudentData(const StudentInfo& student) {
    cout << "Student Name: " << student.name << endl;
    cout << "Student Age: " << student.age << endl;
    cout << "Student Department: " << student.department << endl;
    cout << "Student Year: " << student.year << endl;
}

void saveStudentData(const StudentInfo student[], int numStudents) {
    ofstream outfile("student_data.csv");

    if (outfile.is_open()) {
        outfile << "Name,\tAge,\tDepartment,\tYear\n";
        for (int i = 0; i < numStudents; ++i) {
            outfile << student[i].name << ",\t" << student[i].age << ",\t" << student[i].department << ",\t"
            << student[i].year<< endl;
        }
        outfile.close();
        cout << "Student data saved to file." << endl;
    } else {
        cout << "Unable to open file." << endl;
    }
}



int main() {
    StudentInfo students[MAX_STUDENTS];
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;
    cin.ignore();
    for (int i = 0; i < numStudents; i++) {
        cout << "Enter information for student " << i + 1 << ":" << endl;
        ReadStudentData(students[i]);

    }
    cout << endl << "Student Information:" << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << "Student " << i + 1 << ":" << endl;
        PrintStudentData(students[i]);
        cout << endl;
    }
    saveStudentData(students, numStudents);



    return 0;
}
