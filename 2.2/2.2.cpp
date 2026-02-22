#include <iostream>
using namespace std;

class Student
{
private:
    int roll;
    string name;
    float marks1, marks2, marks3;
    float average;

public:


    Student()
    {
        roll = 1;
        name = "feni";
        marks1 = 60;
        marks2 = 70;
        marks3 = 80;
        calculate();
    }

    // Parameterized Constructor
    Student(int r, string n, float m1, float m2, float m3)
    {
        roll = r;
        name = n;
        marks1 = m1;
        marks2 = m2;
        marks3 = m3;
       // average = (marks1 + marks2 + marks3) / 3;
    }
    void calculate()
    {
          average = (marks1 + marks2 + marks3) / 3;
    }

    void display()
    {
        cout << "Roll No: " << roll << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks1 << ", " << marks2 << ", " << marks3 << endl;
        cout << "Average: " << average << endl;
        cout << "--------------------------" << endl;
    }
};

int main()
{
    // Default object
    Student s1;
    s1.display();

    // User input object
    Student s2();

   // s1.display();
    s2.display();

    return 0;
}
