#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    void inputPerson() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
    }
};

class Employee : public Person {
protected:
    int empID;

public:
    void inputEmployee() {
        inputPerson();
        cout << "Enter Employee ID: ";
        cin >> empID;
    }
};

// Top class
class Manager : public Employee {
    string department;

public:
    void inputManager()
    {
        inputEmployee();
        cout << "Enter Department: ";
        cin >> department;
    }

    void display() {
        cout << "\n--- Details ---\n";
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Employee ID: " << empID << endl;
        cout << "Department: " << department << endl;
    }
};

int main() {
    Manager m;

    m.inputManager();
    m.display();

    return 0;
}
