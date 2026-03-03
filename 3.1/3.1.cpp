#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    double basicSalary;
    double bonus;

public:

    Employee(string n, double b) {
        name = n;
        basicSalary = b;
        bonus = 2000;
    }

    Employee(string n, double b, double bon) {
        name = n;
        basicSalary = b;
        bonus = bon;
    }


    inline double calculateTotalSalary() {
        return basicSalary + bonus;
    }


    void display() {
        cout << "\nEmployee Name: " << name;
        cout << "\nBasic Salary: " << basicSalary;
        cout << "\nBonus: " << bonus;
        cout << "\nTotal Salary: " << calculateTotalSalary();
        cout << "\n=================================================";

    }
};


int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;


    Employee* emp[n];

    for (int i = 0; i < n; i++) {
        string name;
        double basic, bonus;
        int choice;

        cout << "\nEmployee " << i + 1 << endl;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter basic salary: ";
        cin >> basic;

        cout << "Use default bonus? (1-Yes / 0-No): ";
        cin >> choice;

        if (choice == 1) {
            emp[i] = new Employee(name, basic);
        } else {
            cout << "Enter custom bonus: ";
            cin >> bonus;
            emp[i] = new Employee(name, basic, bonus);
        }
    }


    cout << "\n=========================================Employee Details==========================================\n";
    for (int i = 0; i < n; i++) {
        emp[i]->display();
    }


    for (int i = 0; i < n; i++) {
        delete emp[i];
    }

    return 0;
}
