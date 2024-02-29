#include <iostream>
#include <string>
using namespace std;

class Student {
private:
string Name;
int Age;
string Department;
string Year;

public:
/*void SetStudentData(string name, int age, string department, string year) {
Name = name;
Age = age;
Department = department;
Year = year;
}*/
void ReadStudentData() {
cin.ignore();
cout << "Enter Student Name:";
getline(cin, Name);
cout << "Enter Student Age: ";
cin >> Age;
cin.ignore();
cout << "Enter Student Department: ";
getline(cin, Department);
cout << "Enter Student Year: ";
getline(cin, Year);

//}
}
void PrintStudentData() {
cout << "Name: " << Name << endl;
cout << "Age: " << Age << endl;
cout << "Department: " << Department << endl;
cout << "Year : " << Year << endl;
}
};

int main() {
int N; 
cout << "Enter the number of students data you want to store: ";
cin >> N;

Student s[N];

for(int i = 1; i <= N; i++) {
s[i].ReadStudentData();
}
for(int i = 1; i <= N; i++) {
cout << "Student " << i << ":"<<endl;
s[i].PrintStudentData();
}
return 0;
}
